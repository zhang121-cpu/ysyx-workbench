// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop___024unit;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*3:0*/ top__DOT__op_alu;
        CData/*0:0*/ top__DOT__alu_src2_sel;
        CData/*1:0*/ top__DOT__wdata_sel;
        CData/*0:0*/ top__DOT__m_ren;
        CData/*0:0*/ top__DOT__m_wen;
        CData/*1:0*/ top__DOT__m_size;
        CData/*0:0*/ top__DOT__wen;
        CData/*0:0*/ top__DOT__jump_en;
        CData/*0:0*/ top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_9;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_10;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_11;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*14:0*/ top__DOT__gpr__DOT__reg_wen;
        SData/*15:0*/ top__DOT__gpr__DOT__dec1__DOT__pout;
        IData/*31:0*/ top__DOT__pc_state;
        IData/*31:0*/ top__DOT__instruction;
        IData/*31:0*/ top__DOT__rdata1;
        IData/*31:0*/ top__DOT__rdata2;
        IData/*31:0*/ top__DOT__m_addr;
        IData/*31:0*/ top__DOT__m_rdata;
        IData/*31:0*/ top__DOT__ifu__DOT__pc_nextstate;
        IData/*31:0*/ top__DOT__exu__DOT__imm;
        IData/*31:0*/ top__DOT__exu__DOT__alu_result;
        IData/*31:0*/ top__DOT__mem__DOT__len;
        IData/*31:0*/ top__DOT__gpr__DOT__wdata;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4;
        IData/*31:0*/ top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4;
        VlWide<18>/*575:0*/ top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut;
        IData/*31:0*/ top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out;
        IData/*31:0*/ __Vfunc_pmem_read__1__Vfuncout;
        IData/*31:0*/ __Vfunc_pmem_read__2__Vfuncout;
        IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_6;
        IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_14;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*35:0*/, 16> top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 16> top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 16> top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 16> top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 16> top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 16> top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
