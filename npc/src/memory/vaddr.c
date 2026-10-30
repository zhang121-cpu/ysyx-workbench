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
#include <memory/paddr.h>

#ifdef CONFIG_MTRACE
extern uint64_t g_nr_guest_inst;
bool mtrace_enable() {
    return (g_nr_guest_inst >= CONFIG_TRACE_START) &&
          (g_nr_guest_inst <= CONFIG_TRACE_END);
}
#endif

word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  word_t data = paddr_read(addr, len);
  #ifdef CONFIG_MTRACE
    if (mtrace_enable() && npc_in_clk0_eval()) {     //不仅要在mtrace_enable()，还要在npc_in_clk0_eval()，保证只记录一次
      log_write("[mtrace] READ  addr=0x%08x, len=%d, data=0x%08x\n", 
          addr, len, data);
    }
  #endif
  return data;
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_write(addr, len, data);
  #ifdef CONFIG_MTRACE
    if (mtrace_enable()) {
        log_write("[mtrace] WRITE addr=0x%08x, len=%d, data=0x%08x\n", 
            addr, len, data);
    }
  #endif
}
