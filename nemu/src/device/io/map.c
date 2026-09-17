/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (32 * 1024 * 1024)

void dtrace_log(const char *fmt, ...);

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

// 输入: size - 需要分配的字节数
// 输出: 返回分配得到的空间首地址(页对齐)
// 作用: 从全局 IO 空间中按页对齐分配 size 字节, 并断言不超出 IO 空间上限
uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

// 输入: map - I/O 映射结构指针(可为 NULL); addr - 待查询的物理地址
// 输出: 无
// 作用: 检查物理地址 addr 是否越界, 越界则触发 Assert 并打印错误信息
static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

// 输入: c - 设备回调函数; offset - 映射内偏移地址; len - 访问长度; is_write - 是否为写操作
// 输出: 无
// 作用: 若回调函数不为 NULL 则调用它, 通知设备发生了一次 I/O 访问
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

// 输入: 无
// 输出: 无
// 作用: 初始化全局 IO 空间, 分配 IO_SPACE_MAX 字节供后续设备映射使用
void init_map() {
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

// 输入: addr - 读取的物理地址; len - 读取长度(1~8 字节); map - 对应的 I/O 映射
// 输出: 返回从映射空间中读出的数据
// 作用: 检查地址越界后, 先调用回调让设备准备数据, 再从映射空间读取 len 字节
word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read(map->space + offset, len);
  #ifdef CONFIG_DTRACE
    dtrace_log("0x%08x:read  %-12s, addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n",
        cpu.pc, map->name,  addr, len, ret);
  #endif
  return ret;
}

// 输入: addr - 写入的物理地址; len - 写入长度(1~8 字节); data - 待写入数据; map - 对应的 I/O 映射
// 输出: 无
// 作用: 检查地址越界后, 将 data 写入映射空间, 再调用回调通知设备更新状态
void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write(map->space + offset, len, data);
  #ifdef CONFIG_DTRACE
    dtrace_log("0x%08x:write %-12s, addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n",
        cpu.pc, map->name, addr, len, data);
  #endif
  invoke_callback(map->callback, offset, len, true);
}
