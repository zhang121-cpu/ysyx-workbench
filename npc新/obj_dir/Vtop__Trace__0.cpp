// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<16>/*511:0*/ __Vtemp_14;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 0, vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__key_list);
        Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 16, vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__key_list);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__instruction),32);
        bufp->chgCData(oldp+33,((0x0000001fU & (vlSelfRef.top__DOT__instruction 
                                                >> 7U))),5);
        bufp->chgCData(oldp+34,((0x0000001fU & (vlSelfRef.top__DOT__instruction 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+35,((0x0000001fU & (vlSelfRef.top__DOT__instruction 
                                                >> 0x00000014U))),5);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__exu__DOT__imm),32);
        bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__op_alu),4);
        bufp->chgBit(oldp+38,(vlSelfRef.top__DOT__alu_src2_sel));
        bufp->chgCData(oldp+39,(vlSelfRef.top__DOT__wdata_sel),2);
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__m_ren));
        bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__m_wen));
        bufp->chgCData(oldp+42,(vlSelfRef.top__DOT__m_size),2);
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__wen));
        bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__jump_en));
        bufp->chgBit(oldp+45,((0x00100073U == vlSelfRef.top__DOT__instruction)));
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__rdata1),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__rdata2),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__exu__DOT__alu_result),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__m_addr),32);
        bufp->chgIData(oldp+50,((vlSelfRef.top__DOT__rdata2 
                                 & (- (IData)((IData)(vlSelfRef.top__DOT__m_wen))))),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__m_rdata),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__gpr__DOT__wdata),32);
        bufp->chgIData(oldp+53,(((IData)(vlSelfRef.top__DOT__alu_src2_sel)
                                  ? vlSelfRef.top__DOT__exu__DOT__imm
                                  : vlSelfRef.top__DOT__rdata2)),32);
        bufp->chgSData(oldp+54,((0x00007fffU & ((IData)(vlSelfRef.top__DOT__gpr__DOT__dec1__DOT__pout) 
                                                >> 1U))),15);
        bufp->chgSData(oldp+55,(vlSelfRef.top__DOT__gpr__DOT__reg_wen),15);
        bufp->chgBit(oldp+56,(((~ (vlSelfRef.top__DOT__instruction 
                                   >> 7U)) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11))));
        bufp->chgCData(oldp+57,((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                                >> 7U))),4);
        bufp->chgSData(oldp+58,(vlSelfRef.top__DOT__gpr__DOT__dec1__DOT__pout),16);
        bufp->chgCData(oldp+59,(((((2U & ((~ (vlSelfRef.top__DOT__instruction 
                                              >> 0x0000000aU)) 
                                          << 1U)) | 
                                   (1U & (~ (vlSelfRef.top__DOT__instruction 
                                             >> 9U)))) 
                                  << 2U) | ((2U & (
                                                   (~ 
                                                    (vlSelfRef.top__DOT__instruction 
                                                     >> 8U)) 
                                                   << 1U)) 
                                            | (1U & 
                                               (~ (vlSelfRef.top__DOT__instruction 
                                                   >> 7U)))))),4);
        bufp->chgCData(oldp+60,((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                                >> 0x0000000fU))),4);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+63,((0x0000000fU & (vlSelfRef.top__DOT__instruction 
                                                >> 0x00000014U))),4);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+65,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+66,((1U & (IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen))));
        bufp->chgBit(oldp+67,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 9U))));
        bufp->chgBit(oldp+68,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 0x0000000aU))));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 0x0000000bU))));
        bufp->chgBit(oldp+70,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 0x0000000cU))));
        bufp->chgBit(oldp+71,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 0x0000000dU))));
        bufp->chgBit(oldp+72,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 0x0000000eU))));
        bufp->chgBit(oldp+73,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 1U))));
        bufp->chgBit(oldp+74,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 2U))));
        bufp->chgBit(oldp+75,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 3U))));
        bufp->chgBit(oldp+76,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 4U))));
        bufp->chgBit(oldp+77,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 5U))));
        bufp->chgBit(oldp+78,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 6U))));
        bufp->chgBit(oldp+79,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 7U))));
        bufp->chgBit(oldp+80,((1U & ((IData)(vlSelfRef.top__DOT__gpr__DOT__reg_wen) 
                                     >> 8U))));
        bufp->chgCData(oldp+81,((0x0000007fU & vlSelfRef.top__DOT__instruction)),7);
        bufp->chgCData(oldp+82,((7U & (vlSelfRef.top__DOT__instruction 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+83,((vlSelfRef.top__DOT__instruction 
                                 >> 0x00000019U)),7);
        bufp->chgIData(oldp+84,((((- (IData)((vlSelfRef.top__DOT__instruction 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 (vlSelfRef.top__DOT__instruction 
                                  >> 0x00000014U))),32);
        bufp->chgIData(oldp+85,((((- (IData)((vlSelfRef.top__DOT__instruction 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000fe0U & (vlSelfRef.top__DOT__instruction 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.top__DOT__instruction 
                                      >> 7U))))),32);
        bufp->chgIData(oldp+86,((((- (IData)((vlSelfRef.top__DOT__instruction 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000800U & (vlSelfRef.top__DOT__instruction 
                                                  << 4U)) 
                                  | ((0x000007e0U & 
                                      (vlSelfRef.top__DOT__instruction 
                                       >> 0x00000014U)) 
                                     | (0x0000001eU 
                                        & (vlSelfRef.top__DOT__instruction 
                                           >> 7U)))))),32);
        bufp->chgIData(oldp+87,((0xfffff000U & vlSelfRef.top__DOT__instruction)),32);
        bufp->chgIData(oldp+88,((((- (IData)((vlSelfRef.top__DOT__instruction 
                                              >> 0x0000001fU))) 
                                  << 0x00000014U) | 
                                 ((((0x000001feU & 
                                     (vlSelfRef.top__DOT__instruction 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.top__DOT__instruction 
                                             >> 0x00000014U))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.top__DOT__instruction 
                                      >> 0x00000014U))))),32);
        bufp->chgIData(oldp+89,(((IData)(vlSelfRef.top__DOT__jump_en)
                                  ? (0xfffffffeU & vlSelfRef.top__DOT__exu__DOT__alu_result)
                                  : ((IData)(4U) + vlSelfRef.top__DOT__pc_state))),32);
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__mem__DOT__len),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+91,(vlSelfRef.top__DOT__pc_state),32);
        bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4),32);
        __Vtemp_14[0U] = 0U;
        __Vtemp_14[1U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4;
        __Vtemp_14[2U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4;
        __Vtemp_14[3U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4;
        __Vtemp_14[4U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4;
        __Vtemp_14[5U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4;
        __Vtemp_14[6U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4;
        __Vtemp_14[7U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4;
        __Vtemp_14[8U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4;
        __Vtemp_14[9U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4;
        __Vtemp_14[10U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg10____pinNumber4;
        __Vtemp_14[11U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4;
        __Vtemp_14[12U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4;
        __Vtemp_14[13U] = vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4;
        __Vtemp_14[14U] = (IData)((((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4))));
        __Vtemp_14[15U] = (IData)(((((QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4))) 
                                   >> 0x00000020U));
        bufp->chgWData(oldp+93,(__Vtemp_14),512);
        bufp->chgWData(oldp+109,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__lut),576);
        bufp->chgQData(oldp+127,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[15]),36);
        bufp->chgQData(oldp+129,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[14]),36);
        bufp->chgQData(oldp+131,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[13]),36);
        bufp->chgQData(oldp+133,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[12]),36);
        bufp->chgQData(oldp+135,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[11]),36);
        bufp->chgQData(oldp+137,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[10]),36);
        bufp->chgQData(oldp+139,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[9]),36);
        bufp->chgQData(oldp+141,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[8]),36);
        bufp->chgQData(oldp+143,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[7]),36);
        bufp->chgQData(oldp+145,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[6]),36);
        bufp->chgQData(oldp+147,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[5]),36);
        bufp->chgQData(oldp+149,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[4]),36);
        bufp->chgQData(oldp+151,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[3]),36);
        bufp->chgQData(oldp+153,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[2]),36);
        bufp->chgQData(oldp+155,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgQData(oldp+157,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgIData(oldp+159,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[15]),32);
        bufp->chgIData(oldp+160,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[14]),32);
        bufp->chgIData(oldp+161,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[13]),32);
        bufp->chgIData(oldp+162,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[12]),32);
        bufp->chgIData(oldp+163,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[11]),32);
        bufp->chgIData(oldp+164,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[10]),32);
        bufp->chgIData(oldp+165,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[9]),32);
        bufp->chgIData(oldp+166,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[8]),32);
        bufp->chgIData(oldp+167,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[7]),32);
        bufp->chgIData(oldp+168,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[6]),32);
        bufp->chgIData(oldp+169,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[5]),32);
        bufp->chgIData(oldp+170,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+171,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+172,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+173,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+174,(vlSelfRef.top__DOT__gpr__DOT__mux1__DOT__i0__DOT__i0__DOT__data_list[0]),32);
        bufp->chgQData(oldp+175,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[15]),36);
        bufp->chgQData(oldp+177,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[14]),36);
        bufp->chgQData(oldp+179,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[13]),36);
        bufp->chgQData(oldp+181,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[12]),36);
        bufp->chgQData(oldp+183,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[11]),36);
        bufp->chgQData(oldp+185,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[10]),36);
        bufp->chgQData(oldp+187,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[9]),36);
        bufp->chgQData(oldp+189,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[8]),36);
        bufp->chgQData(oldp+191,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[7]),36);
        bufp->chgQData(oldp+193,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[6]),36);
        bufp->chgQData(oldp+195,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[5]),36);
        bufp->chgQData(oldp+197,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[4]),36);
        bufp->chgQData(oldp+199,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[3]),36);
        bufp->chgQData(oldp+201,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[2]),36);
        bufp->chgQData(oldp+203,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgQData(oldp+205,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgIData(oldp+207,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[15]),32);
        bufp->chgIData(oldp+208,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[14]),32);
        bufp->chgIData(oldp+209,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[13]),32);
        bufp->chgIData(oldp+210,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[12]),32);
        bufp->chgIData(oldp+211,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[11]),32);
        bufp->chgIData(oldp+212,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[10]),32);
        bufp->chgIData(oldp+213,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[9]),32);
        bufp->chgIData(oldp+214,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[8]),32);
        bufp->chgIData(oldp+215,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[7]),32);
        bufp->chgIData(oldp+216,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[6]),32);
        bufp->chgIData(oldp+217,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[5]),32);
        bufp->chgIData(oldp+218,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+219,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+220,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+221,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+222,(vlSelfRef.top__DOT__gpr__DOT__mux2__DOT__i0__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+223,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg1____pinNumber4),32);
        bufp->chgIData(oldp+224,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg11____pinNumber4),32);
        bufp->chgIData(oldp+225,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg12____pinNumber4),32);
        bufp->chgIData(oldp+226,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg13____pinNumber4),32);
        bufp->chgIData(oldp+227,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg14____pinNumber4),32);
        bufp->chgIData(oldp+228,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg15____pinNumber4),32);
        bufp->chgIData(oldp+229,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg2____pinNumber4),32);
        bufp->chgIData(oldp+230,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg3____pinNumber4),32);
        bufp->chgIData(oldp+231,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg4____pinNumber4),32);
        bufp->chgIData(oldp+232,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg5____pinNumber4),32);
        bufp->chgIData(oldp+233,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg6____pinNumber4),32);
        bufp->chgIData(oldp+234,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg7____pinNumber4),32);
        bufp->chgIData(oldp+235,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg8____pinNumber4),32);
        bufp->chgIData(oldp+236,(vlSelfRef.top__DOT__gpr__DOT____Vcellout__reg9____pinNumber4),32);
    }
    bufp->chgBit(oldp+237,(vlSelfRef.clk));
    bufp->chgBit(oldp+238,(vlSelfRef.rst));
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),4);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),4);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),4);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),4);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),4);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),4);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),4);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),4);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),4);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),4);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),4);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),4);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),4);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),4);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),4);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),4);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
