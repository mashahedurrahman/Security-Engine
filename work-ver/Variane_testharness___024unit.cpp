// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Variane_testharness.h for the primary calling header

#include "Variane_testharness___024unit.h"
#include "Variane_testharness__Syms.h"

#include "verilated_dpi.h"

//==========

VL_INLINE_OPT void Variane_testharness___024unit::__Vdpiimwrap_debug_tick_TOP____024unit(CData/*0:0*/ (&debug_req_valid), CData/*0:0*/ debug_req_ready, IData/*31:0*/ (&debug_req_bits_addr), IData/*31:0*/ (&debug_req_bits_op), IData/*31:0*/ (&debug_req_bits_data), CData/*0:0*/ debug_resp_valid, CData/*0:0*/ (&debug_resp_ready), IData/*31:0*/ debug_resp_bits_resp, IData/*31:0*/ debug_resp_bits_data, IData/*31:0*/ (&debug_tick__Vfuncrtn)) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Variane_testharness___024unit::__Vdpiimwrap_debug_tick_TOP____024unit\n"); );
    // Body
    svBit debug_req_valid__Vcvt;
    svBit debug_req_ready__Vcvt;
    debug_req_ready__Vcvt = debug_req_ready;
    int debug_req_bits_addr__Vcvt;
    int debug_req_bits_op__Vcvt;
    int debug_req_bits_data__Vcvt;
    svBit debug_resp_valid__Vcvt;
    debug_resp_valid__Vcvt = debug_resp_valid;
    svBit debug_resp_ready__Vcvt;
    int debug_resp_bits_resp__Vcvt;
    debug_resp_bits_resp__Vcvt = debug_resp_bits_resp;
    int debug_resp_bits_data__Vcvt;
    debug_resp_bits_data__Vcvt = debug_resp_bits_data;
    int debug_tick__Vfuncrtn__Vcvt;
    debug_tick__Vfuncrtn__Vcvt = debug_tick(&debug_req_valid__Vcvt, debug_req_ready__Vcvt, &debug_req_bits_addr__Vcvt, &debug_req_bits_op__Vcvt, &debug_req_bits_data__Vcvt, debug_resp_valid__Vcvt, &debug_resp_ready__Vcvt, debug_resp_bits_resp__Vcvt, debug_resp_bits_data__Vcvt);
    debug_req_valid = (1U & debug_req_valid__Vcvt);
    debug_req_bits_addr = debug_req_bits_addr__Vcvt;
    debug_req_bits_op = debug_req_bits_op__Vcvt;
    debug_req_bits_data = debug_req_bits_data__Vcvt;
    debug_resp_ready = (1U & debug_resp_ready__Vcvt);
    debug_tick__Vfuncrtn = debug_tick__Vfuncrtn__Vcvt;
}

VL_INLINE_OPT void Variane_testharness___024unit::__Vdpiimwrap_jtag_tick_TOP____024unit(CData/*0:0*/ (&jtag_TCK), CData/*0:0*/ (&jtag_TMS), CData/*0:0*/ (&jtag_TDI), CData/*0:0*/ (&jtag_TRSTn), CData/*0:0*/ jtag_TDO, IData/*31:0*/ (&jtag_tick__Vfuncrtn)) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Variane_testharness___024unit::__Vdpiimwrap_jtag_tick_TOP____024unit\n"); );
    // Body
    svBit jtag_TCK__Vcvt;
    svBit jtag_TMS__Vcvt;
    svBit jtag_TDI__Vcvt;
    svBit jtag_TRSTn__Vcvt;
    svBit jtag_TDO__Vcvt;
    jtag_TDO__Vcvt = jtag_TDO;
    int jtag_tick__Vfuncrtn__Vcvt;
    jtag_tick__Vfuncrtn__Vcvt = jtag_tick(&jtag_TCK__Vcvt, &jtag_TMS__Vcvt, &jtag_TDI__Vcvt, &jtag_TRSTn__Vcvt, jtag_TDO__Vcvt);
    jtag_TCK = (1U & jtag_TCK__Vcvt);
    jtag_TMS = (1U & jtag_TMS__Vcvt);
    jtag_TDI = (1U & jtag_TDI__Vcvt);
    jtag_TRSTn = (1U & jtag_TRSTn__Vcvt);
    jtag_tick__Vfuncrtn = jtag_tick__Vfuncrtn__Vcvt;
}
