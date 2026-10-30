// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

extern "C" unsigned int pmem_read(unsigned int addr, int len);

void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    int len__Vcvt;
    len__Vcvt = len;
    unsigned int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(addr__Vcvt, len__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void pmem_write(unsigned int addr, unsigned int data, int len);

void Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    unsigned int data__Vcvt;
    data__Vcvt = data;
    int len__Vcvt;
    len__Vcvt = len;
    pmem_write(addr__Vcvt, data__Vcvt, len__Vcvt);
}

extern "C" void pmem_rst();

void Vtop___024unit____Vdpiimwrap_pmem_rst_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_pmem_rst_TOP____024unit\n"); );
    // Body
    pmem_rst();
}

extern "C" void ebreak_handler(unsigned int a0);

void Vtop___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit(IData/*31:0*/ a0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit\n"); );
    // Body
    unsigned int a0__Vcvt;
    a0__Vcvt = a0;
    ebreak_handler(a0__Vcvt);
}
