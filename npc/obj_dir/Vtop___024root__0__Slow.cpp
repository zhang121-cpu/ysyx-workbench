// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[15U] = 0ULL;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[15U] = 0U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[0U] = 0x0fU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[1U] = 0x0eU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[2U] = 0x0dU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[3U] = 0x0cU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[4U] = 0x0bU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[5U] = 0x0aU;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[6U] = 9U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[7U] = 8U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[8U] = 7U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[9U] = 6U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[10U] = 5U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[11U] = 4U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[12U] = 3U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[13U] = 2U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[14U] = 1U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[15U] = 0U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[15U] = 0ULL;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[15U] = 0U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[0U] = 0x0fU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[1U] = 0x0eU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[2U] = 0x0dU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[3U] = 0x0cU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[4U] = 0x0bU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[5U] = 0x0aU;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[6U] = 9U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[7U] = 8U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[8U] = 7U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[9U] = 6U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[10U] = 5U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[11U] = 4U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[12U] = 3U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[13U] = 2U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[14U] = 1U;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[15U] = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[0U] 
        = (0x0000000f00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[14U] 
        = (0x0000000100000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[0U] 
        = (0x0000000f00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[14U] 
        = (0x0000000100000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[9U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[10U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[11U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[12U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[13U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[14U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[9U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[10U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[11U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[12U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[13U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[14U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[0U] 
        = (IData)((0x0000000f00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[1U] 
        = ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4 
            << 4U) | (IData)(((0x0000000f00000000ULL 
                               | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4))) 
                              >> 0x00000020U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U] 
        = (0x000000e0U | ((0xffffff00U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U]) 
                          | (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4 
                             >> 0x0000001cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U] 
        = ((0x000000ffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U]) 
           | ((IData)((0x0000000d00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4)))) 
              << 8U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[3U] 
        = (((IData)((0x0000000d00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4)))) 
            >> 0x00000018U) | ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 
                                << 0x0000000cU) | ((IData)(
                                                           ((0x0000000d00000000ULL 
                                                             | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4))) 
                                                            >> 0x00000020U)) 
                                                   << 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U] 
        = (0x0000c000U | ((0xffff0000U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U]) 
                          | (((0x000000ffU & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 
                                              >> 0x00000014U)) 
                              | ((IData)(((0x0000000d00000000ULL 
                                           | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4))) 
                                          >> 0x00000020U)) 
                                 >> 0x00000018U)) | 
                             (0x00000f00U & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 
                                             >> 0x00000014U)))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U] 
        = ((0x0000ffffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U]) 
           | ((IData)((0x0000000b00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4)))) 
              << 0x00000010U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[5U] 
        = (((IData)((0x0000000b00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4)))) 
            >> 0x00000010U) | ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 
                                << 0x00000014U) | ((IData)(
                                                           ((0x0000000b00000000ULL 
                                                             | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4))) 
                                                            >> 0x00000020U)) 
                                                   << 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U] 
        = (0x00a00000U | ((0xff000000U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U]) 
                          | (((0x0000ffffU & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 
                                              >> 0x0000000cU)) 
                              | ((IData)(((0x0000000b00000000ULL 
                                           | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4))) 
                                          >> 0x00000020U)) 
                                 >> 0x00000010U)) | 
                             (0x000f0000U & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 
                                             >> 0x0000000cU)))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U] 
        = ((0x00ffffffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U]) 
           | ((IData)((0x0000000900000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4)))) 
              << 0x00000018U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[7U] 
        = (((IData)((0x0000000900000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4)))) 
            >> 8U) | ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 
                       << 0x0000001cU) | ((IData)((
                                                   (0x0000000900000000ULL 
                                                    | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4))) 
                                                   >> 0x00000020U)) 
                                          << 0x00000018U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[8U] 
        = (0x80000000U | (((0x00ffffffU & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 
                                           >> 4U)) 
                           | ((IData)(((0x0000000900000000ULL 
                                        | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4))) 
                                       >> 0x00000020U)) 
                              >> 8U)) | (0x0f000000U 
                                         & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 
                                            >> 4U))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[9U] 
        = (IData)((0x0000000700000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[10U] 
        = ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4 
            << 4U) | (IData)(((0x0000000700000000ULL 
                               | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4))) 
                              >> 0x00000020U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U] 
        = (0x00000060U | ((0xffffff00U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U]) 
                          | (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4 
                             >> 0x0000001cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U] 
        = ((0x000000ffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U]) 
           | ((IData)((0x0000000500000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4)))) 
              << 8U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[12U] 
        = (((IData)((0x0000000500000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4)))) 
            >> 0x00000018U) | ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 
                                << 0x0000000cU) | ((IData)(
                                                           ((0x0000000500000000ULL 
                                                             | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4))) 
                                                            >> 0x00000020U)) 
                                                   << 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U] 
        = (0x00004000U | ((0xffff0000U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U]) 
                          | (((0x000000ffU & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 
                                              >> 0x00000014U)) 
                              | ((IData)(((0x0000000500000000ULL 
                                           | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4))) 
                                          >> 0x00000020U)) 
                                 >> 0x00000018U)) | 
                             (0x00000f00U & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 
                                             >> 0x00000014U)))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U] 
        = ((0x0000ffffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U]) 
           | ((IData)((0x0000000300000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4)))) 
              << 0x00000010U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[14U] 
        = (((IData)((0x0000000300000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4)))) 
            >> 0x00000010U) | ((vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 
                                << 0x00000014U) | ((IData)(
                                                           ((0x0000000300000000ULL 
                                                             | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4))) 
                                                            >> 0x00000020U)) 
                                                   << 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U] 
        = (0x00200000U | ((0xff000000U & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U]) 
                          | (((0x0000ffffU & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 
                                              >> 0x0000000cU)) 
                              | ((IData)(((0x0000000300000000ULL 
                                           | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4))) 
                                          >> 0x00000020U)) 
                                 >> 0x00000010U)) | 
                             (0x000f0000U & (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 
                                             >> 0x0000000cU)))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U] 
        = ((0x00ffffffU & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U]) 
           | (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4 
              << 0x00000018U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[16U] 
        = (0x01000000U | (vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4 
                          >> 8U));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[17U] = 0U;
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__instruction = 0U;
    } else {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__pc_state, 4U, vlSelfRef.__Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_pmem_read__1__Vfuncout;
    }
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[1U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[1U])) 
                                       >> 4U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[2U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[3U])) 
                                     << 0x00000018U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U])) 
                                       >> 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[3U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U])) 
                                     << 0x00000014U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[3U])) 
                                       >> 0x0000000cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[4U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[5U])) 
                                     << 0x00000010U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U])) 
                                       >> 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[5U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U])) 
                                     << 0x0000000cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[5U])) 
                                       >> 0x00000014U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[6U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[7U])) 
                                     << 8U) | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U])) 
                                               >> 0x00000018U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[7U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[8U])) 
                                     << 4U) | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[7U])) 
                                               >> 0x0000001cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[8U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[10U])) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[9U]))));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[9U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[10U])) 
                                       >> 4U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[10U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[12U])) 
                                     << 0x00000018U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U])) 
                                       >> 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[11U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U])) 
                                     << 0x00000014U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[12U])) 
                                       >> 0x0000000cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[12U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[14U])) 
                                     << 0x00000010U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U])) 
                                       >> 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[13U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U])) 
                                     << 0x0000000cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[14U])) 
                                       >> 0x00000014U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[1U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[1U])) 
                                       >> 4U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[2U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[3U])) 
                                     << 0x00000018U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[2U])) 
                                       >> 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[3U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U])) 
                                     << 0x00000014U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[3U])) 
                                       >> 0x0000000cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[4U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[5U])) 
                                     << 0x00000010U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[4U])) 
                                       >> 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[5U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U])) 
                                     << 0x0000000cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[5U])) 
                                       >> 0x00000014U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[6U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[7U])) 
                                     << 8U) | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[6U])) 
                                               >> 0x00000018U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[7U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[8U])) 
                                     << 4U) | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[7U])) 
                                               >> 0x0000001cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[8U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[10U])) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[9U]))));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[9U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[10U])) 
                                       >> 4U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[10U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[12U])) 
                                     << 0x00000018U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[11U])) 
                                       >> 8U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[11U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U])) 
                                     << 0x00000014U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[12U])) 
                                       >> 0x0000000cU)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[12U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[14U])) 
                                     << 0x00000010U) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[13U])) 
                                       >> 0x00000010U)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[13U] 
        = (0x0000000fffffffffULL & (((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[15U])) 
                                     << 0x0000000cU) 
                                    | ((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut[14U])) 
                                       >> 0x00000014U)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                           >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[0U]);
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[1U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[2U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[3U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[4U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[5U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[6U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[7U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[8U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[9U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[10U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[11U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[12U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[13U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[14U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x0000000fU)) == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[15U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                           >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[0U]);
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[1U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[2U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[3U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[4U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[5U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[6U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[7U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[8U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[9U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[10U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[11U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[12U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[13U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[14U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit 
        = ((IData)(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit) 
           | ((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                              >> 0x00000014U)) == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[15U]));
    vlSelfRef.top__DOT__wen = 0U;
    vlSelfRef.top__DOT__jump_en = 0U;
    vlSelfRef.top__DOT__wdata_sel = 0U;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = (IData)(
                                                       (0x00000600U 
                                                        == 
                                                        (0x00000700U 
                                                         & vlSelfRef.top__DOT__instruction)));
    vlSelfRef.top__DOT__m_size = 0U;
    vlSelfRef.top__DOT__m_wen = 0U;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (IData)(
                                                       (0U 
                                                        == 
                                                        (0x00000600U 
                                                         & vlSelfRef.top__DOT__instruction)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = (IData)(
                                                       (0x00000200U 
                                                        == 
                                                        (0x00000600U 
                                                         & vlSelfRef.top__DOT__instruction)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = (IData)(
                                                       (0x00000400U 
                                                        == 
                                                        (0x00000600U 
                                                         & vlSelfRef.top__DOT__instruction)));
    vlSelfRef.top__DOT__m_ren = 0U;
    if ((1U & (~ (vlSelfRef.top__DOT__instruction >> 6U)))) {
        if ((0x00000020U & vlSelfRef.top__DOT__instruction)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instruction)) {
                            if ((1U & vlSelfRef.top__DOT__instruction)) {
                                if ((0U == (7U & (vlSelfRef.top__DOT__instruction 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.top__DOT__m_size = 0U;
                                    vlSelfRef.top__DOT__m_wen = 1U;
                                } else if ((2U == (7U 
                                                   & (vlSelfRef.top__DOT__instruction 
                                                      >> 0x0000000cU)))) {
                                    vlSelfRef.top__DOT__m_size = 2U;
                                    vlSelfRef.top__DOT__m_wen = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                             >> 4U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__instruction)) {
                        if ((1U & vlSelfRef.top__DOT__instruction)) {
                            if ((2U == (7U & (vlSelfRef.top__DOT__instruction 
                                              >> 0x0000000cU)))) {
                                vlSelfRef.top__DOT__m_size = 2U;
                            } else if ((4U == (7U & 
                                               (vlSelfRef.top__DOT__instruction 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.top__DOT__m_size = 0U;
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.top__DOT__instruction)) {
                            if ((1U & vlSelfRef.top__DOT__instruction)) {
                                if ((2U == (7U & (vlSelfRef.top__DOT__instruction 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.top__DOT__m_ren = 1U;
                                } else if ((4U == (7U 
                                                   & (vlSelfRef.top__DOT__instruction 
                                                      >> 0x0000000cU)))) {
                                    vlSelfRef.top__DOT__m_ren = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__op_alu = 0x0fU;
    vlSelfRef.top__DOT__alu_src2_sel = 0U;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                       >> 0x0000000fU)) 
                       == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[0U]))) 
           & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[0U]);
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[1U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[1U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[2U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[2U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[3U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[3U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[4U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[4U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[5U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[5U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[6U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[6U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[7U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[7U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[8U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[8U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[9U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[9U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[10U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[10U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[11U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[11U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[12U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[12U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[13U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[13U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[14U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[14U]));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000fU)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[15U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[15U]));
    vlSelfRef.top__DOT__rdata1 = vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                       >> 0x00000014U)) 
                       == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[0U]))) 
           & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[0U]);
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[1U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[1U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[2U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[2U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[3U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[3U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[4U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[4U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[5U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[5U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[6U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[6U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[7U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[7U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[8U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[8U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[9U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[9U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[10U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[10U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[11U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[11U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[12U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[12U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[13U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[13U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[14U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[14U]));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
        = (vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                          >> 0x00000014U)) 
                          == vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[15U]))) 
              & vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[15U]));
    vlSelfRef.top__DOT__rdata2 = vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 = ((((- (IData)(
                                                             (vlSelfRef.top__DOT__instruction 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | (vlSelfRef.top__DOT__instruction 
                                                    >> 0x00000014U)) 
                                                & (- (IData)(
                                                             (3U 
                                                              == 
                                                              (3U 
                                                               & vlSelfRef.top__DOT__instruction)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = (0xfffff000U 
                                                 & (vlSelfRef.top__DOT__instruction 
                                                    & (- (IData)(
                                                                 (3U 
                                                                  == 
                                                                  (3U 
                                                                   & vlSelfRef.top__DOT__instruction))))));
    if ((0x00000040U & vlSelfRef.top__DOT__instruction)) {
        if ((0x00000020U & vlSelfRef.top__DOT__instruction)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.top__DOT__instruction)) {
                        if ((2U & vlSelfRef.top__DOT__instruction)) {
                            if ((1U & vlSelfRef.top__DOT__instruction)) {
                                vlSelfRef.top__DOT__wen = 1U;
                                vlSelfRef.top__DOT__jump_en = 1U;
                                vlSelfRef.top__DOT__wdata_sel = 2U;
                                vlSelfRef.top__DOT__op_alu = 0U;
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        vlSelfRef.top__DOT__exu__DOT__imm = ((- (IData)(
                                                        (1U 
                                                         & (~ 
                                                            (vlSelfRef.top__DOT__instruction 
                                                             >> 4U))))) 
                                             & (((8U 
                                                  & vlSelfRef.top__DOT__instruction)
                                                  ? 
                                                 ((((- (IData)(
                                                               (vlSelfRef.top__DOT__instruction 
                                                                >> 0x0000001fU))) 
                                                    << 0x00000014U) 
                                                   | ((((0x000001feU 
                                                         & (vlSelfRef.top__DOT__instruction 
                                                            >> 0x0000000bU)) 
                                                        | (1U 
                                                           & (vlSelfRef.top__DOT__instruction 
                                                              >> 0x00000014U))) 
                                                       << 0x0000000bU) 
                                                      | (0x000007feU 
                                                         & (vlSelfRef.top__DOT__instruction 
                                                            >> 0x00000014U)))) 
                                                  & (- (IData)(
                                                               (7U 
                                                                == 
                                                                (7U 
                                                                 & vlSelfRef.top__DOT__instruction)))))
                                                  : 
                                                 ((4U 
                                                   & vlSelfRef.top__DOT__instruction)
                                                   ? vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6
                                                   : 
                                                  ((((- (IData)(
                                                                (vlSelfRef.top__DOT__instruction 
                                                                 >> 0x0000001fU))) 
                                                     << 0x0000000cU) 
                                                    | ((0x00000800U 
                                                        & (vlSelfRef.top__DOT__instruction 
                                                           << 4U)) 
                                                       | ((0x000007e0U 
                                                           & (vlSelfRef.top__DOT__instruction 
                                                              >> 0x00000014U)) 
                                                          | (0x0000001eU 
                                                             & (vlSelfRef.top__DOT__instruction 
                                                                >> 7U))))) 
                                                   & (- (IData)(
                                                                (3U 
                                                                 == 
                                                                 (3U 
                                                                  & vlSelfRef.top__DOT__instruction))))))) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__instruction 
                                                                 >> 5U))))));
    } else if ((0x00000020U & vlSelfRef.top__DOT__instruction)) {
        if ((0x00000010U & vlSelfRef.top__DOT__instruction)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__instruction)) {
                    if ((2U & vlSelfRef.top__DOT__instruction)) {
                        if ((1U & vlSelfRef.top__DOT__instruction)) {
                            vlSelfRef.top__DOT__wen = 1U;
                            vlSelfRef.top__DOT__wdata_sel = 3U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__instruction)) {
                    if ((1U & vlSelfRef.top__DOT__instruction)) {
                        if ((0U == (7U & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000cU)))) {
                            if ((0U == (vlSelfRef.top__DOT__instruction 
                                        >> 0x00000019U))) {
                                vlSelfRef.top__DOT__wen = 1U;
                                vlSelfRef.top__DOT__wdata_sel = 0U;
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__instruction)) {
                        if ((1U & vlSelfRef.top__DOT__instruction)) {
                            if ((0U == (7U & (vlSelfRef.top__DOT__instruction 
                                              >> 0x0000000cU)))) {
                                if ((0U == (vlSelfRef.top__DOT__instruction 
                                            >> 0x00000019U))) {
                                    vlSelfRef.top__DOT__op_alu = 0U;
                                    vlSelfRef.top__DOT__alu_src2_sel = 0U;
                                }
                            }
                        }
                    }
                }
            }
            vlSelfRef.top__DOT__exu__DOT__imm = ((- (IData)((IData)(
                                                                    (4U 
                                                                     == 
                                                                     (0x0000000cU 
                                                                      & vlSelfRef.top__DOT__instruction))))) 
                                                 & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14);
        } else {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__instruction)) {
                        if ((1U & vlSelfRef.top__DOT__instruction)) {
                            if ((0U == (7U & (vlSelfRef.top__DOT__instruction 
                                              >> 0x0000000cU)))) {
                                vlSelfRef.top__DOT__op_alu = 0U;
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            } else if ((2U == (7U & 
                                               (vlSelfRef.top__DOT__instruction 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.top__DOT__op_alu = 0U;
                                vlSelfRef.top__DOT__alu_src2_sel = 1U;
                            }
                        }
                    }
                }
            }
            vlSelfRef.top__DOT__exu__DOT__imm = (((
                                                   (- (IData)(
                                                              (vlSelfRef.top__DOT__instruction 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000cU) 
                                                  | ((0x00000fe0U 
                                                      & (vlSelfRef.top__DOT__instruction 
                                                         >> 0x00000014U)) 
                                                     | (0x0000001fU 
                                                        & (vlSelfRef.top__DOT__instruction 
                                                           >> 7U)))) 
                                                 & (- (IData)((IData)(
                                                                      (3U 
                                                                       == 
                                                                       (0x0000000fU 
                                                                        & vlSelfRef.top__DOT__instruction))))));
        }
    } else if ((0x00000010U & vlSelfRef.top__DOT__instruction)) {
        if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__instruction)) {
                    if ((1U & vlSelfRef.top__DOT__instruction)) {
                        if ((0U == (7U & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000cU)))) {
                            vlSelfRef.top__DOT__wen = 1U;
                            vlSelfRef.top__DOT__wdata_sel = 0U;
                            vlSelfRef.top__DOT__op_alu = 0U;
                            vlSelfRef.top__DOT__alu_src2_sel = 1U;
                        }
                    }
                }
            }
        }
        vlSelfRef.top__DOT__exu__DOT__imm = (((4U & vlSelfRef.top__DOT__instruction)
                                               ? vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14
                                               : vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                             & (- (IData)(
                                                          (1U 
                                                           & (~ 
                                                              (vlSelfRef.top__DOT__instruction 
                                                               >> 3U))))));
    } else {
        if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__instruction 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__instruction)) {
                    if ((1U & vlSelfRef.top__DOT__instruction)) {
                        if ((2U == (7U & (vlSelfRef.top__DOT__instruction 
                                          >> 0x0000000cU)))) {
                            vlSelfRef.top__DOT__wen = 1U;
                            vlSelfRef.top__DOT__wdata_sel = 1U;
                            vlSelfRef.top__DOT__op_alu = 0U;
                            vlSelfRef.top__DOT__alu_src2_sel = 1U;
                        } else if ((4U == (7U & (vlSelfRef.top__DOT__instruction 
                                                 >> 0x0000000cU)))) {
                            vlSelfRef.top__DOT__wen = 1U;
                            vlSelfRef.top__DOT__wdata_sel = 1U;
                            vlSelfRef.top__DOT__op_alu = 0U;
                            vlSelfRef.top__DOT__alu_src2_sel = 1U;
                        }
                    }
                }
            }
        }
        vlSelfRef.top__DOT__exu__DOT__imm = (vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (~ 
                                                               (vlSelfRef.top__DOT__instruction 
                                                                >> 3U))))) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ 
                                                                 (vlSelfRef.top__DOT__instruction 
                                                                  >> 2U)))))));
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11 = ((~ 
                                                  (vlSelfRef.top__DOT__instruction 
                                                   >> 8U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((~ 
                                                  (vlSelfRef.top__DOT__instruction 
                                                   >> 8U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9 = ((~ 
                                                 (vlSelfRef.top__DOT__instruction 
                                                  >> 8U)) 
                                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.top__DOT__gpr__DOT__dec1__DOT__pout = 
        (((((((0x0000000fU == (0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                              >> 7U))) 
              << 3U) | ((IData)((0x00000700U == (0x00000780U 
                                                 & vlSelfRef.top__DOT__instruction))) 
                        << 2U)) | ((0x03fffffeU & (
                                                   (vlSelfRef.top__DOT__instruction 
                                                    >> 6U) 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8) 
                                                      << 1U))) 
                                   | ((~ (vlSelfRef.top__DOT__instruction 
                                          >> 7U)) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8)))) 
           << 0x0000000cU) | (((((IData)(((0x00000180U 
                                           == (0x00000180U 
                                               & vlSelfRef.top__DOT__instruction)) 
                                          & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
                                 << 3U) | ((IData)(
                                                   ((0x00000100U 
                                                     == 
                                                     (0x00000180U 
                                                      & vlSelfRef.top__DOT__instruction)) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
                                           << 2U)) 
                               | ((0x03fffffeU & ((vlSelfRef.top__DOT__instruction 
                                                   >> 6U) 
                                                  & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9) 
                                                     << 1U))) 
                                  | ((~ (vlSelfRef.top__DOT__instruction 
                                         >> 7U)) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)))) 
                              << 8U)) | ((((((IData)(
                                                     ((0x00000180U 
                                                       == 
                                                       (0x00000180U 
                                                        & vlSelfRef.top__DOT__instruction)) 
                                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))) 
                                             << 3U) 
                                            | ((IData)(
                                                       ((0x00000100U 
                                                         == 
                                                         (0x00000180U 
                                                          & vlSelfRef.top__DOT__instruction)) 
                                                        & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))) 
                                               << 2U)) 
                                           | ((0x03fffffeU 
                                               & ((vlSelfRef.top__DOT__instruction 
                                                   >> 6U) 
                                                  & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
                                                     << 1U))) 
                                              | ((~ 
                                                  (vlSelfRef.top__DOT__instruction 
                                                   >> 7U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)))) 
                                          << 4U) | 
                                         ((((IData)(
                                                    ((0x00000180U 
                                                      == 
                                                      (0x00000180U 
                                                       & vlSelfRef.top__DOT__instruction)) 
                                                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))) 
                                            << 3U) 
                                           | ((IData)(
                                                      ((0x00000100U 
                                                        == 
                                                        (0x00000180U 
                                                         & vlSelfRef.top__DOT__instruction)) 
                                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))) 
                                              << 2U)) 
                                          | ((0x03fffffeU 
                                              & ((vlSelfRef.top__DOT__instruction 
                                                  >> 6U) 
                                                 & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                                                    << 1U))) 
                                             | ((~ 
                                                 (vlSelfRef.top__DOT__instruction 
                                                  >> 7U)) 
                                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11))))));
    vlSelfRef.top__DOT__exu__DOT__alu_result = ((vlSelfRef.top__DOT__rdata1 
                                                 + 
                                                 ((IData)(vlSelfRef.top__DOT__alu_src2_sel)
                                                   ? vlSelfRef.top__DOT__exu__DOT__imm
                                                   : vlSelfRef.top__DOT__rdata2)) 
                                                & (- (IData)(
                                                             (0U 
                                                              == (IData)(vlSelfRef.top__DOT__op_alu)))));
    vlSelfRef.top__DOT__gpr__DOT__reg_wen = (0x00007fffU 
                                             & (((IData)(vlSelfRef.top__DOT__gpr__DOT__dec1__DOT__pout) 
                                                 >> 1U) 
                                                & (- (IData)((IData)(vlSelfRef.top__DOT__wen)))));
    vlSelfRef.top__DOT__ifu__DOT__pc_nextstate = ((IData)(vlSelfRef.top__DOT__jump_en)
                                                   ? 
                                                  (0xfffffffeU 
                                                   & vlSelfRef.top__DOT__exu__DOT__alu_result)
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pc_state));
    vlSelfRef.top__DOT__m_addr = 0U;
    if (vlSelfRef.top__DOT__m_wen) {
        vlSelfRef.top__DOT__m_addr = vlSelfRef.top__DOT__exu__DOT__alu_result;
    }
    vlSelfRef.top__DOT__mem__DOT__len = ((0U == (IData)(vlSelfRef.top__DOT__m_size))
                                          ? 1U : ((1U 
                                                   == (IData)(vlSelfRef.top__DOT__m_size))
                                                   ? 2U
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelfRef.top__DOT__m_size))
                                                    ? 4U
                                                    : 0U)));
    if (vlSelfRef.top__DOT__m_ren) {
        vlSelfRef.top__DOT__m_addr = vlSelfRef.top__DOT__exu__DOT__alu_result;
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__m_addr, vlSelfRef.top__DOT__mem__DOT__len, vlSelfRef.__Vfunc_pmem_read__2__Vfuncout);
        vlSelfRef.top__DOT__m_rdata = vlSelfRef.__Vfunc_pmem_read__2__Vfuncout;
    } else {
        vlSelfRef.top__DOT__m_rdata = 0U;
    }
    vlSelfRef.top__DOT__gpr__DOT__wdata = ((2U & (IData)(vlSelfRef.top__DOT__wdata_sel))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.top__DOT__wdata_sel))
                                                ? vlSelfRef.top__DOT__exu__DOT__imm
                                                : ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pc_state))
                                            : ((1U 
                                                & (IData)(vlSelfRef.top__DOT__wdata_sel))
                                                ? vlSelfRef.top__DOT__m_rdata
                                                : vlSelfRef.top__DOT__exu__DOT__alu_result));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->top__DOT__pc_state = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2618292479826098527ull);
    vlSelf->top__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5136261650506720916ull);
    vlSelf->top__DOT__op_alu = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4898720218932402610ull);
    vlSelf->top__DOT__alu_src2_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9811209623396773591ull);
    vlSelf->top__DOT__wdata_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2300047134189955685ull);
    vlSelf->top__DOT__m_ren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15726302512674487646ull);
    vlSelf->top__DOT__m_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3429279889940526899ull);
    vlSelf->top__DOT__m_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8222423283187059505ull);
    vlSelf->top__DOT__wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5718604826377190525ull);
    vlSelf->top__DOT__jump_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9410013446802330500ull);
    vlSelf->top__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12275060777207994323ull);
    vlSelf->top__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16962670634133904117ull);
    vlSelf->top__DOT__m_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3076024841737623020ull);
    vlSelf->top__DOT__m_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8316344338289289258ull);
    vlSelf->top__DOT__ifu__DOT__pc_nextstate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6645704826758884510ull);
    vlSelf->top__DOT__exu__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7967900723359521494ull);
    vlSelf->top__DOT__exu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15971599061084172445ull);
    vlSelf->top__DOT__mem__DOT__len = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15839836298671303038ull);
    vlSelf->top__DOT__gpr__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8676071283357896692ull);
    vlSelf->top__DOT__gpr__DOT__reg_wen = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 7729773693642369602ull);
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4 = 0;
    vlSelf->top__DOT__gpr__DOT__dec1__DOT__pout = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13981138319319265729ull);
    VL_SCOPED_RAND_RESET_W(576, vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut, __VscopeHash, 12371191369727509886ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[__Vi0] = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 110103076462908546ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14629444279169968567ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7452030877048380920ull);
    }
    vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10363278693182771931ull);
    vlSelf->top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5444249245726215426ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[__Vi0] = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 8392032766401558298ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18327451304198747733ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8126923731262374855ull);
    }
    vlSelf->top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16825501544512604164ull);
    vlSelf->top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6208343543829806059ull);
    vlSelf->__Vfunc_pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_pmem_read__2__Vfuncout = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_6 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_8 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_9 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_10 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_11 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
