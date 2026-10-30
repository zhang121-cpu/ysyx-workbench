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
#include <cpu/cpu.h>
#include <memory/vaddr.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}


static int cmd_help(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args) ;
static int cmd_w(char *args);
static int cmd_d(char *args);
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Execute N instrution ", cmd_si },
  { "info", "Print register state or watchpoint information", cmd_info },
  { "x", "Scan memory", cmd_x },
  {"p", "Evaluate expression", cmd_p},
  {"w", "Set watchpoint", cmd_w},
  {"d", "Delete watchpoint", cmd_d},


  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(args, " ");    //输入的第一个参数后还有其他的参数的话，这里args会指向这些参数的第一个字符，arg是args的第一个参数
  int i;                                                      //如果没有后续参数，args被赋值NULL，arg在上个strtok下也被赋值NULL
                                                                    //实质上相当于args永远是指向输入的第二个参数的指针，arg是输入的第二个参数
  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

static int cmd_si(char *args) {
  /* extract the first argument */
  char *num = strtok(args, " ");

  if (num == NULL) {
    /* no argument given */
    cpu_exec(1);
    }
  else {
    cpu_exec(atoi(num));
  }
  return 0;
}

static int cmd_info(char *args) {
  /* extract the first argument */
  char *arg = strtok(args, " ");

  if (arg == NULL) {
    printf("Please specify the type of information to display: "
                      "'r' for registers, 'w' for watchpoints.\n");
    return 0;
  }

  if (strcmp(arg, "r") == 0) {
    isa_reg_display();
  } else if (strcmp(arg, "w") == 0) {
    wp_display();
  } else {
    printf("Unknown info command '%s'. Use 'info r' for "
                      "registers or 'info w' for watchpoints.\n", arg);
  }
  return 0;
}

static int cmd_x(char *args){
  size_t length = strlen(args);
  char *num = strtok(args, " ");                       //获取指令条数
  char *addr_str = args + strlen(num) + 1;  //获取地址参数的起始位置

  if (num == NULL || addr_str >= args + length) {  //检查是否有足够的参数
    printf("Please specify the printed instruction's num and address.\n");
    return 0;
  }

  bool success;
  vaddr_t addr = expr(addr_str, &success);  
  if (!success) 
    printf("Invalid address expression: %s\n", addr_str);
  else {
    for (int i = 0; i < atoi(num); i++){
      if (i % 4 == 0) printf("0x%08x:", addr + i * 4);        //每4条指令重新打印1行地址
      printf("  0x%08x", vaddr_read(addr + i * 4, 4));
      if (i % 4 == 3) printf("\n");                                             //每4条指令换行                                                                                                    
      if (atoi(num) - 1 == i && i % 4 != 3) printf("\n");  //最后1行指令不足4条时换行
    }
  }
  return 0;
}

static int cmd_p(char *args) {
  if (args == NULL) {                       //如果使用之前strtok函数方案，会将' '变为'\0'                              
    printf("Please input the expression.\n");
    return 0;
  }

  bool success;
  word_t result = expr(args, &success);

  if (!success) 
    printf("Invalid expression: %s\n", args);
  else 
    printf("0x%08x\t%u\n", result, result);
  
  return 0;
}

static int cmd_w(char *args) {
  if (args == NULL) {                       //如果使用之前strtok函数方案，会将' '变为'\0'  
    printf("Please input the expression for the watchpoint.\n");
    return 0;
  }

  bool success;
  word_t result = expr(args, &success);

  if (!success) 
    printf("Invalid expression: %s\n", args);
  else {
    wp_set(args, result);
  }

  return 0; 
}

static int cmd_d(char *args) {
  char *arg = strtok(args, " ");

  if (arg == NULL) {
    printf("Please input the expression for the watchpoint.\n");
    return 0;
  }

  wp_d(atoi(arg));
  return 0;  
}

//用于测试expr函数的正确性
/*
static void expr_test() {
  FILE *fp = fopen("input", "r");
  if (fp == NULL) {
    printf("Can not open 'input'\n");
    return;
  }

  char line[65536];
  int line_no = 0;
  int pass = 0, fail = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    line_no++;

    // 跳过空行
    if (line[0] == '\n' || line[0] == '\0') continue;

    // 解析 "期望结果 表达式"
    unsigned int expected;
    char expr_str[65536];
    if (sscanf(line, "%u %[^\n]", &expected, expr_str) != 2) {       //%[^\n]匹配除换行符之外的所有字符，^表示取反
      printf("Line %d: parse error: %s", line_no, line);
      continue;
    }

    // 用 NEMU 的 expr 求值
    bool success;
    word_t result = expr(expr_str, &success);

    // 比较
    if (!success) {
      printf("\033[31mFAIL\033[0m Line %d: %s (expr() returned false)\n", 
                      line_no, expr_str);
      fail++;
    } else if (result != expected) {
      printf("\033[31mFAIL\033[0m Line %d: %s\n  Expected: %u, Got: %u\n",
                      line_no, expr_str, expected, result);
      fail++;
    } else {
      pass++;
      printf("PASS Line %d: %s = %u\n", line_no, expr_str, result);
    }
  }

  fclose(fp);
  printf("\n=== Test Summary ===\n");
  printf("Total: %d, Pass: %d, Fail: %d\n", pass + fail, pass, fail);
}
*/

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    //expr_test();
    //nemu_state.state = NEMU_QUIT;
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
