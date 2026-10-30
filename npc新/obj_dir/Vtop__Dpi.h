// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vsrc/top.v:1:30
    extern void ebreak_handler(unsigned int a0);
    // DPI import at vsrc/MEM.v:1:38
    extern unsigned int pmem_read(unsigned int addr, int len);
    // DPI import at vsrc/MEM.v:4:30
    extern void pmem_rst();
    // DPI import at vsrc/MEM.v:2:30
    extern void pmem_write(unsigned int addr, unsigned int data, int len);

#ifdef __cplusplus
}
#endif

#endif  // guard
