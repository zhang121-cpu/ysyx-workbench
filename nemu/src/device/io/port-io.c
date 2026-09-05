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

#define PORT_IO_SPACE_MAX 65535

#define NR_MAP 16
static IOMap maps[NR_MAP] = {};
static int nr_map = 0;

/* device interface */
// 输入: name - 映射名称; addr - 端口 I/O 起始地址; space - 设备存储空间首地址; len - 映射长度; callback - 访问回调(可为 NULL)
// 输出: 无
// 作用: 注册一个端口 I/O 映射, 将端口区间 [addr, addr+len-1] 关联到设备的存储空间
void add_pio_map(const char *name, ioaddr_t addr, void *space, uint32_t len, io_callback_t callback) {
  assert(nr_map < NR_MAP);
  assert(addr + len <= PORT_IO_SPACE_MAX);
  maps[nr_map] = (IOMap){ .name = name, .low = addr, .high = addr + len - 1,
    .space = space, .callback = callback };
  Log("Add port-io map '%s' at [" FMT_PADDR ", " FMT_PADDR "]",
      maps[nr_map].name, maps[nr_map].low, maps[nr_map].high);

  nr_map ++;
}

/* CPU interface */
// 输入: addr - 读取的端口号; len - 读取长度(字节)
// 输出: 返回从对应设备映射空间中读出的数据
// 作用: 查找 addr 所属的端口 I/O 映射, 并从其映射空间中读取 len 字节数据
uint32_t pio_read(ioaddr_t addr, int len) {
  assert(addr + len - 1 < PORT_IO_SPACE_MAX);
  int mapid = find_mapid_by_addr(maps, nr_map, addr);
  assert(mapid != -1);
  return map_read(addr, len, &maps[mapid]);
}

// 输入: addr - 写入的端口号; len - 写入长度(字节); data - 待写入数据
// 输出: 无
// 作用: 查找 addr 所属的端口 I/O 映射, 并向其映射空间写入 len 字节数据
void pio_write(ioaddr_t addr, int len, uint32_t data) {
  assert(addr + len - 1 < PORT_IO_SPACE_MAX);
  int mapid = find_mapid_by_addr(maps, nr_map, addr);
  assert(mapid != -1);
  map_write(addr, len, data, &maps[mapid]);
}
