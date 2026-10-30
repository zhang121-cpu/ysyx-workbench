#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <npc_api.h>

#define MAX_INST_TO_PRINT 10

//为输出最近的16条指令设置结构体
#ifdef CONFIG_ITRACE
#define IRINGBUF_SIZE 16 
typedef struct {
  uint32_t pc;
  uint32_t inst;
  char disasm[128];  //存放反汇编后的指令字符串
} ItraceStruct;

ItraceStruct iringbuf[IRINGBUF_SIZE];
int iringbuf_index = 0;
#endif

//打印结构体内容
#ifdef CONFIG_ITRACE
void iringbuf_display() {
    printf("\n---- iringbuf (last %d instructions) ----\n", IRINGBUF_SIZE);

    int i = 0;
    for (i = 0; i < IRINGBUF_SIZE; i++) {  
        if (i == ((iringbuf_index == 0 )?(IRINGBUF_SIZE-1):(iringbuf_index-1))){
            printf("--> ");  // 标记出错指令
        } else {
            printf("    ");
        }
        printf("0x%08x: %08x\t%s\n", iringbuf[i].pc, iringbuf[i].inst, iringbuf[i].disasm);
    }
    
    printf("----------------------------------------\n");
}
#endif

/* DUT 寄存器影子：由 DPI 事件维护。nemu 拷来的代码全部读它，故零修改。 */
CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

int wp_check();

/* ============ DPI 事件处理（由 vsrc 在时钟上升沿调用） ============ */

static Decode s_commit;
static bool commit_valid = false;

/* GPR 写回事件（vsrc/GPR.v）。x0 恒 0 在此保证。 */
void npc_sync_gpr(uint32_t idx, uint32_t val) {
  if (idx != 0) cpu.gpr[idx] = val;
}

#ifdef CONFIG_FTRACE
void ftrace_call(uint32_t pc, uint32_t target);
void ftrace_ret(uint32_t pc);
static void ftrace_detect(uint32_t pc, uint32_t inst, uint32_t dnpc) {
  uint32_t opcode = inst & 0x7f;
  uint32_t rd     = (inst >> 7) & 0x1f;
  uint32_t rs1    = (inst >> 15) & 0x1f;
  if (opcode == 0x6f) {                      /* jal */
    if (rd != 0) ftrace_call(pc, dnpc);      /* rd!=x0 才是调用（对齐 nemu） */
  } else if (opcode == 0x67) {               /* jalr */
    if (rd != 0) ftrace_call(pc, dnpc);      /* rd!=x0 才是调用 */
    else if (rd == 0 && rs1 == 1) ftrace_ret(pc);  /* rd==x0 且 rs1==ra 才是返回（对齐 nemu） */
  }
}
#endif

/* 指令提交事件（vsrc/top.v）：RTL 中一条指令执行完毕*/
void npc_commit_inst(uint32_t pc, uint32_t inst, uint32_t dnpc) {
  s_commit.pc   = pc;
  s_commit.snpc = pc + MUXDEF(CONFIG_ISA_x86, 8, 4);
  s_commit.dnpc = dnpc;
  s_commit.isa.inst = inst;
  cpu.pc = dnpc;
  commit_valid = true;              
  IFDEF(CONFIG_FTRACE, ftrace_detect(pc, inst, dnpc));
}

/* ============ 以下与 nemu 的 cpu-exec.c 相同，仅 exec_once 内部不同 ============ */

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

#ifdef CONFIG_WATCHPOINT
  int symbol = wp_check();
  if (symbol) {
    if (nemu_state.state != NEMU_END)
      nemu_state.state = NEMU_STOP;
  }
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
  commit_valid = false;
  while (!commit_valid) {  //流水线下单指令多周期起作用
    npc_single_cycle();
  #ifdef CONFIG_WAVE_RECORD
    npc_wave_record();
  #endif
  }
  *s = s_commit;

#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;    /* 从 snpc-pc 算指令长度（恢复 nemu 原版写法，扩展性） */
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {      /* x86：正序 */
#else
  for (i = ilen - 1; i >= 0; i --) { /* riscv：倒序 */
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);    /* x86 最长 8 字节，riscv 4 */
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);

  //将指令存入iringbuf中
  iringbuf[iringbuf_index].pc = s->pc;
  iringbuf[iringbuf_index].inst = s->isa.inst;
  disassemble(iringbuf[iringbuf_index].disasm, sizeof(iringbuf[iringbuf_index].disasm),
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
  iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (; n > 0; n--) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst++;               //一个用于记录客户指令的计数器
    trace_and_difftest(&s, cpu.pc);
  #ifdef CONFIG_MAX_SIM_CYCLES_ENABLE    //周期数达到上限时自动结束模拟
    if (g_nr_guest_inst > CONFIG_MAX_SIM_CYCLES){
      Log("total cycles has reached the limit");
      nemu_state.state = NEMU_QUIT;
    }
  #endif
    if (nemu_state.state != NEMU_RUNNING) break;
  }
}

static void statistic() {
  setlocale(LC_NUMERIC, "");
#define NUMBERIC_FMT "%'" PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
#ifdef CONFIG_ITRACE
  iringbuf_display();
#endif
  statistic();
}

void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_ABORT:
#ifdef CONFIG_ITRACE
      iringbuf_display();
#endif
      Log("npc: %s at pc = " FMT_WORD, ANSI_FMT("ABORT", ANSI_FG_RED), nemu_state.halt_pc);
      statistic();
      break;

    case NEMU_END:
      if (nemu_state.halt_ret != 0) {
#ifdef CONFIG_ITRACE
        iringbuf_display();
#endif
      }
      Log("npc: %s at pc = " FMT_WORD,
          (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)), 
            nemu_state.halt_pc);
      statistic();
      break;

    case NEMU_QUIT: statistic();
  }
}