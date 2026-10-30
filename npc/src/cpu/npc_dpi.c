/* DPI-C 访存/设备后端。pmem 本体在 src/memory/paddr.c —— 全系统只有一份内存，
 * sdb 的 x 命令、DiffTest 的 memcpy、RTL 的取指/访存读写同一块。
 *
 * 【移植提醒】设备开关用 CONFIG_NPC_DEVICE（npc 自己的总开关），
 *   不用 nemu 的 CONFIG_DEVICE（那个绑定了未拷贝的 device/*.c 框架）。
 *   dtrace 触发点在此（对齐 nemu 在 map.c 的角色）。 
 *   关于后续的vga与键盘外设实现，我的想法是输入数据的时候还是在这里输入，
 * 显示的时机放到原来device_update()里，既平衡了硬链接与nemu对齐，
 * 又满足了多个数据一起显示的需求 */
#include <common.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>
#include <cpu/cpu.h>
#include <cpu/difftest.h>
#include <isa.h>
#include <stdio.h>
#include <npc_api.h> 

#ifdef CONFIG_NPC_DEVICE
  #ifdef CONFIG_HAS_SERIAL
  #define SERIAL_MMIO  ((uint32_t)CONFIG_SERIAL_MMIO)   
  #endif
  #ifdef CONFIG_HAS_TIMER
  #define RTC_MMIO     ((uint32_t)CONFIG_RTC_MMIO)      
  static uint64_t rtc_latch = 0;    //用于时间快照
  #endif
#endif

uint32_t npc_mem_ifetch(uint32_t addr, int len) {
  return vaddr_ifetch(addr, len); //读写越界问题在函数内处理
}

uint32_t npc_mem_read(uint32_t addr, int len) {
#ifdef CONFIG_NPC_DEVICE
  #ifdef CONFIG_HAS_TIMER
  if (addr == RTC_MMIO + 4) {              //与AM的RTC_ADDR对应，先读取高32位，后读取低32位，保证同一快照
    rtc_latch = get_time();
    if (npc_in_clk0_eval()) {  //保证只记录一次
      IFDEF(CONFIG_DTRACE, dtrace_log("0x%08x:read  rtc_hi , addr = 0x%08x, len = %d, data = 0x%08x\n", cpu.pc, addr, len, (uint32_t)(rtc_latch >> 32)));
    }
    return (uint32_t)(rtc_latch >> 32);
  }
  if (addr == RTC_MMIO) {    
    if (npc_in_clk0_eval()) {  //保证只记录一次
      IFDEF(CONFIG_DTRACE, dtrace_log("0x%08x:read  rtc_lo , addr = 0x%08x, len = %d, data = 0x%08x\n", cpu.pc, addr, len, (uint32_t)rtc_latch ));
    }             
    return (uint32_t)rtc_latch;
  }
  #endif
#endif
  return vaddr_read(addr, len); //读写越界问题在函数内处理
}

void npc_mem_write(uint32_t addr, uint32_t data, int len) {
#ifdef CONFIG_NPC_DEVICE
  #ifdef CONFIG_HAS_SERIAL
  if (addr == SERIAL_MMIO) {                
    putchar(data);
    IFDEF(CONFIG_DTRACE, dtrace_log("0x%08x:write serial, addr = 0x%08x, len = %d, data = 0x%08x\n", cpu.pc, addr, len, data));
    return;
  }
  #endif
#endif
  vaddr_write(addr, len, data);  //读写越界问题在函数内处理
}


/* ebreak：对齐 nemu 的 set_nemu_state（hostcall.c） */
void npc_trap(uint32_t pc, uint32_t a0) {
  set_nemu_state(NEMU_END, pc, a0);    //在set_nemu_state函数中进行
}