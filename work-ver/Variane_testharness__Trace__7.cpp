// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Variane_testharness__Syms.h"


void Variane_testharness::traceChgSub7(void* userp, VerilatedVcd* tracep) {
    Variane_testharness__Syms* __restrict vlSymsp = static_cast<Variane_testharness__Syms*>(userp);
    Variane_testharness* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 30930);
    if (false && oldp) {}  // Prevent unused
    // Variables
    // Begin mtask footprint all: 
    WData/*127:0*/ __Vtemp22329[4];
    WData/*127:0*/ __Vtemp22330[4];
    WData/*127:0*/ __Vtemp22333[4];
    WData/*127:0*/ __Vtemp22334[4];
    WData/*127:0*/ __Vtemp22336[4];
    WData/*127:0*/ __Vtemp22337[4];
    WData/*127:0*/ __Vtemp22338[4];
    WData/*127:0*/ __Vtemp22339[4];
    WData/*511:0*/ __Vtemp22340[16];
    WData/*511:0*/ __Vtemp22341[16];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgCData(oldp+0,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Crtl_cnt_S),6);
            tracep->chgBit(oldp+1,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Start_dly_S));
            tracep->chgBit(oldp+2,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Final_state_S));
            tracep->chgBit(oldp+3,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))));
            tracep->chgCData(oldp+4,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),2);
            tracep->chgCData(oldp+5,((7U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),3);
            tracep->chgCData(oldp+6,((0xfU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),4);
            tracep->chgCData(oldp+7,((0x1fU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),5);
            tracep->chgCData(oldp+8,((0x3fU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),6);
            tracep->chgCData(oldp+9,((0x7fU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),7);
            tracep->chgCData(oldp+10,((0xffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),8);
            tracep->chgSData(oldp+11,((0x1ffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),9);
            tracep->chgSData(oldp+12,((0x3ffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),10);
            tracep->chgSData(oldp+13,((0x7ffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),11);
            tracep->chgSData(oldp+14,((0xfffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),12);
            tracep->chgSData(oldp+15,((0x1fffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),13);
            tracep->chgSData(oldp+16,((0x3fffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),14);
            tracep->chgSData(oldp+17,((0x7fffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),15);
            tracep->chgSData(oldp+18,((0xffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),16);
            tracep->chgIData(oldp+19,((0x1ffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),17);
            tracep->chgIData(oldp+20,((0x3ffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),18);
            tracep->chgIData(oldp+21,((0x7ffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),19);
            tracep->chgIData(oldp+22,((0xfffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),20);
            tracep->chgIData(oldp+23,((0x1fffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),21);
            tracep->chgIData(oldp+24,((0x3fffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),22);
            tracep->chgIData(oldp+25,((0x7fffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),23);
            tracep->chgIData(oldp+26,((0xffffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),24);
            tracep->chgIData(oldp+27,((0x1ffffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),25);
            tracep->chgIData(oldp+28,((0x3ffffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),26);
            tracep->chgIData(oldp+29,((0x7ffffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),27);
            tracep->chgIData(oldp+30,((0xfffffffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),28);
            tracep->chgIData(oldp+31,((0x1fffffffU 
                                       & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),29);
            tracep->chgIData(oldp+32,((0x3fffffffU 
                                       & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),30);
            tracep->chgIData(oldp+33,((0x7fffffffU 
                                       & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP))),31);
            tracep->chgIData(oldp+34,((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),32);
            tracep->chgQData(oldp+35,((0x1ffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),33);
            tracep->chgQData(oldp+37,((0x3ffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),34);
            tracep->chgQData(oldp+39,((0x7ffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),35);
            tracep->chgQData(oldp+41,((0xfffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),36);
            tracep->chgQData(oldp+43,((0x1fffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),37);
            tracep->chgQData(oldp+45,((0x3fffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),38);
            tracep->chgQData(oldp+47,((0x7fffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),39);
            tracep->chgQData(oldp+49,((0xffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),40);
            tracep->chgQData(oldp+51,((0x1ffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),41);
            tracep->chgQData(oldp+53,((0x3ffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),42);
            tracep->chgQData(oldp+55,((0x7ffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),43);
            tracep->chgQData(oldp+57,((0xfffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),44);
            tracep->chgQData(oldp+59,((0x1fffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),45);
            tracep->chgQData(oldp+61,((0x3fffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),46);
            tracep->chgQData(oldp+63,((0x7fffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),47);
            tracep->chgQData(oldp+65,((0xffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),48);
            tracep->chgQData(oldp+67,((0x1ffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),49);
            tracep->chgQData(oldp+69,((0x3ffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),50);
            tracep->chgQData(oldp+71,((0x7ffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),51);
            tracep->chgQData(oldp+73,((0xfffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),52);
            tracep->chgQData(oldp+75,((0x1fffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),53);
            tracep->chgQData(oldp+77,((0x3fffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),54);
            tracep->chgQData(oldp+79,((0x7fffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),55);
            tracep->chgQData(oldp+81,((0xffffffffffffffULL 
                                       & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)),56);
            tracep->chgQData(oldp+83,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_start_dly_S)
                                        ? 0ULL : vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Partial_remainder_DP)),58);
            tracep->chgQData(oldp+85,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Q_sqrt_com_3),58);
            tracep->chgCData(oldp+87,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI[0]),2);
            tracep->chgCData(oldp+88,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI[1]),2);
            tracep->chgCData(oldp+89,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI[2]),2);
            tracep->chgCData(oldp+90,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI[3]),2);
            tracep->chgCData(oldp+91,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DO[0]),2);
            tracep->chgCData(oldp+92,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DO[1]),2);
            tracep->chgCData(oldp+93,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DO[2]),2);
            tracep->chgCData(oldp+94,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DO[3]),2);
            tracep->chgQData(oldp+95,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Denominator_se_format_DB),58);
            tracep->chgQData(oldp+97,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__First_iteration_cell_div_a_D),58);
            tracep->chgQData(oldp+99,((((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_S)
                                         ? 1U : (1U 
                                                 & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)))
                                        ? vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Denominator_se_format_DB
                                        : (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Mant_b_norm_DP 
                                           << 4U))),58);
            tracep->chgBit(oldp+101,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_S)
                                       ? 1U : (1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Quotient_DP)))));
            tracep->chgBit(oldp+102,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI[0]));
            tracep->chgBit(oldp+103,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI[1]));
            tracep->chgBit(oldp+104,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI[2]));
            tracep->chgBit(oldp+105,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI[3]));
            tracep->chgBit(oldp+106,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI[0]));
            tracep->chgBit(oldp+107,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI[1]));
            tracep->chgBit(oldp+108,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI[2]));
            tracep->chgBit(oldp+109,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI[3]));
            tracep->chgBit(oldp+110,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI[0]));
            tracep->chgBit(oldp+111,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI[1]));
            tracep->chgBit(oldp+112,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI[2]));
            tracep->chgBit(oldp+113,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI[3]));
            tracep->chgSData(oldp+114,((0x1fffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Start_dly_S)
                                                    ? 
                                                   ((((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_start_dly_S)
                                                       ? 
                                                      ((0x2000U 
                                                        & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                           << 2U)) 
                                                       | ((0x1000U 
                                                           & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                              << 1U)) 
                                                          | ((0x800U 
                                                              & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP)) 
                                                             | (0x7ffU 
                                                                & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                                   >> 1U)))))
                                                       : 
                                                      ((0x2000U 
                                                        & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                           << 2U)) 
                                                       | ((0x1000U 
                                                           & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                              << 1U)) 
                                                          | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP)))) 
                                                     + 
                                                     ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_start_dly_S)
                                                       ? 
                                                      (1U 
                                                       & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP))
                                                       : 
                                                      ((0x2000U 
                                                        & ((~ 
                                                            ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP) 
                                                             >> 0xbU)) 
                                                           << 0xdU)) 
                                                       | ((0x1000U 
                                                           & ((~ 
                                                               ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP) 
                                                                >> 0xbU)) 
                                                              << 0xcU)) 
                                                          | (0xfffU 
                                                             & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP))))))) 
                                                    + 
                                                    ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_S)
                                                      ? vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_BIAS_AONE
                                                      : vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_HALF_BIAS))
                                                    : (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP)))),13);
            tracep->chgSData(oldp+115,((0x1fffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_start_dly_S)
                                                    ? 
                                                   ((0x2000U 
                                                     & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                        << 2U)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                           << 1U)) 
                                                       | ((0x800U 
                                                           & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP)) 
                                                          | (0x7ffU 
                                                             & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                                >> 1U)))))
                                                    : 
                                                   ((0x2000U 
                                                     & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                        << 2U)) 
                                                    | ((0x1000U 
                                                        & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP) 
                                                           << 1U)) 
                                                       | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP)))))),13);
            tracep->chgSData(oldp+116,((0x1fffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_start_dly_S)
                                                    ? 
                                                   (1U 
                                                    & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_a_norm_DP))
                                                    : 
                                                   ((0x2000U 
                                                     & ((~ 
                                                         ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP) 
                                                          >> 0xbU)) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & ((~ 
                                                            ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP) 
                                                             >> 0xbU)) 
                                                           << 0xcU)) 
                                                       | (0xfffU 
                                                          & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Exp_b_norm_DP)))))))),13);
            tracep->chgSData(oldp+117,((0x1fffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_S)
                                                    ? vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_BIAS_AONE
                                                    : vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_HALF_BIAS))),13);
            tracep->chgIData(oldp+118,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_BIAS_AONE),32);
            tracep->chgIData(oldp+119,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__C_HALF_BIAS),32);
            tracep->chgBit(oldp+120,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI
                                     [0U]));
            tracep->chgBit(oldp+121,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI
                                     [0U]));
            tracep->chgBit(oldp+122,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                     [0U]));
            tracep->chgCData(oldp+123,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                       [0U]),2);
            tracep->chgCData(oldp+124,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT____Vcellout__genblk4__BRA__0__KET____DOT__iteration_div_sqrt__D_DO),2);
            tracep->chgBit(oldp+125,((1U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                             [0U] >> 1U) 
                                            | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                            [0U]))));
            tracep->chgBit(oldp+126,((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                      [0U] & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                               [0U] 
                                               >> 1U) 
                                              | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                              [0U]))));
            tracep->chgBit(oldp+127,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__genblk4__BRA__0__KET____DOT__iteration_div_sqrt__DOT__Cin_D));
            tracep->chgBit(oldp+128,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI
                                     [1U]));
            tracep->chgBit(oldp+129,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI
                                     [1U]));
            tracep->chgBit(oldp+130,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                     [1U]));
            tracep->chgCData(oldp+131,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                       [1U]),2);
            tracep->chgCData(oldp+132,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT____Vcellout__genblk4__BRA__1__KET____DOT__iteration_div_sqrt__D_DO),2);
            tracep->chgBit(oldp+133,((1U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                             [1U] >> 1U) 
                                            | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                            [1U]))));
            tracep->chgBit(oldp+134,((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                      [1U] & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                               [1U] 
                                               >> 1U) 
                                              | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                              [1U]))));
            tracep->chgBit(oldp+135,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__genblk4__BRA__1__KET____DOT__iteration_div_sqrt__DOT__Cin_D));
            tracep->chgBit(oldp+136,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_enable_SI
                                     [2U]));
            tracep->chgBit(oldp+137,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Div_start_dly_SI
                                     [2U]));
            tracep->chgBit(oldp+138,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                     [2U]));
            tracep->chgCData(oldp+139,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                       [2U]),2);
            tracep->chgCData(oldp+140,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT____Vcellout__genblk4__BRA__2__KET____DOT__iteration_div_sqrt__D_DO),2);
            tracep->chgBit(oldp+141,((1U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                             [2U] >> 1U) 
                                            | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                            [2U]))));
            tracep->chgBit(oldp+142,((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_enable_SI
                                      [2U] & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                               [2U] 
                                               >> 1U) 
                                              | vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Sqrt_DI
                                              [2U]))));
            tracep->chgBit(oldp+143,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__genblk4__BRA__2__KET____DOT__iteration_div_sqrt__DOT__Cin_D));
            tracep->chgBit(oldp+144,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Sign_res_D));
            tracep->chgBit(oldp+145,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__NaN_a_SP)
                                       ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__SNaN_SP)
                                       : ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__NaN_b_SP)
                                           ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__SNaN_SP)
                                           : ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Inf_a_SP)
                                               ? (((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Inf_b_SP)) 
                                                  | ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Sqrt_enable_S) 
                                                     & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Sign_z_DP)))
                                               : ((~ 
                                                   ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                    & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Inf_b_SP))) 
                                                  & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_a_SP)
                                                      ? 
                                                     ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                      & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_b_SP))
                                                      : 
                                                     ((~ 
                                                       ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                        & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_b_SP))) 
                                                      & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Sign_z_DP) 
                                                         & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Sqrt_enable_S))))))))));
            tracep->chgBit(oldp+146,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Exp_OF_S));
            tracep->chgBit(oldp+147,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Exp_UF_S));
            tracep->chgBit(oldp+148,(((~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__NaN_a_SP)) 
                                      & ((~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__NaN_b_SP)) 
                                         & ((~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Inf_a_SP)) 
                                            & ((~ ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Inf_b_SP))) 
                                               & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_a_SP)
                                                   ? 
                                                  ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_b_SP))
                                                   : 
                                                  ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Div_enable_S) 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__preprocess_U0__DOT__Zero_b_SP)))))))));
            tracep->chgBit(oldp+149,(((0U != (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Precision_ctl_S)) 
                                      | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_rounded_S))));
            tracep->chgQData(oldp+150,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_res_norm_D),53);
            tracep->chgSData(oldp+152,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Exp_res_norm_D),11);
            tracep->chgSData(oldp+153,((0x1fffU & ((IData)(0x35U) 
                                                   + 
                                                   (0xfffU 
                                                    & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))),13);
            tracep->chgSData(oldp+154,((0x3ffU & ((IData)(0x18U) 
                                                  + 
                                                  (0x1ffU 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))),10);
            tracep->chgCData(oldp+155,((0x7fU & ((IData)(0xbU) 
                                                 + 
                                                 (0x3fU 
                                                  & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))),7);
            tracep->chgSData(oldp+156,((0x3ffU & ((IData)(8U) 
                                                  + 
                                                  (0x1ffU 
                                                   & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))),10);
            tracep->chgSData(oldp+157,((0x1fffU & ((IData)(2U) 
                                                   + 
                                                   (~ 
                                                    VL_EXTENDS_II(13,13, (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP)))))),13);
            __Vtemp22329[0U] = 0U;
            __Vtemp22329[1U] = (0xffe00000U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D) 
                                               << 0x15U));
            __Vtemp22329[2U] = ((0x1fffffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D) 
                                              >> 0xbU)) 
                                | (0xffe00000U & ((IData)(
                                                          (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D 
                                                           >> 0x20U)) 
                                                  << 0x15U)));
            __Vtemp22329[3U] = (0x1fffffU & ((IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D 
                                                      >> 0x20U)) 
                                             >> 0xbU));
            VL_SHIFTR_WWI(110,110,13, __Vtemp22330, __Vtemp22329, 
                          (0x1fffU & ((IData)(2U) + 
                                      (~ VL_EXTENDS_II(13,13, (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))));
            tracep->chgQData(oldp+158,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            (0x3fffU 
                                                             & __Vtemp22330[3U]))) 
                                            << 0x27U) 
                                           | (((QData)((IData)(
                                                               __Vtemp22330[2U])) 
                                               << 7U) 
                                              | ((QData)((IData)(
                                                                 __Vtemp22330[1U])) 
                                                 >> 0x19U))))),53);
            __Vtemp22333[0U] = 0U;
            __Vtemp22333[1U] = (0xffe00000U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D) 
                                               << 0x15U));
            __Vtemp22333[2U] = ((0x1fffffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D) 
                                              >> 0xbU)) 
                                | (0xffe00000U & ((IData)(
                                                          (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D 
                                                           >> 0x20U)) 
                                                  << 0x15U)));
            __Vtemp22333[3U] = (0x1fffffU & ((IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__Mant_z_D 
                                                      >> 0x20U)) 
                                             >> 0xbU));
            VL_SHIFTR_WWI(110,110,13, __Vtemp22334, __Vtemp22333, 
                          (0x1fffU & ((IData)(2U) + 
                                      (~ VL_EXTENDS_II(13,13, (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP))))));
            tracep->chgQData(oldp+160,((0x1ffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            __Vtemp22334[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             __Vtemp22334[0U]))))),57);
            tracep->chgSData(oldp+162,((0x1fffU & (
                                                   VL_EXTENDS_II(13,13, (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Exp_result_prenorm_DP)) 
                                                   - (IData)(1U)))),13);
            tracep->chgCData(oldp+163,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_lower_D),2);
            tracep->chgBit(oldp+164,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_sticky_bit_D));
            tracep->chgQData(oldp+165,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_forround_D),57);
            tracep->chgQData(oldp+167,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upper_D),53);
            tracep->chgQData(oldp+169,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D),54);
            tracep->chgBit(oldp+171,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_roundUp_S));
            tracep->chgBit(oldp+172,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_rounded_S));
            tracep->chgBit(oldp+173,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D 
                                                    >> 0x35U)))));
            tracep->chgQData(oldp+174,((((QData)((IData)(
                                                         ((3U 
                                                           == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Format_sel_S)) 
                                                          & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_roundUp_S)))) 
                                         << 0x2dU) 
                                        | (((QData)((IData)(
                                                            ((2U 
                                                              == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Format_sel_S)) 
                                                             & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_roundUp_S)))) 
                                            << 0x2aU) 
                                           | (QData)((IData)(
                                                             ((((0U 
                                                                 == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Format_sel_S)) 
                                                                & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_roundUp_S)) 
                                                               << 0x1dU) 
                                                              | ((1U 
                                                                  == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__nrbd_nrsc_U0__DOT__control_U0__DOT__Format_sel_S)) 
                                                                 & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_roundUp_S)))))))),53);
            tracep->chgQData(oldp+176,((0xfffffffffffffULL 
                                        & ((1U & (IData)(
                                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D 
                                                          >> 0x35U)))
                                            ? (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D 
                                               >> 1U)
                                            : vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D))),52);
            tracep->chgSData(oldp+178,((0x7ffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Exp_res_norm_D) 
                                                  + 
                                                  (1U 
                                                   & (IData)(
                                                             (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_upperRounded_D 
                                                              >> 0x35U)))))),11);
            tracep->chgQData(oldp+179,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Mant_before_format_ctl_D),52);
            tracep->chgSData(oldp+181,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__1__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_fpnew_divsqrt_multi__DOT__i_divsqrt_lei__DOT__fpu_norm_U0__DOT__Exp_before_format_ctl_D),11);
            tracep->chgCData(oldp+182,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q),3);
            tracep->chgBit(oldp+183,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__0__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgBit(oldp+184,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__0__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q))));
            tracep->chgBit(oldp+185,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__0__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgBit(oldp+186,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__0__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgBit(oldp+187,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__1__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgBit(oldp+188,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__1__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q))));
            tracep->chgBit(oldp+189,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__1__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgBit(oldp+190,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__2__KET____DOT__i_opgroup_block__DOT__gen_parallel_slices__BRA__1__KET____DOT__active_format__DOT__i_fmt_slice__DOT__gen_num_lanes__BRA__0__KET____DOT__active_lane__DOT__lane_instance__DOT__i_noncomp__DOT__inp_pipe_aux_q) 
                                            >> 1U))));
            tracep->chgCData(oldp+191,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__3__KET____DOT__i_opgroup_block__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q),3);
            tracep->chgCData(oldp+192,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__fpu_gen__DOT__fpu_i__DOT__fpu_gen__DOT__i_fpnew_bulk__DOT__gen_operation_groups__BRA__3__KET____DOT__i_opgroup_block__DOT__gen_merged_slice__DOT__i_multifmt_slice__DOT__target_regs__DOT__byp_pipe_valid_q),3);
            tracep->chgBit(oldp+193,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__commit_stage_i__DOT__instr_0_is_amo));
            tracep->chgBit(oldp+194,(((((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mprv) 
                                        & (8U == (0xfU 
                                                  & (IData)(
                                                            (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__satp_q 
                                                             >> 0x3cU))))) 
                                       & (3U != (3U 
                                                 & (IData)(
                                                           (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                            >> 0xbU))))) 
                                      | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__enable_translation_csr_ex))));
            tracep->chgBit(oldp+195,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mprv));
            tracep->chgBit(oldp+196,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x3fU)))));
            tracep->chgIData(oldp+197,((0x7ffffffU 
                                        & (IData)((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                   >> 0x24U)))),27);
            tracep->chgCData(oldp+198,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 0x22U)))),2);
            tracep->chgCData(oldp+199,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 0x20U)))),2);
            tracep->chgSData(oldp+200,((0x1ffU & (IData)(
                                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                          >> 0x17U)))),9);
            tracep->chgBit(oldp+201,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x16U)))));
            tracep->chgBit(oldp+202,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x15U)))));
            tracep->chgBit(oldp+203,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+204,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x13U)))));
            tracep->chgBit(oldp+205,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x12U)))));
            tracep->chgBit(oldp+206,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 0x11U)))));
            tracep->chgCData(oldp+207,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 0xfU)))),2);
            tracep->chgCData(oldp+208,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 0xdU)))),2);
            tracep->chgCData(oldp+209,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 0xbU)))),2);
            tracep->chgCData(oldp+210,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                      >> 9U)))),2);
            tracep->chgBit(oldp+211,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 8U)))));
            tracep->chgBit(oldp+212,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 7U)))));
            tracep->chgBit(oldp+213,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 6U)))));
            tracep->chgBit(oldp+214,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 5U)))));
            tracep->chgBit(oldp+215,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 4U)))));
            tracep->chgBit(oldp+216,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 3U)))));
            tracep->chgBit(oldp+217,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 2U)))));
            tracep->chgBit(oldp+218,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q 
                                                    >> 1U)))));
            tracep->chgBit(oldp+219,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q))));
            tracep->chgQData(oldp+220,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mstatus_q),64);
            tracep->chgCData(oldp+222,((0xfU & (IData)(
                                                       (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__satp_q 
                                                        >> 0x3cU)))),4);
            tracep->chgSData(oldp+223,((0xffffU & (IData)(
                                                          (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__satp_q 
                                                           >> 0x2cU)))),16);
            tracep->chgQData(oldp+224,((0xfffffffffffULL 
                                        & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__satp_q)),44);
            tracep->chgCData(oldp+226,((0xfU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                                >> 0x1cU))),4);
            tracep->chgSData(oldp+227,((0xfffU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                                  >> 0x10U))),12);
            tracep->chgBit(oldp+228,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xfU))));
            tracep->chgBit(oldp+229,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xeU))));
            tracep->chgBit(oldp+230,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xdU))));
            tracep->chgBit(oldp+231,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xcU))));
            tracep->chgBit(oldp+232,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xbU))));
            tracep->chgBit(oldp+233,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 0xaU))));
            tracep->chgBit(oldp+234,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 9U))));
            tracep->chgCData(oldp+235,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                              >> 6U))),3);
            tracep->chgBit(oldp+236,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 5U))));
            tracep->chgBit(oldp+237,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 4U))));
            tracep->chgBit(oldp+238,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 3U))));
            tracep->chgBit(oldp+239,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q 
                                            >> 2U))));
            tracep->chgCData(oldp+240,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcsr_q)),2);
            tracep->chgCData(oldp+241,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__csr_buffer_i__DOT__csr_reg_q) 
                                              >> 0xbU))),2);
            tracep->chgCData(oldp+242,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__csr_buffer_i__DOT__csr_reg_q) 
                                              >> 9U))),2);
            tracep->chgCData(oldp+243,((0xffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__ex_stage_i__DOT__csr_buffer_i__DOT__csr_reg_q) 
                                                 >> 1U))),8);
            tracep->chgCData(oldp+244,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__priv_lvl_q),2);
            tracep->chgBit(oldp+245,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mtvec_rst_load_q));
            tracep->chgQData(oldp+246,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dpc_q),64);
            tracep->chgQData(oldp+248,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dscratch0_q),64);
            tracep->chgQData(oldp+250,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dscratch1_q),64);
            tracep->chgQData(oldp+252,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mtvec_q),64);
            tracep->chgQData(oldp+254,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__medeleg_q),64);
            tracep->chgQData(oldp+256,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mideleg_q),64);
            tracep->chgQData(oldp+258,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mip_q),64);
            tracep->chgQData(oldp+260,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mie_q),64);
            tracep->chgQData(oldp+262,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mcounteren_q),64);
            tracep->chgQData(oldp+264,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mscratch_q),64);
            tracep->chgQData(oldp+266,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mepc_q),64);
            tracep->chgQData(oldp+268,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mcause_q),64);
            tracep->chgQData(oldp+270,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__mtval_q),64);
            tracep->chgQData(oldp+272,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__stvec_q),64);
            tracep->chgQData(oldp+274,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__scounteren_q),64);
            tracep->chgQData(oldp+276,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__sscratch_q),64);
            tracep->chgQData(oldp+278,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__sepc_q),64);
            tracep->chgQData(oldp+280,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__scause_q),64);
            tracep->chgQData(oldp+282,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__stval_q),64);
            tracep->chgQData(oldp+284,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__dcache_q),64);
            tracep->chgQData(oldp+286,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__icache_q),64);
            tracep->chgQData(oldp+288,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__cycle_q),64);
            tracep->chgQData(oldp+290,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__instret_q),64);
            tracep->chgIData(oldp+292,((0x1ffffU & 
                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__fcsr_q 
                                         >> 0xfU))),17);
            tracep->chgCData(oldp+293,((0x7fU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__fcsr_q 
                                                 >> 8U))),7);
            tracep->chgCData(oldp+294,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__fcsr_q 
                                              >> 5U))),3);
            tracep->chgCData(oldp+295,((0x1fU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__fcsr_q)),5);
            tracep->chgIData(oldp+296,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__csr_update__DOT__unnamedblk1__DOT__i),32);
            tracep->chgIData(oldp+297,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__csr_regfile_i__DOT__unnamedblk6__DOT__i),32);
            tracep->chgBit(oldp+298,((3U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_frontend__DOT__i_instr_queue__DOT__instr_queue_empty))));
            tracep->chgQData(oldp+299,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0U])))),64);
            tracep->chgQData(oldp+301,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[2U])))),64);
            tracep->chgQData(oldp+303,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[4U])))),64);
            tracep->chgQData(oldp+305,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[6U])))),64);
            tracep->chgQData(oldp+307,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[8U])))),64);
            tracep->chgQData(oldp+309,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xbU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xaU])))),64);
            tracep->chgQData(oldp+311,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xdU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xcU])))),64);
            tracep->chgQData(oldp+313,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xfU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0xeU])))),64);
            tracep->chgQData(oldp+315,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x11U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x10U])))),64);
            tracep->chgQData(oldp+317,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x13U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x12U])))),64);
            tracep->chgQData(oldp+319,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x15U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x14U])))),64);
            tracep->chgQData(oldp+321,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x17U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x16U])))),64);
            tracep->chgQData(oldp+323,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x19U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x18U])))),64);
            tracep->chgQData(oldp+325,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x1bU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counter_q[0x1aU])))),64);
            tracep->chgIData(oldp+327,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_perf_counters__DOT__perf_counters__DOT__unnamedblk1__DOT__i),32);
            tracep->chgBit(oldp+328,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__controller_i__DOT__fence_active_q));
            tracep->chgBit(oldp+329,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rtrn_vld_q));
            tracep->chgBit(oldp+330,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[4U] 
                                            >> 0x13U))));
            __Vtemp22336[0U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                             >> 0x13U));
            __Vtemp22336[1U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                             >> 0x13U));
            __Vtemp22336[2U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[3U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U] 
                                             >> 0x13U));
            __Vtemp22336[3U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[4U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[3U] 
                                             >> 0x13U));
            tracep->chgWData(oldp+331,(__Vtemp22336),128);
            tracep->chgBit(oldp+335,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                            >> 0x12U))));
            tracep->chgBit(oldp+336,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                            >> 0x11U))));
            tracep->chgSData(oldp+337,((0xfffU & ((
                                                   vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                                   << 0x1bU) 
                                                  | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                                     >> 5U)))),12);
            tracep->chgCData(oldp+338,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                               << 0x1eU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                                 >> 2U)))),3);
            tracep->chgCData(oldp+339,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U])),2);
            tracep->chgBit(oldp+340,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_vld_q));
            tracep->chgCData(oldp+341,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[4U] 
                                              >> 0x13U))),3);
            __Vtemp22337[0U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                             >> 0x13U));
            __Vtemp22337[1U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[2U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                             >> 0x13U));
            __Vtemp22337[2U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[3U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[2U] 
                                             >> 0x13U));
            __Vtemp22337[3U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[4U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[3U] 
                                             >> 0x13U));
            tracep->chgWData(oldp+342,(__Vtemp22337),128);
            tracep->chgBit(oldp+346,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                            >> 0x12U))));
            tracep->chgBit(oldp+347,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                            >> 0x11U))));
            tracep->chgSData(oldp+348,((0xfffU & ((
                                                   vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                                   << 0x1bU) 
                                                  | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                                     >> 5U)))),12);
            tracep->chgCData(oldp+349,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                               << 0x1eU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                                 >> 2U)))),3);
            tracep->chgCData(oldp+350,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U])),2);
            tracep->chgBit(oldp+351,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cache_en_d));
            tracep->chgBit(oldp+352,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cache_en_q));
            tracep->chgQData(oldp+353,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__vaddr_q),64);
            tracep->chgBit(oldp+355,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cmp_en_q));
            tracep->chgBit(oldp+356,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_q));
            tracep->chgCData(oldp+357,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__i_lfsr__DOT__lfsr_q))),2);
            tracep->chgCData(oldp+358,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__repl_way_oh_q),4);
            tracep->chgBit(oldp+359,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__inv_en));
            tracep->chgBit(oldp+360,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__inv_q));
            tracep->chgBit(oldp+361,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_en));
            tracep->chgBit(oldp+362,((0xffU == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_cnt_q))));
            tracep->chgCData(oldp+363,(((0xffU == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_cnt_q))
                                         ? 0U : (0xffU 
                                                 & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_en)
                                                     ? 
                                                    ((IData)(1U) 
                                                     + (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_cnt_q))
                                                     : (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_cnt_q))))),8);
            tracep->chgCData(oldp+364,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__flush_cnt_q),8);
            tracep->chgCData(oldp+365,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_offset_q),4);
            tracep->chgQData(oldp+366,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_tag_q),44);
            tracep->chgIData(oldp+368,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_sel[0U]),32);
            tracep->chgIData(oldp+369,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_sel[1U]),32);
            tracep->chgIData(oldp+370,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_sel[2U]),32);
            tracep->chgIData(oldp+371,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__cl_sel[3U]),32);
            tracep->chgCData(oldp+372,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__state_q),3);
            tracep->chgCData(oldp+373,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_cva6_icache__DOT__i_lfsr__DOT__lfsr_q),4);
            __Vtemp22338[0U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U] 
                                             >> 0x13U));
            __Vtemp22338[1U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U] 
                                             >> 0x13U));
            __Vtemp22338[2U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[3U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U] 
                                             >> 0x13U));
            __Vtemp22338[3U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[4U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[3U] 
                                             >> 0x13U));
            tracep->chgWData(oldp+374,(__Vtemp22338),128);
            tracep->chgQData(oldp+378,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U])) 
                                         << 0x2dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[1U])) 
                                            << 0xdU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[0U])) 
                                              >> 0x13U)))),64);
            tracep->chgQData(oldp+380,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[4U])) 
                                         << 0x2dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[3U])) 
                                            << 0xdU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_icache[2U])) 
                                              >> 0x13U)))),64);
            tracep->chgBit(oldp+382,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__enable_q));
            tracep->chgBit(oldp+383,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_cl_vld));
            tracep->chgBit(oldp+384,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                            >> 5U))));
            tracep->chgCData(oldp+385,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_cl_we),8);
            tracep->chgQData(oldp+386,((0xfffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                            << 0x21U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                               << 1U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                 >> 0x1fU))))),44);
            tracep->chgCData(oldp+388,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_cl_idx),8);
            tracep->chgCData(oldp+389,((0xfU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U] 
                                                 << 0xdU) 
                                                | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                   >> 0x13U)))),4);
            __Vtemp22339[0U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U] 
                                             >> 0x13U));
            __Vtemp22339[1U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[2U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U] 
                                             >> 0x13U));
            __Vtemp22339[2U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[3U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[2U] 
                                             >> 0x13U));
            __Vtemp22339[3U] = ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[4U] 
                                 << 0xdU) | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[3U] 
                                             >> 0x13U));
            tracep->chgWData(oldp+390,(__Vtemp22339),128);
            tracep->chgSData(oldp+394,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__cl_write_en)
                                         ? 0xffffU : 0U)),16);
            tracep->chgCData(oldp+395,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits),8);
            tracep->chgCData(oldp+396,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_req),8);
            tracep->chgCData(oldp+397,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wr_paddr 
                                                         >> 4U)))),8);
            tracep->chgCData(oldp+398,((0xfU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wr_paddr))),4);
            tracep->chgQData(oldp+399,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_data),64);
            tracep->chgCData(oldp+401,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_data_be),8);
            tracep->chgCData(oldp+402,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_req),3);
            tracep->chgCData(oldp+403,((0xffU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_vld_bits)),8);
            tracep->chgCData(oldp+404,((0xffU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_vld_bits 
                                                 >> 8U))),8);
            tracep->chgCData(oldp+405,((0xffU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_vld_bits 
                                                 >> 0x10U))),8);
            tracep->chgCData(oldp+406,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_rtrn_vld),3);
            tracep->chgCData(oldp+407,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U])),2);
            tracep->chgQData(oldp+408,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[0U]))))),56);
            tracep->chgQData(oldp+410,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[3U])) 
                                            << 0x28U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[2U])) 
                                               << 8U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[1U])) 
                                                 >> 0x18U))))),56);
            tracep->chgQData(oldp+412,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[5U])) 
                                            << 0x30U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[4U])) 
                                               << 0x10U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[3U])) 
                                                 >> 0x10U))))),56);
            tracep->chgQData(oldp+414,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[6U])) 
                                            << 0x18U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__tx_paddr_o[5U])) 
                                              >> 8U)))),56);
            tracep->chgCData(oldp+416,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__tx_vld),4);
            tracep->chgQData(oldp+417,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U])) 
                                            << 0x3fU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[4U])) 
                                               << 0x1fU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[3U])) 
                                                 >> 1U))))),53);
            tracep->chgQData(oldp+419,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[3U])) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[2U])) 
                                            << 0x1fU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[1U])) 
                                              >> 1U)))),64);
            tracep->chgCData(oldp+421,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[1U] 
                                                  << 7U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0U] 
                                                    >> 0x19U)))),8);
            tracep->chgCData(oldp+422,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[1U] 
                                                  << 0xfU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0U] 
                                                    >> 0x11U)))),8);
            tracep->chgCData(oldp+423,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[1U] 
                                                  << 0x17U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0U] 
                                                    >> 9U)))),8);
            tracep->chgBit(oldp+424,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0U] 
                                            >> 8U))));
            tracep->chgCData(oldp+425,((0xffU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0U])),8);
            tracep->chgQData(oldp+426,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[9U])) 
                                            << 0x29U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[8U])) 
                                               << 9U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[7U])) 
                                                 >> 0x17U))))),53);
            tracep->chgQData(oldp+428,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[7U])) 
                                         << 0x29U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[6U])) 
                                            << 9U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U])) 
                                              >> 0x17U)))),64);
            tracep->chgCData(oldp+430,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[6U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U] 
                                                    >> 0xfU)))),8);
            tracep->chgCData(oldp+431,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[6U] 
                                                  << 0x19U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U] 
                                                    >> 7U)))),8);
            tracep->chgCData(oldp+432,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U] 
                                                  << 1U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[4U] 
                                                    >> 0x1fU)))),8);
            tracep->chgBit(oldp+433,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[4U] 
                                            >> 0x1eU))));
            tracep->chgCData(oldp+434,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[5U] 
                                                  << 0xaU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[4U] 
                                                    >> 0x16U)))),8);
            tracep->chgQData(oldp+435,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU])) 
                                            << 0x33U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xdU])) 
                                               << 0x13U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xcU])) 
                                                 >> 0xdU))))),53);
            tracep->chgQData(oldp+437,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xcU])) 
                                         << 0x33U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xbU])) 
                                            << 0x13U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xaU])) 
                                              >> 0xdU)))),64);
            tracep->chgCData(oldp+439,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xbU] 
                                                  << 0x1bU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xaU] 
                                                    >> 5U)))),8);
            tracep->chgCData(oldp+440,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xaU] 
                                                  << 3U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[9U] 
                                                    >> 0x1dU)))),8);
            tracep->chgCData(oldp+441,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xaU] 
                                                  << 0xbU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[9U] 
                                                    >> 0x15U)))),8);
            tracep->chgBit(oldp+442,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[9U] 
                                            >> 0x14U))));
            tracep->chgCData(oldp+443,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xaU] 
                                                  << 0x14U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[9U] 
                                                    >> 0xcU)))),8);
            tracep->chgQData(oldp+444,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x12U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x11U])) 
                                                 >> 3U))))),53);
            tracep->chgQData(oldp+446,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x11U])) 
                                         << 0x3dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x10U])) 
                                            << 0x1dU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xfU])) 
                                              >> 3U)))),64);
            tracep->chgCData(oldp+448,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xfU] 
                                                  << 5U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU] 
                                                    >> 0x1bU)))),8);
            tracep->chgCData(oldp+449,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xfU] 
                                                  << 0xdU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU] 
                                                    >> 0x13U)))),8);
            tracep->chgCData(oldp+450,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xfU] 
                                                  << 0x15U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU] 
                                                    >> 0xbU)))),8);
            tracep->chgBit(oldp+451,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU] 
                                            >> 0xaU))));
            tracep->chgCData(oldp+452,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xfU] 
                                                  << 0x1eU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0xeU] 
                                                    >> 2U)))),8);
            tracep->chgQData(oldp+453,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x17U])) 
                                            << 0x27U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x16U])) 
                                               << 7U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x15U])) 
                                                 >> 0x19U))))),53);
            tracep->chgQData(oldp+455,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x15U])) 
                                         << 0x27U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x14U])) 
                                            << 7U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U])) 
                                              >> 0x19U)))),64);
            tracep->chgCData(oldp+457,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x14U] 
                                                  << 0xfU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U] 
                                                    >> 0x11U)))),8);
            tracep->chgCData(oldp+458,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x14U] 
                                                  << 0x17U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U] 
                                                    >> 9U)))),8);
            tracep->chgCData(oldp+459,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x14U] 
                                                  << 0x1fU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U] 
                                                    >> 1U)))),8);
            tracep->chgBit(oldp+460,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U])));
            tracep->chgCData(oldp+461,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x13U] 
                                                  << 8U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x12U] 
                                                    >> 0x18U)))),8);
            tracep->chgQData(oldp+462,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU])) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1bU])) 
                                               << 0x11U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1aU])) 
                                                 >> 0xfU))))),53);
            tracep->chgQData(oldp+464,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1aU])) 
                                         << 0x31U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x19U])) 
                                            << 0x11U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x18U])) 
                                              >> 0xfU)))),64);
            tracep->chgCData(oldp+466,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x19U] 
                                                  << 0x19U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x18U] 
                                                    >> 7U)))),8);
            tracep->chgCData(oldp+467,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x18U] 
                                                  << 1U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x17U] 
                                                    >> 0x1fU)))),8);
            tracep->chgCData(oldp+468,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x18U] 
                                                  << 9U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x17U] 
                                                    >> 0x17U)))),8);
            tracep->chgBit(oldp+469,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x17U] 
                                            >> 0x16U))));
            tracep->chgCData(oldp+470,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x18U] 
                                                  << 0x12U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x17U] 
                                                    >> 0xeU)))),8);
            tracep->chgQData(oldp+471,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U])) 
                                            << 0x3bU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x20U])) 
                                               << 0x1bU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1fU])) 
                                                 >> 5U))))),53);
            tracep->chgQData(oldp+473,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1fU])) 
                                         << 0x3bU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1eU])) 
                                            << 0x1bU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1dU])) 
                                              >> 5U)))),64);
            tracep->chgCData(oldp+475,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1dU] 
                                                  << 3U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU] 
                                                    >> 0x1dU)))),8);
            tracep->chgCData(oldp+476,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1dU] 
                                                  << 0xbU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU] 
                                                    >> 0x15U)))),8);
            tracep->chgCData(oldp+477,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1dU] 
                                                  << 0x13U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU] 
                                                    >> 0xdU)))),8);
            tracep->chgBit(oldp+478,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU] 
                                            >> 0xcU))));
            tracep->chgCData(oldp+479,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1dU] 
                                                  << 0x1cU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x1cU] 
                                                    >> 4U)))),8);
            tracep->chgQData(oldp+480,((0x1fffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x25U])) 
                                            << 0x25U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x24U])) 
                                               << 5U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x23U])) 
                                                 >> 0x1bU))))),53);
            tracep->chgQData(oldp+482,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x23U])) 
                                         << 0x25U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x22U])) 
                                            << 5U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U])) 
                                              >> 0x1bU)))),64);
            tracep->chgCData(oldp+484,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x22U] 
                                                  << 0xdU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U] 
                                                    >> 0x13U)))),8);
            tracep->chgCData(oldp+485,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x22U] 
                                                  << 0x15U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U] 
                                                    >> 0xbU)))),8);
            tracep->chgCData(oldp+486,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x22U] 
                                                  << 0x1dU) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U] 
                                                    >> 3U)))),8);
            tracep->chgBit(oldp+487,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U] 
                                            >> 2U))));
            tracep->chgCData(oldp+488,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x21U] 
                                                  << 6U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wbuffer_q[0x20U] 
                                                    >> 0x1aU)))),8);
            tracep->chgCData(oldp+489,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__state_q),3);
            tracep->chgQData(oldp+490,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                            << 0x2dU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                               << 0xdU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                 >> 0x13U))))),56);
            tracep->chgCData(oldp+492,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U] 
                                               << 0x10U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                 >> 0x10U)))),3);
            tracep->chgCData(oldp+493,((0xffU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U] 
                                                  << 0x18U) 
                                                 | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                    >> 8U)))),8);
            tracep->chgCData(oldp+494,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U] 
                                               << 0x1aU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                 >> 6U)))),2);
            tracep->chgBit(oldp+495,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                            >> 5U))));
            tracep->chgCData(oldp+496,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U] 
                                               << 0x1eU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                 >> 2U)))),3);
            tracep->chgCData(oldp+497,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])),2);
            tracep->chgCData(oldp+498,((7U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_lfsr_inv__DOT__lfsr_q))),3);
            tracep->chgBit(oldp+499,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_vld_q));
            tracep->chgBit(oldp+500,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_vld_q1));
            tracep->chgBit(oldp+501,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__enable_d));
            tracep->chgBit(oldp+502,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__flush_ack_d));
            tracep->chgBit(oldp+503,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__flush_ack_q));
            tracep->chgBit(oldp+504,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__flush_en));
            tracep->chgBit(oldp+505,((0xffU == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__cnt_q))));
            tracep->chgBit(oldp+506,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mask_reads));
            tracep->chgBit(oldp+507,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__lock_reqs));
            tracep->chgBit(oldp+508,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__amo_sel));
            tracep->chgBit(oldp+509,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__amo_req_q));
            tracep->chgQData(oldp+510,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[2U])) 
                                         << 0x2dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[1U])) 
                                            << 0xdU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__adapter_dcache[0U])) 
                                              >> 0x13U)))),64);
            tracep->chgCData(oldp+512,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__flush_en)
                                         ? (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__cnt_q)))
                                         : 0U)),8);
            tracep->chgCData(oldp+513,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__cnt_q),8);
            tracep->chgCData(oldp+514,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__miss_req_masked_d),3);
            tracep->chgCData(oldp+515,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__miss_req_masked_q),3);
            tracep->chgBit(oldp+516,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__inv_vld));
            tracep->chgBit(oldp+517,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__inv_vld_all));
            tracep->chgBit(oldp+518,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__cl_write_en));
            tracep->chgBit(oldp+519,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__load_ack));
            tracep->chgBit(oldp+520,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__store_ack));
            tracep->chgBit(oldp+521,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__amo_ack));
            tracep->chgCData(oldp+522,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_rdrd_collision_q),3);
            tracep->chgBit(oldp+523,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__cnt_q))));
            tracep->chgCData(oldp+524,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__stores_inflight_q),3);
            tracep->chgCData(oldp+525,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_lzc_reqs__DOT__gen_lzc__DOT__in_tmp),3);
            tracep->chgCData(oldp+526,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_lfsr_inv__DOT__lfsr_q),8);
            tracep->chgSData(oldp+527,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__lfsr_q),16);
            tracep->chgSData(oldp+528,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__cnt_q),16);
            tracep->chgSData(oldp+529,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__mask_q),16);
            tracep->chgBit(oldp+530,((1U & ((((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__lfsr_q) 
                                              ^ ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__lfsr_q) 
                                                 >> 2U)) 
                                             ^ ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__lfsr_q) 
                                                >> 3U)) 
                                            ^ ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__i_exp_backoff__DOT__lfsr_q) 
                                               >> 5U)))));
            tracep->chgBit(oldp+531,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__i_wt_dcache_wbuffer__miss_req_o));
            tracep->chgBit(oldp+532,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_rtrn_vld) 
                                            >> 2U))));
            tracep->chgQData(oldp+533,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__rd_tag_q),44);
            tracep->chgBit(oldp+535,((0U != (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tocheck))));
            tracep->chgBit(oldp+536,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                    >> 0xbU)))));
            tracep->chgCData(oldp+537,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                         >> 3U)))),8);
            tracep->chgCData(oldp+538,((7U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q))),3);
            tracep->chgBit(oldp+539,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                    >> 0x17U)))));
            tracep->chgCData(oldp+540,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                         >> 0xfU)))),8);
            tracep->chgCData(oldp+541,((7U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                      >> 0xcU)))),3);
            tracep->chgBit(oldp+542,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                    >> 0x23U)))));
            tracep->chgCData(oldp+543,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                         >> 0x1bU)))),8);
            tracep->chgCData(oldp+544,((7U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                      >> 0x18U)))),3);
            tracep->chgBit(oldp+545,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                    >> 0x2fU)))));
            tracep->chgCData(oldp+546,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                         >> 0x27U)))),8);
            tracep->chgCData(oldp+547,((7U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tx_stat_q 
                                                      >> 0x24U)))),3);
            tracep->chgCData(oldp+548,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__valid),8);
            tracep->chgCData(oldp+549,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__dirty),8);
            tracep->chgCData(oldp+550,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__tocheck),8);
            tracep->chgCData(oldp+551,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__inval_hit),8);
            tracep->chgCData(oldp+552,((0xffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty))),8);
            tracep->chgCData(oldp+553,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 8U)))),8);
            tracep->chgCData(oldp+554,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x10U)))),8);
            tracep->chgCData(oldp+555,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x18U)))),8);
            tracep->chgCData(oldp+556,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x20U)))),8);
            tracep->chgCData(oldp+557,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x28U)))),8);
            tracep->chgCData(oldp+558,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x30U)))),8);
            tracep->chgCData(oldp+559,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__bdirty 
                                                         >> 0x38U)))),8);
            tracep->chgCData(oldp+560,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__check_ptr_q),3);
            tracep->chgCData(oldp+561,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__check_ptr_q1),3);
            tracep->chgCData(oldp+562,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__rtrn_ptr),3);
            tracep->chgCData(oldp+563,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT____Vcellout__i_rtrn_id_fifo__data_o),2);
            tracep->chgQData(oldp+564,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wr_paddr),56);
            tracep->chgCData(oldp+566,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__rd_hit_oh_q),8);
            tracep->chgBit(oldp+567,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__check_en_q));
            tracep->chgBit(oldp+568,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__check_en_q1));
            tracep->chgBit(oldp+569,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__status_cnt_q))));
            tracep->chgCData(oldp+570,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__ni_pending_q),8);
            tracep->chgBit(oldp+571,((0U != (0xfU & 
                                             (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__tx_vld))))));
            tracep->chgBit(oldp+572,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wr_cl_vld_q));
            tracep->chgCData(oldp+573,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wr_cl_idx_q),8);
            tracep->chgQData(oldp+574,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[0]),56);
            tracep->chgQData(oldp+576,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[1]),56);
            tracep->chgQData(oldp+578,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[2]),56);
            tracep->chgQData(oldp+580,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[3]),56);
            tracep->chgQData(oldp+582,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[4]),56);
            tracep->chgQData(oldp+584,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[5]),56);
            tracep->chgQData(oldp+586,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[6]),56);
            tracep->chgQData(oldp+588,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__debug_paddr[7]),56);
            tracep->chgCData(oldp+590,((0xffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp))),8);
            tracep->chgCData(oldp+591,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 8U)))),8);
            tracep->chgCData(oldp+592,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x10U)))),8);
            tracep->chgCData(oldp+593,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x18U)))),8);
            tracep->chgCData(oldp+594,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x20U)))),8);
            tracep->chgCData(oldp+595,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x28U)))),8);
            tracep->chgCData(oldp+596,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x30U)))),8);
            tracep->chgCData(oldp+597,((0xffU & (IData)(
                                                        (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__wtag_comp 
                                                         >> 0x38U)))),8);
            tracep->chgBit(oldp+598,((0U != (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__ni_pending_q))));
            tracep->chgBit(oldp+599,((4U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__status_cnt_q))));
            tracep->chgCData(oldp+600,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__status_cnt_q))),2);
            tracep->chgBit(oldp+601,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__gate_clock));
            tracep->chgCData(oldp+602,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__read_pointer_q),2);
            tracep->chgCData(oldp+603,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__write_pointer_n),2);
            tracep->chgCData(oldp+604,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__write_pointer_q),2);
            tracep->chgCData(oldp+605,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__status_cnt_q),3);
            tracep->chgCData(oldp+606,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_n))),2);
            tracep->chgCData(oldp+607,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_n) 
                                              >> 2U))),2);
            tracep->chgCData(oldp+608,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_n) 
                                              >> 4U))),2);
            tracep->chgCData(oldp+609,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_n) 
                                              >> 6U))),2);
            tracep->chgCData(oldp+610,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_q))),2);
            tracep->chgCData(oldp+611,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_q) 
                                              >> 2U))),2);
            tracep->chgCData(oldp+612,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_q) 
                                              >> 4U))),2);
            tracep->chgCData(oldp+613,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_rtrn_id_fifo__DOT__mem_q) 
                                              >> 6U))),2);
            tracep->chgCData(oldp+614,((0xfU & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__tx_vld)))),4);
            tracep->chgCData(oldp+615,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__rr_q),2);
            tracep->chgCData(oldp+616,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__req_d),4);
            tracep->chgBit(oldp+617,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
            tracep->chgCData(oldp+618,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),4);
            tracep->chgCData(oldp+619,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),4);
            tracep->chgCData(oldp+620,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),4);
            tracep->chgBit(oldp+621,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__1__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
            tracep->chgBit(oldp+622,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__1__KET____DOT__gen_level__BRA__1__KET____DOT__sel));
            tracep->chgCData(oldp+623,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),4);
            tracep->chgCData(oldp+624,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_tx_id_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),4);
            tracep->chgCData(oldp+625,((0xffU & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__valid)))),8);
            tracep->chgCData(oldp+626,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_vld_lzc__DOT__gen_lzc__DOT__in_tmp),8);
            tracep->chgCData(oldp+627,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__rr_q),3);
            tracep->chgCData(oldp+628,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__req_d),8);
            tracep->chgBit(oldp+629,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
            tracep->chgCData(oldp+630,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),8);
            tracep->chgCData(oldp+631,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),8);
            tracep->chgCData(oldp+632,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),8);
            tracep->chgBit(oldp+633,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
            tracep->chgBit(oldp+634,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__1__KET____DOT__sel));
            tracep->chgBit(oldp+635,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__2__KET____DOT__sel));
            tracep->chgBit(oldp+636,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__3__KET____DOT__sel));
            tracep->chgCData(oldp+637,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),8);
            tracep->chgCData(oldp+638,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_dirty_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),8);
            tracep->chgCData(oldp+639,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__rr_q),3);
            tracep->chgCData(oldp+640,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),8);
            tracep->chgCData(oldp+641,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),8);
            tracep->chgBit(oldp+642,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
            tracep->chgBit(oldp+643,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__1__KET____DOT__sel));
            tracep->chgBit(oldp+644,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__2__KET____DOT__sel));
            tracep->chgBit(oldp+645,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_levels__BRA__2__KET____DOT__gen_level__BRA__3__KET____DOT__sel));
            tracep->chgCData(oldp+646,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),8);
            tracep->chgCData(oldp+647,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_wbuffer__DOT__i_clean_rr__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),8);
            tracep->chgCData(oldp+648,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_idx_q),8);
            tracep->chgCData(oldp+649,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_off_q),4);
            tracep->chgQData(oldp+650,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0U])))),64);
            tracep->chgQData(oldp+652,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[2U])))),64);
            tracep->chgQData(oldp+654,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[4U])))),64);
            tracep->chgQData(oldp+656,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[6U])))),64);
            tracep->chgQData(oldp+658,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[8U])))),64);
            tracep->chgQData(oldp+660,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xbU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xaU])))),64);
            tracep->chgQData(oldp+662,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xdU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xcU])))),64);
            tracep->chgQData(oldp+664,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xfU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xeU])))),64);
            tracep->chgQData(oldp+666,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x11U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x10U])))),64);
            tracep->chgQData(oldp+668,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x13U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x12U])))),64);
            tracep->chgQData(oldp+670,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x15U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x14U])))),64);
            tracep->chgQData(oldp+672,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x17U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x16U])))),64);
            tracep->chgQData(oldp+674,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x19U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x18U])))),64);
            tracep->chgQData(oldp+676,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1bU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1aU])))),64);
            tracep->chgQData(oldp+678,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1dU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1cU])))),64);
            tracep->chgQData(oldp+680,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1fU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1eU])))),64);
            tracep->chgQData(oldp+682,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0U])))),64);
            tracep->chgQData(oldp+684,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[2U])))),64);
            tracep->chgQData(oldp+686,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[4U])))),64);
            tracep->chgQData(oldp+688,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[6U])))),64);
            tracep->chgQData(oldp+690,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[8U])))),64);
            tracep->chgQData(oldp+692,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xbU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xaU])))),64);
            tracep->chgQData(oldp+694,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xdU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xcU])))),64);
            tracep->chgQData(oldp+696,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xfU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__rdata_cl[0xeU])))),64);
            tracep->chgCData(oldp+698,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__vld_sel_q),2);
            tracep->chgBit(oldp+699,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__cmp_en_q));
            tracep->chgCData(oldp+700,(((0x20U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])
                                         ? 0U : (1U 
                                                 & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U] 
                                                    >> 0x16U)))),4);
            tracep->chgBit(oldp+701,((1U & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_cl_vld)))));
            tracep->chgCData(oldp+702,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__rr_q),2);
            __Vtemp22340[0U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0U];
            __Vtemp22340[1U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[1U];
            __Vtemp22340[2U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[2U];
            __Vtemp22340[3U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[3U];
            __Vtemp22340[4U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[4U];
            __Vtemp22340[5U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[5U];
            __Vtemp22340[6U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[6U];
            __Vtemp22340[7U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[7U];
            __Vtemp22340[8U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[8U];
            __Vtemp22340[9U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[9U];
            __Vtemp22340[0xaU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xaU];
            __Vtemp22340[0xbU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xbU];
            __Vtemp22340[0xcU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xcU];
            __Vtemp22340[0xdU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xdU];
            __Vtemp22340[0xeU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xeU];
            __Vtemp22340[0xfU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xfU];
            tracep->chgWData(oldp+703,(__Vtemp22340),512);
            tracep->chgQData(oldp+719,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0U])))),64);
            tracep->chgQData(oldp+721,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[2U])))),64);
            tracep->chgQData(oldp+723,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[4U])))),64);
            tracep->chgQData(oldp+725,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[6U])))),64);
            tracep->chgQData(oldp+727,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[8U])))),64);
            tracep->chgQData(oldp+729,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xbU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xaU])))),64);
            tracep->chgQData(oldp+731,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xdU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xcU])))),64);
            tracep->chgQData(oldp+733,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xfU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0xeU])))),64);
            __Vtemp22341[0U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x10U];
            __Vtemp22341[1U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x11U];
            __Vtemp22341[2U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x12U];
            __Vtemp22341[3U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x13U];
            __Vtemp22341[4U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x14U];
            __Vtemp22341[5U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x15U];
            __Vtemp22341[6U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x16U];
            __Vtemp22341[7U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x17U];
            __Vtemp22341[8U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x18U];
            __Vtemp22341[9U] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x19U];
            __Vtemp22341[0xaU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1aU];
            __Vtemp22341[0xbU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1bU];
            __Vtemp22341[0xcU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1cU];
            __Vtemp22341[0xdU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1dU];
            __Vtemp22341[0xeU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1eU];
            __Vtemp22341[0xfU] = vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1fU];
            tracep->chgWData(oldp+735,(__Vtemp22341),512);
            tracep->chgQData(oldp+751,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x11U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x10U])))),64);
            tracep->chgQData(oldp+753,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x13U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x12U])))),64);
            tracep->chgQData(oldp+755,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x15U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x14U])))),64);
            tracep->chgQData(oldp+757,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x17U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x16U])))),64);
            tracep->chgQData(oldp+759,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x19U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x18U])))),64);
            tracep->chgQData(oldp+761,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1bU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1aU])))),64);
            tracep->chgQData(oldp+763,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1dU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1cU])))),64);
            tracep->chgQData(oldp+765,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1fU])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__bank_wdata[0x1eU])))),64);
            tracep->chgQData(oldp+767,((((QData)((IData)(
                                                         (1U 
                                                          & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+769,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__0__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+771,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 1U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+773,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__1__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+775,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 2U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+777,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__2__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+779,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 3U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+781,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__3__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+783,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 4U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+785,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__4__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+787,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 5U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+789,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__5__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+791,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 6U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+793,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__6__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgQData(oldp+795,((((QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__wr_vld_bits) 
                                                             >> 7U)))) 
                                         << 0x2cU) 
                                        | (0xfffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[2U])) 
                                               << 0x21U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[1U])) 
                                                  << 1U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_missunit__DOT__mshr_q[0U])) 
                                                    >> 0x1fU)))))),45);
            tracep->chgQData(oldp+797,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__i_wt_dcache_mem__DOT__gen_tag_srams__BRA__7__KET____DOT__i_tag_sram__DOT__wdata_aligned),64);
            tracep->chgBit(oldp+799,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__miss_req_o));
            tracep->chgCData(oldp+800,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__vld_data_q),8);
            tracep->chgQData(oldp+801,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_tag_q 
                                         << 0xcU) | (QData)((IData)(
                                                                    (((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_idx_q) 
                                                                      << 4U) 
                                                                     | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_off_q)))))),56);
            tracep->chgBit(oldp+803,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__miss_nc_o));
            tracep->chgCData(oldp+804,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__miss_nc_o)
                                         ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__data_size_q)
                                         : 7U)),3);
            tracep->chgBit(oldp+805,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_rtrn_vld))));
            tracep->chgCData(oldp+806,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__state_q),3);
            tracep->chgQData(oldp+807,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_tag_q),44);
            tracep->chgCData(oldp+809,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_idx_q),8);
            tracep->chgCData(oldp+810,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__address_off_q),4);
            tracep->chgBit(oldp+811,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__rd_req_q));
            tracep->chgBit(oldp+812,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__rd_ack_q));
            tracep->chgCData(oldp+813,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__data_size_q),2);
            tracep->chgBit(oldp+814,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__miss_req_o));
            tracep->chgCData(oldp+815,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__vld_data_q),8);
            tracep->chgQData(oldp+816,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_tag_q 
                                         << 0xcU) | (QData)((IData)(
                                                                    (((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_idx_q) 
                                                                      << 4U) 
                                                                     | (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_off_q)))))),56);
            tracep->chgBit(oldp+818,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__miss_nc_o));
            tracep->chgCData(oldp+819,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT____Vcellout__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__miss_nc_o)
                                         ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__data_size_q)
                                         : 7U)),3);
            tracep->chgBit(oldp+820,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__miss_rtrn_vld) 
                                            >> 1U))));
            tracep->chgCData(oldp+821,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__state_q),3);
            tracep->chgQData(oldp+822,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_tag_q),44);
            tracep->chgCData(oldp+824,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_idx_q),8);
            tracep->chgCData(oldp+825,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__address_off_q),4);
            tracep->chgBit(oldp+826,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__rd_req_q));
            tracep->chgBit(oldp+827,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__rd_ack_q));
            tracep->chgCData(oldp+828,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__data_size_q),2);
            tracep->chgCData(oldp+829,((3U & (IData)(
                                                     (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o 
                                                      >> 0x3bU)))),2);
            tracep->chgQData(oldp+830,((0xffffffffffffffULL 
                                        & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o 
                                           >> 3U))),56);
            tracep->chgBit(oldp+832,((1U & (IData)(
                                                   (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o 
                                                    >> 2U)))));
            tracep->chgCData(oldp+833,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o))),2);
            tracep->chgBit(oldp+834,((2U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+835,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__status_cnt_q))));
            tracep->chgCData(oldp+836,((3U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U] 
                                              >> 5U))),2);
            tracep->chgCData(oldp+837,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U] 
                                              >> 2U))),3);
            tracep->chgCData(oldp+838,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U] 
                                               << 1U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[3U] 
                                                 >> 0x1fU)))),3);
            tracep->chgQData(oldp+839,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U])) 
                                            << 0x39U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[3U])) 
                                               << 0x19U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[2U])) 
                                                 >> 7U))))),56);
            tracep->chgQData(oldp+841,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[2U])) 
                                         << 0x39U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[1U])) 
                                            << 0x19U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[0U])) 
                                              >> 7U)))),64);
            tracep->chgBit(oldp+843,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[0U] 
                                            >> 6U))));
            tracep->chgCData(oldp+844,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[1U] 
                                               << 0x1cU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[0U] 
                                                 >> 4U)))),2);
            tracep->chgCData(oldp+845,((0xfU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[0U])),4);
            tracep->chgBit(oldp+846,((2U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+847,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__status_cnt_q))));
            tracep->chgCData(oldp+848,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__arb_req),2);
            tracep->chgBit(oldp+849,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
            tracep->chgBit(oldp+850,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_rd_req));
            tracep->chgBit(oldp+851,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_req));
            tracep->chgBit(oldp+852,((4U != (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+853,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_rd_lock));
            tracep->chgBit(oldp+854,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_lock));
            tracep->chgQData(oldp+855,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)
                                         ? (0xffffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U])) 
                                                << 0x39U) 
                                               | (((QData)((IData)(
                                                                   vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[3U])) 
                                                   << 0x19U) 
                                                  | ((QData)((IData)(
                                                                     vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[2U])) 
                                                     >> 7U))))
                                         : (0xffffffffffffffULL 
                                            & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o 
                                               >> 3U)))),64);
            tracep->chgQData(oldp+857,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U])) 
                                            << 0x39U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[3U])) 
                                               << 0x19U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[2U])) 
                                                 >> 7U))))),64);
            tracep->chgBit(oldp+859,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_rd_blen));
            tracep->chgCData(oldp+860,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)
                                         ? (3U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U] 
                                                  >> 2U))
                                         : 3U)),2);
            tracep->chgCData(oldp+861,((3U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[4U] 
                                              >> 2U))),2);
            tracep->chgCData(oldp+862,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_rd_id_in),4);
            tracep->chgCData(oldp+863,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_id_in),4);
            tracep->chgQData(oldp+864,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_data[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_data[0U])))),64);
            tracep->chgQData(oldp+866,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_data[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_data[2U])))),64);
            tracep->chgCData(oldp+868,((0xffU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_be))),8);
            tracep->chgCData(oldp+869,((0xffU & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_be) 
                                                 >> 8U))),8);
            tracep->chgCData(oldp+870,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__axi_wr_atop),6);
            tracep->chgCData(oldp+871,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__amo_off_d),3);
            tracep->chgCData(oldp+872,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__amo_off_q),3);
            tracep->chgBit(oldp+873,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__amo_gen_r_d));
            tracep->chgBit(oldp+874,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__amo_gen_r_q));
            tracep->chgCData(oldp+875,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__mem_q) 
                                              >> (7U 
                                                  & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__read_pointer_q) 
                                                     << 1U))))),2);
            tracep->chgCData(oldp+876,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rtrn_tid_q),2);
            tracep->chgCData(oldp+877,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_tid_q),2);
            tracep->chgCData(oldp+878,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__mem_q) 
                                              >> (7U 
                                                  & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__read_pointer_q) 
                                                     << 1U))))),2);
            tracep->chgCData(oldp+879,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__mem_q) 
                                              >> (7U 
                                                  & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__read_pointer_q) 
                                                     << 1U))))),2);
            tracep->chgBit(oldp+880,((4U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+881,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+882,((4U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+883,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+884,((4U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+885,((0U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__status_cnt_q))));
            tracep->chgBit(oldp+886,((4U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+887,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_first_q));
            tracep->chgBit(oldp+888,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_first_q));
            tracep->chgQData(oldp+889,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rd_shift_q[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rd_shift_q[0U])))),64);
            tracep->chgQData(oldp+891,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rd_shift_q[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__icache_rd_shift_q[2U])))),64);
            tracep->chgQData(oldp+893,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rd_shift_q[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rd_shift_q[0U])))),64);
            tracep->chgQData(oldp+895,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rd_shift_q[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rd_shift_q[2U])))),64);
            tracep->chgCData(oldp+897,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_type_q),3);
            tracep->chgBit(oldp+898,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_inv_q 
                                            >> 0x10U))));
            tracep->chgBit(oldp+899,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_inv_q 
                                            >> 0xfU))));
            tracep->chgSData(oldp+900,((0xfffU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_inv_q 
                                                  >> 3U))),12);
            tracep->chgCData(oldp+901,((7U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__dcache_rtrn_inv_q)),3);
            tracep->chgBit(oldp+902,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__req_nodes));
            tracep->chgBit(oldp+903,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
            tracep->chgBit(oldp+904,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__req_nodes));
            tracep->chgBit(oldp+905,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__rr_q));
            tracep->chgCData(oldp+906,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__req_d),2);
            tracep->chgBit(oldp+907,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
            tracep->chgCData(oldp+908,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),2);
            tracep->chgCData(oldp+909,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),2);
            tracep->chgCData(oldp+910,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),2);
            tracep->chgBit(oldp+911,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
            tracep->chgBit(oldp+912,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
            tracep->chgBit(oldp+913,((1U & ((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes))
                                             ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)
                                             : (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes)))));
            tracep->chgBit(oldp+914,((1U & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes)))));
            tracep->chgCData(oldp+915,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes),2);
            tracep->chgBit(oldp+916,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
            tracep->chgBit(oldp+917,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                            >> 1U))));
            tracep->chgCData(oldp+918,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),2);
            tracep->chgBit(oldp+919,((1U & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes)))));
            tracep->chgCData(oldp+920,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes),2);
            tracep->chgBit(oldp+921,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
            tracep->chgBit(oldp+922,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                            >> 1U))));
            tracep->chgCData(oldp+923,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rr_arb_tree__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),2);
            tracep->chgBit(oldp+924,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+925,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__read_pointer_q));
            tracep->chgBit(oldp+926,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__write_pointer_q));
            tracep->chgCData(oldp+927,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__status_cnt_q),2);
            tracep->chgCData(oldp+928,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[2U] 
                                               << 5U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[1U] 
                                                 >> 0x1bU)))),2);
            tracep->chgQData(oldp+929,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[2U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[1U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[0U])) 
                                                 >> 3U))))),56);
            tracep->chgBit(oldp+931,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[0U] 
                                            >> 2U))));
            tracep->chgCData(oldp+932,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[0U])),2);
            tracep->chgCData(oldp+933,((3U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[3U] 
                                              >> 0x18U))),2);
            tracep->chgQData(oldp+934,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[2U]))))),56);
            tracep->chgBit(oldp+936,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[1U] 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+937,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[2U] 
                                               << 3U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_icache_data_fifo__DOT__mem_q[1U] 
                                                 >> 0x1dU)))),2);
            tracep->chgBit(oldp+938,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__status_cnt_q))));
            tracep->chgBit(oldp+939,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__read_pointer_q));
            tracep->chgBit(oldp+940,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__write_pointer_q));
            tracep->chgCData(oldp+941,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__status_cnt_q),2);
            tracep->chgCData(oldp+942,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[5U] 
                                               << 0x1bU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                                 >> 5U)))),2);
            tracep->chgCData(oldp+943,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[5U] 
                                               << 0x1eU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                                 >> 2U)))),3);
            tracep->chgCData(oldp+944,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                               << 1U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[3U] 
                                                 >> 0x1fU)))),3);
            tracep->chgQData(oldp+945,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U])) 
                                            << 0x39U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[3U])) 
                                               << 0x19U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[2U])) 
                                                 >> 7U))))),56);
            tracep->chgQData(oldp+947,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[2U])) 
                                         << 0x39U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[1U])) 
                                            << 0x19U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[0U])) 
                                              >> 7U)))),64);
            tracep->chgBit(oldp+949,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[0U] 
                                            >> 6U))));
            tracep->chgCData(oldp+950,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[1U] 
                                               << 0x1cU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[0U] 
                                                 >> 4U)))),2);
            tracep->chgCData(oldp+951,((0xfU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[0U])),4);
            tracep->chgCData(oldp+952,((3U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[8U] 
                                              >> 0xcU))),2);
            tracep->chgCData(oldp+953,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[8U] 
                                              >> 9U))),3);
            tracep->chgCData(oldp+954,((7U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[8U] 
                                              >> 6U))),3);
            tracep->chgQData(oldp+955,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[8U])) 
                                            << 0x32U) 
                                           | (((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[7U])) 
                                               << 0x12U) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[6U])) 
                                                 >> 0xeU))))),56);
            tracep->chgQData(oldp+957,((((QData)((IData)(
                                                         vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[6U])) 
                                         << 0x32U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[5U])) 
                                            << 0x12U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U])) 
                                              >> 0xeU)))),64);
            tracep->chgBit(oldp+959,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                            >> 0xdU))));
            tracep->chgCData(oldp+960,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[5U] 
                                               << 0x15U) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                                 >> 0xbU)))),2);
            tracep->chgCData(oldp+961,((0xfU & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[5U] 
                                                 << 0x19U) 
                                                | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_dcache_data_fifo__DOT__mem_q[4U] 
                                                   >> 7U)))),4);
            tracep->chgCData(oldp+962,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__status_cnt_q))),2);
            tracep->chgCData(oldp+963,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_icache_data_fifo__data_o))),2);
            tracep->chgCData(oldp+964,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__read_pointer_q),2);
            tracep->chgCData(oldp+965,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__write_pointer_q),2);
            tracep->chgCData(oldp+966,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__status_cnt_q),3);
            tracep->chgCData(oldp+967,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__mem_q))),2);
            tracep->chgCData(oldp+968,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__mem_q) 
                                              >> 2U))),2);
            tracep->chgCData(oldp+969,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__mem_q) 
                                              >> 4U))),2);
            tracep->chgCData(oldp+970,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_icache_id__DOT__mem_q) 
                                              >> 6U))),2);
            tracep->chgCData(oldp+971,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__status_cnt_q))),2);
            tracep->chgCData(oldp+972,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[1U] 
                                               << 0x1cU) 
                                              | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT____Vcellout__i_dcache_data_fifo__data_o[0U] 
                                                 >> 4U)))),2);
            tracep->chgCData(oldp+973,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__read_pointer_q),2);
            tracep->chgCData(oldp+974,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__write_pointer_q),2);
            tracep->chgCData(oldp+975,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__status_cnt_q),3);
            tracep->chgCData(oldp+976,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__mem_q))),2);
            tracep->chgCData(oldp+977,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__mem_q) 
                                              >> 2U))),2);
            tracep->chgCData(oldp+978,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__mem_q) 
                                              >> 4U))),2);
            tracep->chgCData(oldp+979,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_rd_dcache_id__DOT__mem_q) 
                                              >> 6U))),2);
            tracep->chgCData(oldp+980,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__status_cnt_q))),2);
            tracep->chgCData(oldp+981,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__read_pointer_q),2);
            tracep->chgCData(oldp+982,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__write_pointer_q),2);
            tracep->chgCData(oldp+983,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__status_cnt_q),3);
            tracep->chgCData(oldp+984,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__mem_q))),2);
            tracep->chgCData(oldp+985,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__mem_q) 
                                              >> 2U))),2);
            tracep->chgCData(oldp+986,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__mem_q) 
                                              >> 4U))),2);
            tracep->chgCData(oldp+987,((3U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_wr_dcache_id__DOT__mem_q) 
                                              >> 6U))),2);
            tracep->chgCData(oldp+988,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__status_cnt_q))),2);
            tracep->chgCData(oldp+989,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__read_pointer_q),2);
            tracep->chgCData(oldp+990,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__write_pointer_q),2);
            tracep->chgCData(oldp+991,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__status_cnt_q),3);
            tracep->chgCData(oldp+992,((0x1fU & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__mem_q)),5);
            tracep->chgCData(oldp+993,((0x1fU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__mem_q 
                                                 >> 5U))),5);
            tracep->chgCData(oldp+994,((0x1fU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__mem_q 
                                                 >> 0xaU))),5);
            tracep->chgCData(oldp+995,((0x1fU & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_b_fifo__DOT__mem_q 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+996,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_axi_shim__DOT__wr_state_q),4);
            tracep->chgBit(oldp+997,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_axi_shim__DOT__wr_cnt_q));
            tracep->chgBit(oldp+998,((1U & (~ (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_adapter__DOT__i_axi_shim__DOT__wr_cnt_q)))));
            tracep->chgBit(oldp+999,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[8U] 
                                            >> 0x10U))));
            tracep->chgBit(oldp+1000,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[7U] 
                                             >> 0x1aU))));
            tracep->chgBit(oldp+1001,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_ready_o));
            tracep->chgBit(oldp+1002,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o) 
                                             >> 5U))));
            tracep->chgBit(oldp+1003,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o) 
                                             >> 4U))));
            tracep->chgBit(oldp+1004,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o) 
                                             >> 3U))));
            tracep->chgBit(oldp+1005,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o) 
                                             >> 2U))));
            tracep->chgBit(oldp+1006,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o) 
                                             >> 1U))));
            tracep->chgBit(oldp+1007,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o))));
            tracep->chgBit(oldp+1008,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1009,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                             >> 0xdU))));
            tracep->chgBit(oldp+1010,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                             >> 5U))));
            tracep->chgBit(oldp+1011,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[0U])));
            tracep->chgBit(oldp+1012,((8U == (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__status_cnt_q))));
            tracep->chgBit(oldp+1013,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_empty));
            tracep->chgBit(oldp+1014,((8U != (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__status_cnt_q))));
            tracep->chgBit(oldp+1015,(((0x20U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__x_issue_resp_o))
                                        ? 1U : 0U)));
            tracep->chgIData(oldp+1016,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[5U] 
                                          << 0x13U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[4U] 
                                            >> 0xdU))),32);
            tracep->chgCData(oldp+1017,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[5U] 
                                                << 0x15U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[4U] 
                                                  >> 0xbU)))),2);
            tracep->chgCData(oldp+1018,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[5U] 
                                                << 0x18U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[4U] 
                                                  >> 8U)))),3);
            tracep->chgQData(oldp+1019,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[2U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U])) 
                                               >> 8U)))),64);
            tracep->chgQData(oldp+1021,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[4U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[3U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[2U])) 
                                               >> 8U)))),64);
            tracep->chgCData(oldp+1023,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[1U] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                                  >> 6U)))),2);
            tracep->chgBit(oldp+1024,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                             >> 5U))));
            tracep->chgBit(oldp+1025,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                             >> 4U))));
            tracep->chgBit(oldp+1026,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                             >> 3U))));
            tracep->chgBit(oldp+1027,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                             >> 2U))));
            tracep->chgBit(oldp+1028,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U] 
                                             >> 1U))));
            tracep->chgBit(oldp+1029,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__req_i[0U])));
            tracep->chgIData(oldp+1030,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[5U] 
                                          << 0x13U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[4U] 
                                            >> 0xdU))),32);
            tracep->chgCData(oldp+1031,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[5U] 
                                                << 0x15U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[4U] 
                                                  >> 0xbU)))),2);
            tracep->chgCData(oldp+1032,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[5U] 
                                                << 0x18U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[4U] 
                                                  >> 8U)))),3);
            tracep->chgQData(oldp+1033,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[2U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U])) 
                                               >> 8U)))),64);
            tracep->chgQData(oldp+1035,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[4U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[3U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[2U])) 
                                               >> 8U)))),64);
            tracep->chgCData(oldp+1037,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[1U] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                                  >> 6U)))),2);
            tracep->chgBit(oldp+1038,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                             >> 5U))));
            tracep->chgBit(oldp+1039,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                             >> 4U))));
            tracep->chgBit(oldp+1040,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                             >> 3U))));
            tracep->chgBit(oldp+1041,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                             >> 2U))));
            tracep->chgBit(oldp+1042,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U] 
                                             >> 1U))));
            tracep->chgBit(oldp+1043,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT____Vcellout__fifo_commit_i__data_o[0U])));
            tracep->chgCData(oldp+1044,((0xfU & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__i_counter__DOT__counter_q))),4);
            tracep->chgCData(oldp+1045,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__instr_decoder_i__DOT__sel),2);
            tracep->chgCData(oldp+1046,((7U & (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__status_cnt_q))),3);
            tracep->chgBit(oldp+1047,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__gate_clock));
            tracep->chgCData(oldp+1048,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__read_pointer_q),3);
            tracep->chgCData(oldp+1049,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__write_pointer_q),3);
            tracep->chgCData(oldp+1050,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__status_cnt_q),4);
            tracep->chgIData(oldp+1051,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                          << 0x13U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[4U] 
                                            >> 0xdU))),32);
            tracep->chgCData(oldp+1052,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                                << 0x15U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[4U] 
                                                  >> 0xbU)))),2);
            tracep->chgCData(oldp+1053,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                                << 0x18U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[4U] 
                                                  >> 8U)))),3);
            tracep->chgQData(oldp+1054,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[2U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U])) 
                                               >> 8U)))),64);
            tracep->chgQData(oldp+1056,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[4U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[3U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[2U])) 
                                               >> 8U)))),64);
            tracep->chgCData(oldp+1058,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[1U] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                                  >> 6U)))),2);
            tracep->chgBit(oldp+1059,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                             >> 5U))));
            tracep->chgBit(oldp+1060,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                             >> 4U))));
            tracep->chgBit(oldp+1061,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                             >> 3U))));
            tracep->chgBit(oldp+1062,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                             >> 2U))));
            tracep->chgBit(oldp+1063,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U] 
                                             >> 1U))));
            tracep->chgBit(oldp+1064,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0U])));
            tracep->chgIData(oldp+1065,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                          << 6U) | 
                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[9U] 
                                          >> 0x1aU))),32);
            tracep->chgCData(oldp+1066,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                                << 8U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[9U] 
                                                  >> 0x18U)))),2);
            tracep->chgCData(oldp+1067,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                                << 0xbU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[9U] 
                                                  >> 0x15U)))),3);
            tracep->chgQData(oldp+1068,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[7U])) 
                                          << 0x2bU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[6U])) 
                                             << 0xbU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U])) 
                                               >> 0x15U)))),64);
            tracep->chgQData(oldp+1070,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[9U])) 
                                          << 0x2bU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[8U])) 
                                             << 0xbU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[7U])) 
                                               >> 0x15U)))),64);
            tracep->chgCData(oldp+1072,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[6U] 
                                                << 0xdU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                                  >> 0x13U)))),2);
            tracep->chgBit(oldp+1073,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1074,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1075,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1076,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0xfU))));
            tracep->chgBit(oldp+1077,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0xeU))));
            tracep->chgBit(oldp+1078,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[5U] 
                                             >> 0xdU))));
            tracep->chgIData(oldp+1079,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                          << 0x19U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xfU] 
                                            >> 7U))),32);
            tracep->chgCData(oldp+1080,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                                << 0x1bU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xfU] 
                                                  >> 5U)))),2);
            tracep->chgCData(oldp+1081,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                                << 0x1eU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xfU] 
                                                  >> 2U)))),3);
            tracep->chgQData(oldp+1082,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xdU])) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xcU])) 
                                             << 0x1eU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xbU])) 
                                               >> 2U)))),64);
            tracep->chgQData(oldp+1084,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xfU])) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xeU])) 
                                             << 0x1eU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xdU])) 
                                               >> 2U)))),64);
            tracep->chgCData(oldp+1086,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xbU])),2);
            tracep->chgBit(oldp+1087,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1fU))));
            tracep->chgBit(oldp+1088,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1eU))));
            tracep->chgBit(oldp+1089,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1dU))));
            tracep->chgBit(oldp+1090,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1cU))));
            tracep->chgBit(oldp+1091,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1bU))));
            tracep->chgBit(oldp+1092,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0xaU] 
                                             >> 0x1aU))));
            tracep->chgIData(oldp+1093,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                          << 0xcU) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x14U] 
                                            >> 0x14U))),32);
            tracep->chgCData(oldp+1094,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                                << 0xeU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x14U] 
                                                  >> 0x12U)))),2);
            tracep->chgCData(oldp+1095,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                                << 0x11U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x14U] 
                                                  >> 0xfU)))),3);
            tracep->chgQData(oldp+1096,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x12U])) 
                                          << 0x31U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x11U])) 
                                             << 0x11U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U])) 
                                               >> 0xfU)))),64);
            tracep->chgQData(oldp+1098,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x14U])) 
                                          << 0x31U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x13U])) 
                                             << 0x11U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x12U])) 
                                               >> 0xfU)))),64);
            tracep->chgCData(oldp+1100,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x11U] 
                                                << 0x13U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                                  >> 0xdU)))),2);
            tracep->chgBit(oldp+1101,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 0xcU))));
            tracep->chgBit(oldp+1102,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 0xbU))));
            tracep->chgBit(oldp+1103,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 0xaU))));
            tracep->chgBit(oldp+1104,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 9U))));
            tracep->chgBit(oldp+1105,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 8U))));
            tracep->chgBit(oldp+1106,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x10U] 
                                             >> 7U))));
            tracep->chgIData(oldp+1107,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                          << 0x1fU) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1aU] 
                                            >> 1U))),32);
            tracep->chgCData(oldp+1108,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1aU] 
                                                << 1U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x19U] 
                                                  >> 0x1fU)))),2);
            tracep->chgCData(oldp+1109,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1aU] 
                                                << 4U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x19U] 
                                                  >> 0x1cU)))),3);
            tracep->chgQData(oldp+1110,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x17U])) 
                                          << 0x24U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x16U])) 
                                             << 4U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U])) 
                                               >> 0x1cU)))),64);
            tracep->chgQData(oldp+1112,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x19U])) 
                                          << 0x24U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x18U])) 
                                             << 4U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x17U])) 
                                               >> 0x1cU)))),64);
            tracep->chgCData(oldp+1114,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x16U] 
                                                << 6U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                                  >> 0x1aU)))),2);
            tracep->chgBit(oldp+1115,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x19U))));
            tracep->chgBit(oldp+1116,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x18U))));
            tracep->chgBit(oldp+1117,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x17U))));
            tracep->chgBit(oldp+1118,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x16U))));
            tracep->chgBit(oldp+1119,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x15U))));
            tracep->chgBit(oldp+1120,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x15U] 
                                             >> 0x14U))));
            tracep->chgIData(oldp+1121,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                          << 0x12U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1fU] 
                                            >> 0xeU))),32);
            tracep->chgCData(oldp+1122,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                                << 0x14U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1fU] 
                                                  >> 0xcU)))),2);
            tracep->chgCData(oldp+1123,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                                << 0x17U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1fU] 
                                                  >> 9U)))),3);
            tracep->chgQData(oldp+1124,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1dU])) 
                                          << 0x37U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1cU])) 
                                             << 0x17U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU])) 
                                               >> 9U)))),64);
            tracep->chgQData(oldp+1126,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1fU])) 
                                          << 0x37U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1eU])) 
                                             << 0x17U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1dU])) 
                                               >> 9U)))),64);
            tracep->chgCData(oldp+1128,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1cU] 
                                                << 0x19U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                                  >> 7U)))),2);
            tracep->chgBit(oldp+1129,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 6U))));
            tracep->chgBit(oldp+1130,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 5U))));
            tracep->chgBit(oldp+1131,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 4U))));
            tracep->chgBit(oldp+1132,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 3U))));
            tracep->chgBit(oldp+1133,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 2U))));
            tracep->chgBit(oldp+1134,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x1bU] 
                                             >> 1U))));
            tracep->chgIData(oldp+1135,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                          << 5U) | 
                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x24U] 
                                          >> 0x1bU))),32);
            tracep->chgCData(oldp+1136,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                                << 7U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x24U] 
                                                  >> 0x19U)))),2);
            tracep->chgCData(oldp+1137,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                                << 0xaU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x24U] 
                                                  >> 0x16U)))),3);
            tracep->chgQData(oldp+1138,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x22U])) 
                                          << 0x2aU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x21U])) 
                                             << 0xaU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U])) 
                                               >> 0x16U)))),64);
            tracep->chgQData(oldp+1140,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x24U])) 
                                          << 0x2aU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x23U])) 
                                             << 0xaU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x22U])) 
                                               >> 0x16U)))),64);
            tracep->chgCData(oldp+1142,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x21U] 
                                                << 0xcU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                                  >> 0x14U)))),2);
            tracep->chgBit(oldp+1143,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0x13U))));
            tracep->chgBit(oldp+1144,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1145,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1146,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1147,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0xfU))));
            tracep->chgBit(oldp+1148,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x20U] 
                                             >> 0xeU))));
            tracep->chgIData(oldp+1149,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2bU] 
                                          << 0x18U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2aU] 
                                            >> 8U))),32);
            tracep->chgCData(oldp+1150,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2bU] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2aU] 
                                                  >> 6U)))),2);
            tracep->chgCData(oldp+1151,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2bU] 
                                                << 0x1dU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2aU] 
                                                  >> 3U)))),3);
            tracep->chgQData(oldp+1152,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x28U])) 
                                          << 0x3dU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x27U])) 
                                             << 0x1dU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x26U])) 
                                               >> 3U)))),64);
            tracep->chgQData(oldp+1154,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x2aU])) 
                                          << 0x3dU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x29U])) 
                                             << 0x1dU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x28U])) 
                                               >> 3U)))),64);
            tracep->chgCData(oldp+1156,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x27U] 
                                                << 0x1fU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x26U] 
                                                  >> 1U)))),2);
            tracep->chgBit(oldp+1157,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x26U])));
            tracep->chgBit(oldp+1158,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                             >> 0x1fU))));
            tracep->chgBit(oldp+1159,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                             >> 0x1eU))));
            tracep->chgBit(oldp+1160,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                             >> 0x1dU))));
            tracep->chgBit(oldp+1161,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                             >> 0x1cU))));
            tracep->chgBit(oldp+1162,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_n[0x25U] 
                                             >> 0x1bU))));
            tracep->chgIData(oldp+1163,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                          << 0x13U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[4U] 
                                            >> 0xdU))),32);
            tracep->chgCData(oldp+1164,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                                << 0x15U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[4U] 
                                                  >> 0xbU)))),2);
            tracep->chgCData(oldp+1165,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                                << 0x18U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[4U] 
                                                  >> 8U)))),3);
            tracep->chgQData(oldp+1166,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[2U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U])) 
                                               >> 8U)))),64);
            tracep->chgQData(oldp+1168,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[4U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[3U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[2U])) 
                                               >> 8U)))),64);
            tracep->chgCData(oldp+1170,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[1U] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                                  >> 6U)))),2);
            tracep->chgBit(oldp+1171,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                             >> 5U))));
            tracep->chgBit(oldp+1172,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                             >> 4U))));
            tracep->chgBit(oldp+1173,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                             >> 3U))));
            tracep->chgBit(oldp+1174,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                             >> 2U))));
            tracep->chgBit(oldp+1175,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U] 
                                             >> 1U))));
            tracep->chgBit(oldp+1176,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0U])));
            tracep->chgIData(oldp+1177,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                          << 6U) | 
                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[9U] 
                                          >> 0x1aU))),32);
            tracep->chgCData(oldp+1178,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                                << 8U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[9U] 
                                                  >> 0x18U)))),2);
            tracep->chgCData(oldp+1179,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                                << 0xbU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[9U] 
                                                  >> 0x15U)))),3);
            tracep->chgQData(oldp+1180,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[7U])) 
                                          << 0x2bU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[6U])) 
                                             << 0xbU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U])) 
                                               >> 0x15U)))),64);
            tracep->chgQData(oldp+1182,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[9U])) 
                                          << 0x2bU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[8U])) 
                                             << 0xbU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[7U])) 
                                               >> 0x15U)))),64);
            tracep->chgCData(oldp+1184,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[6U] 
                                                << 0xdU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                                  >> 0x13U)))),2);
            tracep->chgBit(oldp+1185,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1186,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1187,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1188,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0xfU))));
            tracep->chgBit(oldp+1189,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0xeU))));
            tracep->chgBit(oldp+1190,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[5U] 
                                             >> 0xdU))));
            tracep->chgIData(oldp+1191,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                          << 0x19U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xfU] 
                                            >> 7U))),32);
            tracep->chgCData(oldp+1192,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                                << 0x1bU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xfU] 
                                                  >> 5U)))),2);
            tracep->chgCData(oldp+1193,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                                << 0x1eU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xfU] 
                                                  >> 2U)))),3);
            tracep->chgQData(oldp+1194,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xdU])) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xcU])) 
                                             << 0x1eU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xbU])) 
                                               >> 2U)))),64);
            tracep->chgQData(oldp+1196,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xfU])) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xeU])) 
                                             << 0x1eU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xdU])) 
                                               >> 2U)))),64);
            tracep->chgCData(oldp+1198,((3U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xbU])),2);
            tracep->chgBit(oldp+1199,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1fU))));
            tracep->chgBit(oldp+1200,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1eU))));
            tracep->chgBit(oldp+1201,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1dU))));
            tracep->chgBit(oldp+1202,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1cU))));
            tracep->chgBit(oldp+1203,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1bU))));
            tracep->chgBit(oldp+1204,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0xaU] 
                                             >> 0x1aU))));
            tracep->chgIData(oldp+1205,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                          << 0xcU) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x14U] 
                                            >> 0x14U))),32);
            tracep->chgCData(oldp+1206,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                                << 0xeU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x14U] 
                                                  >> 0x12U)))),2);
            tracep->chgCData(oldp+1207,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                                << 0x11U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x14U] 
                                                  >> 0xfU)))),3);
            tracep->chgQData(oldp+1208,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x12U])) 
                                          << 0x31U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x11U])) 
                                             << 0x11U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U])) 
                                               >> 0xfU)))),64);
            tracep->chgQData(oldp+1210,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x14U])) 
                                          << 0x31U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x13U])) 
                                             << 0x11U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x12U])) 
                                               >> 0xfU)))),64);
            tracep->chgCData(oldp+1212,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x11U] 
                                                << 0x13U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                                  >> 0xdU)))),2);
            tracep->chgBit(oldp+1213,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 0xcU))));
            tracep->chgBit(oldp+1214,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 0xbU))));
            tracep->chgBit(oldp+1215,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 0xaU))));
            tracep->chgBit(oldp+1216,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 9U))));
            tracep->chgBit(oldp+1217,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 8U))));
            tracep->chgBit(oldp+1218,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x10U] 
                                             >> 7U))));
            tracep->chgIData(oldp+1219,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                          << 0x1fU) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1aU] 
                                            >> 1U))),32);
            tracep->chgCData(oldp+1220,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1aU] 
                                                << 1U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x19U] 
                                                  >> 0x1fU)))),2);
            tracep->chgCData(oldp+1221,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1aU] 
                                                << 4U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x19U] 
                                                  >> 0x1cU)))),3);
            tracep->chgQData(oldp+1222,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x17U])) 
                                          << 0x24U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x16U])) 
                                             << 4U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U])) 
                                               >> 0x1cU)))),64);
            tracep->chgQData(oldp+1224,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x19U])) 
                                          << 0x24U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x18U])) 
                                             << 4U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x17U])) 
                                               >> 0x1cU)))),64);
            tracep->chgCData(oldp+1226,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x16U] 
                                                << 6U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                                  >> 0x1aU)))),2);
            tracep->chgBit(oldp+1227,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x19U))));
            tracep->chgBit(oldp+1228,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x18U))));
            tracep->chgBit(oldp+1229,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x17U))));
            tracep->chgBit(oldp+1230,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x16U))));
            tracep->chgBit(oldp+1231,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x15U))));
            tracep->chgBit(oldp+1232,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x15U] 
                                             >> 0x14U))));
            tracep->chgIData(oldp+1233,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                          << 0x12U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1fU] 
                                            >> 0xeU))),32);
            tracep->chgCData(oldp+1234,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                                << 0x14U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1fU] 
                                                  >> 0xcU)))),2);
            tracep->chgCData(oldp+1235,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                                << 0x17U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1fU] 
                                                  >> 9U)))),3);
            tracep->chgQData(oldp+1236,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1dU])) 
                                          << 0x37U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1cU])) 
                                             << 0x17U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU])) 
                                               >> 9U)))),64);
            tracep->chgQData(oldp+1238,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1fU])) 
                                          << 0x37U) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1eU])) 
                                             << 0x17U) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1dU])) 
                                               >> 9U)))),64);
            tracep->chgCData(oldp+1240,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1cU] 
                                                << 0x19U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                                  >> 7U)))),2);
            tracep->chgBit(oldp+1241,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 6U))));
            tracep->chgBit(oldp+1242,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 5U))));
            tracep->chgBit(oldp+1243,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 4U))));
            tracep->chgBit(oldp+1244,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 3U))));
            tracep->chgBit(oldp+1245,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 2U))));
            tracep->chgBit(oldp+1246,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x1bU] 
                                             >> 1U))));
            tracep->chgIData(oldp+1247,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                          << 5U) | 
                                         (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x24U] 
                                          >> 0x1bU))),32);
            tracep->chgCData(oldp+1248,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                                << 7U) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x24U] 
                                                  >> 0x19U)))),2);
            tracep->chgCData(oldp+1249,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                                << 0xaU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x24U] 
                                                  >> 0x16U)))),3);
            tracep->chgQData(oldp+1250,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x22U])) 
                                          << 0x2aU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x21U])) 
                                             << 0xaU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U])) 
                                               >> 0x16U)))),64);
            tracep->chgQData(oldp+1252,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x24U])) 
                                          << 0x2aU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x23U])) 
                                             << 0xaU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x22U])) 
                                               >> 0x16U)))),64);
            tracep->chgCData(oldp+1254,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x21U] 
                                                << 0xcU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                                  >> 0x14U)))),2);
            tracep->chgBit(oldp+1255,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0x13U))));
            tracep->chgBit(oldp+1256,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1257,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1258,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1259,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0xfU))));
            tracep->chgBit(oldp+1260,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x20U] 
                                             >> 0xeU))));
            tracep->chgIData(oldp+1261,(((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2bU] 
                                          << 0x18U) 
                                         | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2aU] 
                                            >> 8U))),32);
            tracep->chgCData(oldp+1262,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2bU] 
                                                << 0x1aU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2aU] 
                                                  >> 6U)))),2);
            tracep->chgCData(oldp+1263,((7U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2bU] 
                                                << 0x1dU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2aU] 
                                                  >> 3U)))),3);
            tracep->chgQData(oldp+1264,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x28U])) 
                                          << 0x3dU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x27U])) 
                                             << 0x1dU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x26U])) 
                                               >> 3U)))),64);
            tracep->chgQData(oldp+1266,((((QData)((IData)(
                                                          vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x2aU])) 
                                          << 0x3dU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x29U])) 
                                             << 0x1dU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x28U])) 
                                               >> 3U)))),64);
            tracep->chgCData(oldp+1268,((3U & ((vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x27U] 
                                                << 0x1fU) 
                                               | (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x26U] 
                                                  >> 1U)))),2);
            tracep->chgBit(oldp+1269,((1U & vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x26U])));
            tracep->chgBit(oldp+1270,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                             >> 0x1fU))));
            tracep->chgBit(oldp+1271,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                             >> 0x1eU))));
            tracep->chgBit(oldp+1272,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                             >> 0x1dU))));
            tracep->chgBit(oldp+1273,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                             >> 0x1cU))));
            tracep->chgBit(oldp+1274,((1U & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__fifo_commit_i__DOT__mem_q[0x25U] 
                                             >> 0x1bU))));
            tracep->chgBit(oldp+1275,((1U & ((~ (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                                 >> 0xeU)) 
                                             & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                                >> 0x12U)))));
            tracep->chgBit(oldp+1276,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__i_counter__DOT__counter_q) 
                                             >> 4U))));
            tracep->chgCData(oldp+1277,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__i_counter__DOT__counter_q),5);
            tracep->chgCData(oldp+1278,(((1U & ((~ 
                                                 (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                                  >> 0xeU)) 
                                                & (vlTOPp->ariane_testharness__DOT__i_ariane__DOT__cvxif_req[2U] 
                                                   >> 0x12U)))
                                          ? 0U : (0x1fU 
                                                  & ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__load_i)
                                                      ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__d_i)
                                                      : 
                                                     ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__down_i)
                                                       ? 
                                                      ((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__i_counter__DOT__counter_q) 
                                                       - (IData)(1U))
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__gen_example_coprocessor__DOT__i_cvxif_coprocessor__DOT__counter_i__DOT__i_counter__DOT__counter_q))))))),5);
            tracep->chgCData(oldp+1279,(vlSymsp->TOP__ariane_testharness__DOT__master__BRA__8__KET__.b_id),5);
            tracep->chgBit(oldp+1280,(vlSymsp->TOP__ariane_testharness__DOT__master__BRA__8__KET__.b_valid));
            tracep->chgCData(oldp+1281,(vlSymsp->TOP__ariane_testharness__DOT__master__BRA__8__KET__.r_id),5);
            tracep->chgQData(oldp+1282,(vlSymsp->TOP__ariane_testharness__DOT__master__BRA__8__KET__.r_data),64);
            tracep->chgBit(oldp+1284,(vlSymsp->TOP__ariane_testharness__DOT__master__BRA__8__KET__.r_valid));
            tracep->chgCData(oldp+1285,(vlSymsp->TOP__ariane_testharness__DOT__dram_delayed.b_id),5);
            tracep->chgBit(oldp+1286,(vlSymsp->TOP__ariane_testharness__DOT__dram_delayed.b_valid));
            tracep->chgCData(oldp+1287,(vlSymsp->TOP__ariane_testharness__DOT__dram_delayed.r_id),5);
            tracep->chgQData(oldp+1288,(vlSymsp->TOP__ariane_testharness__DOT__dram_delayed.r_data),64);
            tracep->chgBit(oldp+1290,(vlSymsp->TOP__ariane_testharness__DOT__dram_delayed.r_valid));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgCData(oldp+1291,((0x7fU & (IData)(
                                                         (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_req 
                                                          >> 0x22U)))),7);
            tracep->chgCData(oldp+1292,((3U & (IData)(
                                                      (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_req 
                                                       >> 0x20U)))),2);
            tracep->chgIData(oldp+1293,((IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_req)),32);
            tracep->chgBit(oldp+1294,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_req_ready));
            tracep->chgBit(oldp+1295,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_req_valid));
            tracep->chgIData(oldp+1296,((IData)((vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__data_dst_q 
                                                 >> 2U))),32);
            tracep->chgCData(oldp+1297,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__data_dst_q))),2);
            tracep->chgBit(oldp+1298,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_resp_valid));
            tracep->chgCData(oldp+1299,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__state_q),3);
            tracep->chgCData(oldp+1300,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__address_q),7);
            tracep->chgIData(oldp+1301,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__data_q),32);
            tracep->chgCData(oldp+1302,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__error_q),2);
            tracep->chgCData(oldp+1303,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__tap_state_q),4);
            tracep->chgBit(oldp+1304,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__req_src_q));
            tracep->chgCData(oldp+1305,((0x7fU & (IData)(
                                                         (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__data_src_q 
                                                          >> 0x22U)))),7);
            tracep->chgCData(oldp+1306,((3U & (IData)(
                                                      (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__data_src_q 
                                                       >> 0x20U)))),2);
            tracep->chgIData(oldp+1307,((IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__data_src_q)),32);
            tracep->chgBit(oldp+1308,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__ack_src_q));
            tracep->chgBit(oldp+1309,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_src__DOT__ack_q));
            tracep->chgBit(oldp+1310,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__ack_dst_q));
            tracep->chgBit(oldp+1311,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__req_dst_q));
            tracep->chgBit(oldp+1312,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__req_q0));
            tracep->chgBit(oldp+1313,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_dst__DOT__req_q1));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgBit(oldp+1314,(vlTOPp->ariane_testharness__DOT__debug_req_valid));
            tracep->chgBit(oldp+1315,(vlTOPp->ariane_testharness__DOT__jtag_req_valid));
            tracep->chgBit(oldp+1316,(vlTOPp->ariane_testharness__DOT__jtag_resp_ready));
            tracep->chgBit(oldp+1317,(vlTOPp->ariane_testharness__DOT__jtag_resp_valid));
            tracep->chgIData(oldp+1318,((IData)((vlTOPp->ariane_testharness__DOT__debug_resp 
                                                 >> 2U))),32);
            tracep->chgCData(oldp+1319,((3U & (IData)(vlTOPp->ariane_testharness__DOT__debug_resp))),2);
            tracep->chgBit(oldp+1320,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_req__DOT__i_dst__DOT__ack_dst_q));
            tracep->chgBit(oldp+1321,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_src__DOT__req_src_q));
            tracep->chgIData(oldp+1322,((IData)((vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_src__DOT__data_src_q 
                                                 >> 2U))),32);
            tracep->chgCData(oldp+1323,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_cdc__DOT__i_cdc_resp__DOT__i_src__DOT__data_src_q))),2);
            tracep->chgBit(oldp+1324,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__clear_resumeack));
            tracep->chgBit(oldp+1325,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__sbaddress_write_valid));
            tracep->chgBit(oldp+1326,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__sbdata_read_valid));
            tracep->chgBit(oldp+1327,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__sbdata_write_valid));
            tracep->chgBit(oldp+1328,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__resp_queue_push));
            tracep->chgBit(oldp+1329,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__resp_queue_pop));
            tracep->chgIData(oldp+1330,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__resp_queue_data),32);
            tracep->chgSData(oldp+1331,((0x1ffU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                                   >> 0x17U))),9);
            tracep->chgBit(oldp+1332,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0x16U))));
            tracep->chgCData(oldp+1333,((3U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                               >> 0x14U))),2);
            tracep->chgBit(oldp+1334,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0x13U))));
            tracep->chgBit(oldp+1335,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0x12U))));
            tracep->chgBit(oldp+1336,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1337,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1338,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xfU))));
            tracep->chgBit(oldp+1339,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xeU))));
            tracep->chgBit(oldp+1340,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xdU))));
            tracep->chgBit(oldp+1341,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xcU))));
            tracep->chgBit(oldp+1342,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xbU))));
            tracep->chgBit(oldp+1343,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 0xaU))));
            tracep->chgBit(oldp+1344,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 9U))));
            tracep->chgBit(oldp+1345,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 8U))));
            tracep->chgBit(oldp+1346,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 7U))));
            tracep->chgBit(oldp+1347,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 6U))));
            tracep->chgBit(oldp+1348,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 5U))));
            tracep->chgBit(oldp+1349,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus 
                                             >> 4U))));
            tracep->chgCData(oldp+1350,((0xfU & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmstatus)),4);
            tracep->chgBit(oldp+1351,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1fU))));
            tracep->chgBit(oldp+1352,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1eU))));
            tracep->chgBit(oldp+1353,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1dU))));
            tracep->chgBit(oldp+1354,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1cU))));
            tracep->chgBit(oldp+1355,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1bU))));
            tracep->chgBit(oldp+1356,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 0x1aU))));
            tracep->chgSData(oldp+1357,((0x3ffU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                                   >> 0x10U))),10);
            tracep->chgSData(oldp+1358,((0x3ffU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                                   >> 6U))),10);
            tracep->chgCData(oldp+1359,((3U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                               >> 4U))),2);
            tracep->chgBit(oldp+1360,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 3U))));
            tracep->chgBit(oldp+1361,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 2U))));
            tracep->chgBit(oldp+1362,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d 
                                             >> 1U))));
            tracep->chgBit(oldp+1363,((1U & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__dmcontrol_d)));
            tracep->chgCData(oldp+1364,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                               >> 0x1dU))),3);
            tracep->chgCData(oldp+1365,((0x1fU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                                  >> 0x18U))),5);
            tracep->chgSData(oldp+1366,((0x7ffU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                                   >> 0xdU))),11);
            tracep->chgBit(oldp+1367,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                             >> 0xcU))));
            tracep->chgBit(oldp+1368,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                             >> 0xbU))));
            tracep->chgCData(oldp+1369,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                               >> 8U))),3);
            tracep->chgCData(oldp+1370,((0xfU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs 
                                                 >> 4U))),4);
            tracep->chgCData(oldp+1371,((0xfU & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractcs)),4);
            tracep->chgCData(oldp+1372,((0xffU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__command_d 
                                                  >> 0x18U))),8);
            tracep->chgIData(oldp+1373,((0xffffffU 
                                         & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__command_d)),24);
            tracep->chgBit(oldp+1374,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__cmd_valid_d));
            tracep->chgSData(oldp+1375,((0xffffU & 
                                         (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractauto_d 
                                          >> 0x10U))),16);
            tracep->chgCData(oldp+1376,((0xfU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractauto_d 
                                                 >> 0xcU))),4);
            tracep->chgSData(oldp+1377,((0xfffU & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__abstractauto_d)),12);
            tracep->chgCData(oldp+1378,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                               >> 0x1dU))),3);
            tracep->chgCData(oldp+1379,((0x3fU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                                  >> 0x17U))),6);
            tracep->chgBit(oldp+1380,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 0x16U))));
            tracep->chgBit(oldp+1381,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 0x15U))));
            tracep->chgBit(oldp+1382,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 0x14U))));
            tracep->chgCData(oldp+1383,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                               >> 0x11U))),3);
            tracep->chgBit(oldp+1384,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1385,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 0xfU))));
            tracep->chgCData(oldp+1386,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                               >> 0xcU))),3);
            tracep->chgCData(oldp+1387,((0x7fU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                                  >> 5U))),7);
            tracep->chgBit(oldp+1388,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 4U))));
            tracep->chgBit(oldp+1389,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 3U))));
            tracep->chgBit(oldp+1390,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 2U))));
            tracep->chgBit(oldp+1391,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d 
                                             >> 1U))));
            tracep->chgBit(oldp+1392,((1U & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs_d)));
            tracep->chgBit(oldp+1393,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__havereset_d_aligned))));
            tracep->chgIData(oldp+1394,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[0U]),32);
            tracep->chgIData(oldp+1395,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[1U]),32);
            tracep->chgIData(oldp+1396,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[2U]),32);
            tracep->chgIData(oldp+1397,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[3U]),32);
            tracep->chgIData(oldp+1398,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[4U]),32);
            tracep->chgIData(oldp+1399,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[5U]),32);
            tracep->chgIData(oldp+1400,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[6U]),32);
            tracep->chgIData(oldp+1401,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__progbuf_d[7U]),32);
            tracep->chgCData(oldp+1402,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__havereset_d_aligned),2);
            tracep->chgCData(oldp+1403,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                               >> 0x1dU))),3);
            tracep->chgCData(oldp+1404,((0x3fU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                                  >> 0x17U))),6);
            tracep->chgBit(oldp+1405,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 0x16U))));
            tracep->chgBit(oldp+1406,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 0x15U))));
            tracep->chgBit(oldp+1407,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 0x14U))));
            tracep->chgCData(oldp+1408,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                               >> 0x11U))),3);
            tracep->chgBit(oldp+1409,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1410,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 0xfU))));
            tracep->chgCData(oldp+1411,((7U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                               >> 0xcU))),3);
            tracep->chgCData(oldp+1412,((0x7fU & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                                  >> 5U))),7);
            tracep->chgBit(oldp+1413,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 4U))));
            tracep->chgBit(oldp+1414,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 3U))));
            tracep->chgBit(oldp+1415,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 2U))));
            tracep->chgBit(oldp+1416,((1U & (vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs 
                                             >> 1U))));
            tracep->chgBit(oldp+1417,((1U & vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__sbcs)));
            tracep->chgBit(oldp+1418,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__gate_clock));
            tracep->chgBit(oldp+1419,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__read_pointer_n));
            tracep->chgBit(oldp+1420,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__write_pointer_n));
            tracep->chgCData(oldp+1421,(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__status_cnt_n),2);
            tracep->chgIData(oldp+1422,((IData)(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__mem_n)),32);
            tracep->chgIData(oldp+1423,((IData)((vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_csrs__DOT__i_fifo__DOT__i_fifo_v3__DOT__mem_n 
                                                 >> 0x20U))),32);
            tracep->chgCData(oldp+1424,((3U & (IData)(vlTOPp->ariane_testharness__DOT__debug_resp))),2);
            tracep->chgIData(oldp+1425,((IData)((vlTOPp->ariane_testharness__DOT__debug_resp 
                                                 >> 2U))),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[8U])) {
            tracep->chgBit(oldp+1426,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dmi_access));
            tracep->chgBit(oldp+1427,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dtmcs_select));
            tracep->chgBit(oldp+1428,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1429,((1U & (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q))));
            tracep->chgQData(oldp+1430,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q),41);
            tracep->chgCData(oldp+1432,((0x7fU & (IData)(
                                                         (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q 
                                                          >> 0x22U)))),7);
            tracep->chgIData(oldp+1433,((IData)((vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q 
                                                 >> 2U))),32);
            tracep->chgCData(oldp+1434,((3U & (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q))),2);
            tracep->chgCData(oldp+1435,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_shift_q),5);
            tracep->chgCData(oldp+1436,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_q),5);
            tracep->chgIData(oldp+1437,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__idcode_q),32);
            tracep->chgBit(oldp+1438,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__idcode_select));
            tracep->chgBit(oldp+1439,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__bypass_select));
            tracep->chgSData(oldp+1440,((0x3fffU & 
                                         (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                          >> 0x12U))),14);
            tracep->chgBit(oldp+1441,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1442,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1443,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                             >> 0xfU))));
            tracep->chgCData(oldp+1444,((7U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                               >> 0xcU))),3);
            tracep->chgCData(oldp+1445,((3U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                               >> 0xaU))),2);
            tracep->chgCData(oldp+1446,((0x3fU & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q 
                                                  >> 4U))),6);
            tracep->chgCData(oldp+1447,((0xfU & vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q)),4);
            tracep->chgBit(oldp+1448,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__bypass_q));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[9U])) {
            tracep->chgBit(oldp+1449,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__test_logic_reset));
            tracep->chgBit(oldp+1450,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__shift_dr));
            tracep->chgBit(oldp+1451,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__update_dr));
            tracep->chgBit(oldp+1452,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__capture_dr));
            tracep->chgCData(oldp+1453,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__state_d),3);
            tracep->chgQData(oldp+1454,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_d),41);
            tracep->chgCData(oldp+1456,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__address_d),7);
            tracep->chgIData(oldp+1457,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__data_d),32);
            tracep->chgBit(oldp+1458,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__error_dmi_busy));
            tracep->chgCData(oldp+1459,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__error_d),2);
            tracep->chgCData(oldp+1460,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__tap_state_d),4);
            tracep->chgCData(oldp+1461,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_shift_d),5);
            tracep->chgCData(oldp+1462,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_d),5);
            tracep->chgBit(oldp+1463,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__capture_ir));
            tracep->chgBit(oldp+1464,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__shift_ir));
            tracep->chgBit(oldp+1465,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__update_ir));
            tracep->chgIData(oldp+1466,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__idcode_d),32);
            tracep->chgSData(oldp+1467,((0x3fffU & 
                                         (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                          >> 0x12U))),14);
            tracep->chgBit(oldp+1468,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                             >> 0x11U))));
            tracep->chgBit(oldp+1469,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                             >> 0x10U))));
            tracep->chgBit(oldp+1470,((1U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                             >> 0xfU))));
            tracep->chgCData(oldp+1471,((7U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                               >> 0xcU))),3);
            tracep->chgCData(oldp+1472,((3U & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                               >> 0xaU))),2);
            tracep->chgCData(oldp+1473,((0x3fU & (vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d 
                                                  >> 4U))),6);
            tracep->chgCData(oldp+1474,((0xfU & vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_d)),4);
            tracep->chgBit(oldp+1475,(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__bypass_d));
        }
        tracep->chgBit(oldp+1476,(vlTOPp->clk_i));
        tracep->chgBit(oldp+1477,(vlTOPp->rtc_i));
        tracep->chgBit(oldp+1478,(vlTOPp->rst_ni));
        tracep->chgIData(oldp+1479,(vlTOPp->exit_o),32);
        tracep->chgBit(oldp+1480,(vlTOPp->ariane_testharness__DOT__ndmreset_n));
        tracep->chgBit(oldp+1481,(vlTOPp->ariane_testharness__DOT__jtag_TDO_data));
        tracep->chgBit(oldp+1482,(vlTOPp->ariane_testharness__DOT__jtag_TDO_driven));
        tracep->chgBit(oldp+1483,(((1U & vlTOPp->ariane_testharness__DOT__jtag_enable)
                                    ? (IData)(vlTOPp->ariane_testharness__DOT__jtag_resp_ready)
                                    : (IData)(vlTOPp->ariane_testharness__DOT__genblk1__DOT__i_SimDTM__DOT_____05Fdebug_resp_ready))));
        tracep->chgQData(oldp+1484,(((IData)(vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_mem__DOT__fwd_rom_q)
                                      ? vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_mem__DOT__rom_rdata
                                      : vlTOPp->ariane_testharness__DOT__i_dm_top__DOT__i_dm_mem__DOT__rdata_q)),64);
        tracep->chgBit(oldp+1486,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_rstgen_main__DOT__i_rstgen_bypass__DOT__synch_regs_q) 
                                         >> 3U))));
        tracep->chgCData(oldp+1487,(vlTOPp->ariane_testharness__DOT__i_rstgen_main__DOT__i_rstgen_bypass__DOT__synch_regs_q),4);
        tracep->chgBit(oldp+1488,((1U & (~ (IData)(vlTOPp->rst_ni)))));
        tracep->chgBit(oldp+1489,((1U & ((IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__shift_ir)
                                          ? (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_shift_q)
                                          : ((1U == (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_q))
                                              ? vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__idcode_q
                                              : ((0x10U 
                                                  == (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_q))
                                                  ? vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__dtmcs_q
                                                  : 
                                                 ((0x11U 
                                                   == (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__jtag_ir_q))
                                                   ? (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__dr_q)
                                                   : (IData)(vlTOPp->ariane_testharness__DOT__i_dmi_jtag__DOT__i_dmi_jtag_tap__DOT__bypass_q))))))));
        tracep->chgCData(oldp+1490,((0xfU & ((1U & 
                                              ((vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__slv_reqs[3U] 
                                                >> 4U) 
                                               & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__req_nodes)))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes))
                                                  ? (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)
                                                  : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))
                                              : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__rr_q)))),4);
        tracep->chgCData(oldp+1491,((0xfU & ((1U & 
                                              (vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__slv_reqs[0U] 
                                               & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__req_nodes)))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes))
                                                  ? (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)
                                                  : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))
                                              : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__0__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__rr_q)))),4);
        tracep->chgCData(oldp+1492,((0xfU & ((1U & 
                                              ((vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__slv_reqs[0xbU] 
                                                >> 0x1dU) 
                                               & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__req_nodes)))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes))
                                                  ? (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)
                                                  : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))
                                              : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_b_mux__DOT__gen_arbiter__DOT__rr_q)))),4);
        tracep->chgCData(oldp+1493,((0xfU & ((1U & 
                                              ((vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__slv_reqs[8U] 
                                                >> 0x19U) 
                                               & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__req_nodes)))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes))
                                                  ? (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)
                                                  : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))
                                              : (IData)(vlTOPp->ariane_testharness__DOT__i_axi_xbar__DOT__i_xbar__DOT__gen_slv_port_demux__BRA__1__KET____DOT__i_axi_demux__DOT__gen_demux__DOT__i_r_mux__DOT__gen_arbiter__DOT__rr_q)))),4);
        tracep->chgQData(oldp+1494,(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__id_stage_i__DOT__decoder_i__DOT__interrupt_cause),64);
        tracep->chgCData(oldp+1496,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__rd_req_q)
                                      ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__rd_vld_bits)
                                      : (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__0__KET____DOT__i_wt_dcache_ctrl__DOT__vld_data_q))),8);
        tracep->chgCData(oldp+1497,(((IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__rd_req_q)
                                      ? (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__rd_vld_bits)
                                      : (IData)(vlTOPp->ariane_testharness__DOT__i_ariane__DOT__i_cva6__DOT__i_cache_subsystem__DOT__i_wt_dcache__DOT__gen_rd_ports__BRA__1__KET____DOT__i_wt_dcache_ctrl__DOT__vld_data_q))),8);
    }
}

void Variane_testharness::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Variane_testharness__Syms* __restrict vlSymsp = static_cast<Variane_testharness__Syms*>(userp);
    Variane_testharness* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
        vlTOPp->__Vm_traceActivity[7U] = 0U;
        vlTOPp->__Vm_traceActivity[8U] = 0U;
        vlTOPp->__Vm_traceActivity[9U] = 0U;
    }
}
