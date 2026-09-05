// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__instruction = 0U;
    } else {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__pc_state, 4U, vlSelfRef.__Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_pmem_read__1__Vfuncout;
    }
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024unit____Vdpiimwrap_pmem_rst_TOP____024unit();
void Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ len);
void Vtop___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit(IData/*31:0*/ a0);

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        Vtop___024unit____Vdpiimwrap_pmem_rst_TOP____024unit();
    } else if (vlSelfRef.top__DOT__m_wen) {
        Vtop___024unit____Vdpiimwrap_pmem_write_TOP____024unit(vlSelfRef.top__DOT__m_addr, 
                                                               (vlSelfRef.top__DOT__rdata2 
                                                                & (- (IData)((IData)(vlSelfRef.top__DOT__m_wen)))), vlSelfRef.top__DOT__mem__DOT__len);
    }
    if ((0x00100073U == vlSelfRef.top__DOT__instruction)) {
        Vtop___024unit____Vdpiimwrap_ebreak_handler_TOP____024unit(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4);
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4 = 0U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4 = 0U;
        vlSelfRef.top__DOT__pc_state = 0x80000000U;
        vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 = 0U;
    } else {
        if ((2U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((4U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((8U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000010U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000040U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000080U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000100U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000400U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00000800U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00001000U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00002000U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((1U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        if ((0x00004000U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
        vlSelfRef.top__DOT__pc_state = vlSelfRef.top__DOT__ifu__DOT__pc_nextstate;
        if ((0x00000200U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))) {
            vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4 
                = vlSelfRef.top__DOT__gpr__DOT__wdata;
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__instruction = 0U;
    } else {
        Vtop___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelfRef.top__DOT__pc_state, 4U, vlSelfRef.__Vfunc_pmem_read__1__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_pmem_read__1__Vfuncout;
    }
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[13U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[13U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[12U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[12U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[11U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[11U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[10U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[10U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[9U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[9U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[8U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[7U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[6U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[4U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[14U] 
        = (0x0000000100000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[14U] 
        = (0x0000000100000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[14U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[14U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[0U] 
        = (0x0000000f00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[0U] 
        = (0x0000000f00000000ULL | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)));
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
    vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[5U] 
        = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/top.v", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
