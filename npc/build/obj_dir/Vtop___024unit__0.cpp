// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

extern "C" void npc_sync_gpr(unsigned int idx, unsigned int val);

void Vtop___024unit____Vdpiimwrap_npc_sync_gpr_TOP____024unit(IData/*31:0*/ idx, IData/*31:0*/ val) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_sync_gpr_TOP____024unit\n"); );
    // Body
    unsigned int idx__Vcvt;
    idx__Vcvt = idx;
    unsigned int val__Vcvt;
    val__Vcvt = val;
    npc_sync_gpr(idx__Vcvt, val__Vcvt);
}

extern "C" unsigned int npc_mem_read(unsigned int addr, int len);

void Vtop___024unit____Vdpiimwrap_npc_mem_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &npc_mem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_mem_read_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    int len__Vcvt;
    len__Vcvt = len;
    unsigned int npc_mem_read__Vfuncrtn__Vcvt;
    npc_mem_read__Vfuncrtn__Vcvt = npc_mem_read(addr__Vcvt, len__Vcvt);
    npc_mem_read__Vfuncrtn = (npc_mem_read__Vfuncrtn__Vcvt);
}

extern "C" unsigned int npc_mem_ifetch(unsigned int addr, int len);

void Vtop___024unit____Vdpiimwrap_npc_mem_ifetch_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &npc_mem_ifetch__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_mem_ifetch_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    int len__Vcvt;
    len__Vcvt = len;
    unsigned int npc_mem_ifetch__Vfuncrtn__Vcvt;
    npc_mem_ifetch__Vfuncrtn__Vcvt = npc_mem_ifetch(addr__Vcvt, len__Vcvt);
    npc_mem_ifetch__Vfuncrtn = (npc_mem_ifetch__Vfuncrtn__Vcvt);
}

extern "C" void npc_mem_write(unsigned int addr, unsigned int data, int len);

void Vtop___024unit____Vdpiimwrap_npc_mem_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_mem_write_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    unsigned int data__Vcvt;
    data__Vcvt = data;
    int len__Vcvt;
    len__Vcvt = len;
    npc_mem_write(addr__Vcvt, data__Vcvt, len__Vcvt);
}

extern "C" void npc_commit_inst(unsigned int pc, unsigned int inst, unsigned int dnpc);

void Vtop___024unit____Vdpiimwrap_npc_commit_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ inst, IData/*31:0*/ dnpc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_commit_inst_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    unsigned int inst__Vcvt;
    inst__Vcvt = inst;
    unsigned int dnpc__Vcvt;
    dnpc__Vcvt = dnpc;
    npc_commit_inst(pc__Vcvt, inst__Vcvt, dnpc__Vcvt);
}

extern "C" void npc_trap(unsigned int pc, unsigned int a0);

void Vtop___024unit____Vdpiimwrap_npc_trap_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ a0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_npc_trap_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    unsigned int a0__Vcvt;
    a0__Vcvt = a0;
    npc_trap(pc__Vcvt, a0__Vcvt);
}
