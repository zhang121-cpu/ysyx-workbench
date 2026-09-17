#include <stdio.h>
#include <common.h>
#include <stdarg.h> 

static FILE *dtrace_fp = NULL;   // dtrace 输出目标

//推导 build 目录, 把日志写到 .../build/nemu-log-dtrace.txt
static void init_dtrace_log(const char *log_file) {
    char path[256];
    strcpy(path, log_file);
    char *slash = strrchr(path, '/');          // 找最后一个 '/'
    strcpy(slash + 1, "nemu-log-dtrace.txt");  // 替换文件名
    dtrace_fp = fopen(path, "w");
    Assert(dtrace_fp, "Can not open dtrace log '%s'", path);
    Log("dtrace log is written to %s", path);
}

void init_dtrace(const char *log_file) {
    if (log_file == NULL) return;
    init_dtrace_log(log_file);
}

void dtrace_log(const char *fmt, ...) {
    if (dtrace_fp == NULL) return;
    va_list ap;
    va_start(ap, fmt);
    vfprintf(dtrace_fp, fmt, ap);
    va_end(ap);
    fflush(dtrace_fp);
}
