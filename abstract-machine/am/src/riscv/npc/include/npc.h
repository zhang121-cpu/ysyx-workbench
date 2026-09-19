#ifndef NPC_H_
#define NPC_H_

#include <riscv/riscv.h>

#define DEVICE_BASE 0x10000000

#define SERIAL_PORT (DEVICE_BASE + 0x00000000)
#define RTC_ADDR    (DEVICE_BASE + 0x00000004)

#endif