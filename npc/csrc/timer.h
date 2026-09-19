#ifndef TIMER_H
#define TIMER_H

#define _POSIX_C_SOURCE 200809L   // 用于开启time.h中特定功能

#include <stdint.h>
#include <time.h>                 

/* 取"单调时钟"的微秒值*/
static uint64_t now_us() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000 + (uint64_t)ts.tv_nsec / 1000;
}

/* AM_TIMER_UPTIME 的语义：开机（仿真开始）至今的微秒数 */
static uint64_t uptime_us() {
    static uint64_t boot = 0;
    if (boot == 0) boot = now_us();     // 第一次调用时记录起点
    return now_us() - boot;
}

#endif
