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

#ifndef __DEVICE_MAP_H__
#define __DEVICE_MAP_H__

#include <cpu/difftest.h>

// 设备 I/O 回调函数类型: 参数依次为映射内偏移(offset)、访问长度(len)、是否写操作(is_write)
typedef void(*io_callback_t)(uint32_t, int, bool);

// 输入: size - 需要分配的字节数
// 输出: 返回分配得到的空间首地址(页对齐)
// 作用: 从全局 IO 空间中按页对齐分配 size 字节的连续内存
uint8_t* new_space(int size);

// I/O 映射结构体, 用于描述一个设备的 I/O 映射区间
// 输入: name - 映射名称; low - 映射起始物理地址; high - 映射结束物理地址; space - 设备存储空间首地址; callback - 访问回调函数
//low与high都是cpu视线中的存储单元，但正在访存这些存储单元时使用的时space指向的存储单元
typedef struct {
  const char *name;
  // we treat ioaddr_t as paddr_t here
  paddr_t low;
  paddr_t high;
  void *space;
  io_callback_t callback;
} IOMap;

// 输入: map - I/O 映射结构指针; addr - 待判断的物理地址
// 输出: true 表示 addr 位于映射区间内, false 表示不在
// 作用: 判断物理地址 addr 是否落在 map 覆盖的地址区间内
static inline bool map_inside(IOMap *map, paddr_t addr) {
  return (addr >= map->low && addr <= map->high);
}

// 输入: maps - 映射结构数组首地址; size - 数组元素个数; addr - 待查找的物理地址
// 输出: 返回 addr 所在映射在数组中的下标, 未找到返回 -1
// 作用: 遍历映射数组找到 addr 所属的映射, 同时告知 difftest 跳过本次对比
static inline int find_mapid_by_addr(IOMap *maps, int size, paddr_t addr) {
  int i;
  for (i = 0; i < size; i ++) {
    if (map_inside(maps + i, addr)) {
      difftest_skip_ref();
      return i;
    }
  }
  return -1;
}

// 输入: name - 映射名称; addr - 端口 I/O 起始地址; space - 设备存储空间首地址; len - 映射长度; callback - 访问回调(可为 NULL)
// 输出: 无
// 作用: 注册一个端口 I/O 映射, 将地址区间 [addr, addr+len) 关联到设备的存储空间
void add_pio_map(const char *name, ioaddr_t addr,
        void *space, uint32_t len, io_callback_t callback);

// 输入: name - 映射名称; addr - MMIO 起始物理地址; space - 设备存储空间首地址; len - 映射长度; callback - 访问回调(可为 NULL)
// 输出: 无
// 作用: 注册一个 MMIO 映射, 将地址区间 [addr, addr+len) 关联到设备的存储空间
void add_mmio_map(const char *name, paddr_t addr,
        void *space, uint32_t len, io_callback_t callback);

// 输入: addr - 读取的物理地址; len - 读取长度(1~8 字节); map - 对应的 I/O 映射
// 输出: 返回从映射空间中读出的数据
// 作用: 从 map 指定的设备映射空间中读取 len 字节数据
word_t map_read(paddr_t addr, int len, IOMap *map);

// 输入: addr - 写入的物理地址; len - 写入长度(1~8 字节); data - 待写入数据; map - 对应的 I/O 映射
// 输出: 无
// 作用: 向 map 指定的设备映射空间写入 len 字节数据
void map_write(paddr_t addr, int len, word_t data, IOMap *map);

#endif
