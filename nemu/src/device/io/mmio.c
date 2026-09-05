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

#include <device/map.h>
#include <memory/paddr.h>

#define NR_MAP 16

static IOMap maps[NR_MAP] = {};
static int nr_map = 0;

// 输入: addr - 待查找的物理地址
// 输出: 返回 addr 所属的 I/O 映射指针, 未找到返回 NULL
// 作用: 在 MMIO 映射数组中查找地址 addr 所属的映射
static IOMap* fetch_mmio_map(paddr_t addr) {
  int mapid = find_mapid_by_addr(maps, nr_map, addr);
  return (mapid == -1 ? NULL : &maps[mapid]);
}

// 输入: name1/l1/r1 - 第一个映射的名称和区间; name2/l2/r2 - 第二个映射的名称和区间
// 输出: 无(直接 panic 终止模拟器)
// 作用: 打印两个映射区间的重叠信息并终止运行, 用于报错
static void report_mmio_overlap(const char *name1, paddr_t l1, paddr_t r1,
    const char *name2, paddr_t l2, paddr_t r2) {
  panic("MMIO region %s@[" FMT_PADDR ", " FMT_PADDR "] is overlapped "
               "with %s@[" FMT_PADDR ", " FMT_PADDR "]", name1, l1, r1, name2, l2, r2);
}

/* device interface */
// 输入: name - 映射名称; addr - MMIO 起始物理地址; space - 设备存储空间首地址; len - 映射长度; callback - 访问回调(可为 NULL)
// 输出: 无
// 作用: 注册一个 MMIO 映射, 将物理地址区间 [addr, addr+len-1] 关联到设备的存储空间; 注册前检查是否与 pmem 或其他映射重叠
void add_mmio_map(const char *name, paddr_t addr, void *space, uint32_t len, io_callback_t callback) {
  assert(nr_map < NR_MAP);
  paddr_t left = addr, right = addr + len - 1;
  //防止mmio映射区间与pmem重叠
  if (in_pmem(left) || in_pmem(right)) {
    report_mmio_overlap(name, left, right, "pmem", PMEM_LEFT, PMEM_RIGHT);
  }     
  //防止mmio映射区间与其他mmio映射区间重叠
  for (int i = 0; i < nr_map; i++) {
    if (left <= maps[i].high && right >= maps[i].low) {
      report_mmio_overlap(name, left, right, maps[i].name, maps[i].low, maps[i].high);
    }
  }

  maps[nr_map] = (IOMap){ .name = name, .low = addr, .high = addr + len - 1,
    .space = space, .callback = callback };
  Log("Add mmio map '%s' at [" FMT_PADDR ", " FMT_PADDR "]",
      maps[nr_map].name, maps[nr_map].low, maps[nr_map].high);

  nr_map ++;
}

/* bus interface */
// 输入: addr - 读取的物理地址; len - 读取长度(1~8 字节)
// 输出: 返回从对应 MMIO 映射空间中读出的数据
// 作用: 查找 addr 所属的 MMIO 映射, 并从其映射空间中读取 len 字节数据
word_t mmio_read(paddr_t addr, int len) {
  return map_read(addr, len, fetch_mmio_map(addr));
}

// 输入: addr - 写入的物理地址; len - 写入长度(1~8 字节); data - 待写入数据
// 输出: 无
// 作用: 查找 addr 所属的 MMIO 映射, 并向其映射空间写入 len 字节数据
void mmio_write(paddr_t addr, int len, word_t data) {
  map_write(addr, len, data, fetch_mmio_map(addr));
}
