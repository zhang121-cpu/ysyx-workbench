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

#ifndef __UTILS_H__
#define __UTILS_H__

#include <common.h>

// ----------- state -----------

enum { NEMU_RUNNING, NEMU_STOP, NEMU_END, NEMU_ABORT, NEMU_QUIT };

typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NEMUState;

extern NEMUState nemu_state;

// ----------- timer -----------

uint64_t get_time();

// ----------- log -----------

// ANSI 转义序列（一种终端控制协议）: \33[ 后跟参数和 m 终止，用于控制终端文字的前景色和背景色
// 格式: \33[<属性>;<前景色>m   或   \33[<属性>;<背景色>m
// 其中 1 表示高亮/加粗, 30-37 是前景色编号, 40-47 是背景色编号

// --- 前景色(Foreground): 设置文字颜色 ---
#define ANSI_FG_BLACK   "\33[1;30m"   // 前景 黑色
#define ANSI_FG_RED     "\33[1;31m"   // 前景 红色
#define ANSI_FG_GREEN   "\33[1;32m"   // 前景 绿色
#define ANSI_FG_YELLOW  "\33[1;33m"   // 前景 黄色
#define ANSI_FG_BLUE    "\33[1;34m"   // 前景 蓝色
#define ANSI_FG_MAGENTA "\33[1;35m"   // 前景 品红(洋红)
#define ANSI_FG_CYAN    "\33[1;36m"   // 前景 青色
#define ANSI_FG_WHITE   "\33[1;37m"   // 前景 白色

// --- 背景色(Background): 设置文字底色 ---
#define ANSI_BG_BLACK   "\33[1;40m"   // 背景 黑色
#define ANSI_BG_RED     "\33[1;41m"   // 背景 红色
#define ANSI_BG_GREEN   "\33[1;42m"   // 背景 绿色
#define ANSI_BG_YELLOW  "\33[1;43m"   // 背景 黄色
#define ANSI_BG_BLUE    "\33[1;44m"   // 背景 蓝色
#define ANSI_BG_MAGENTA "\33[1;45m"   // 背景 品红(洋红)
#define ANSI_BG_CYAN    "\33[1;46m"   // 背景 青色
#define ANSI_BG_WHITE   "\33[1;47m"   // 背景 白色

// --- 重置: 关闭所有颜色/样式, 恢复终端默认显示 ---
#define ANSI_NONE       "\33[0m"

//fmt指format,ANSI_FMT(str, fmt)作用是：给字符串加上颜色，然后自动恢复默认颜色
#define ANSI_FMT(str, fmt) fmt str ANSI_NONE 

#define log_write(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp; \
    extern bool log_enable(); \
    if (log_enable() && log_fp != NULL) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0) \
)

#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)


#endif
