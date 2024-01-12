// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Variane_testharness.h for the primary calling header

#ifndef _VARIANE_TESTHARNESS___024UNIT_H_
#define _VARIANE_TESTHARNESS___024UNIT_H_  // guard

#include "verilated_heavy.h"
#include "Variane_testharness__Dpi.h"

//==========

class Variane_testharness__Syms;
class Variane_testharness_VerilatedVcd;


//----------

VL_MODULE(Variane_testharness___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Variane_testharness__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Variane_testharness___024unit);  ///< Copying not allowed
  public:
    Variane_testharness___024unit(const char* name = "TOP");
    ~Variane_testharness___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Variane_testharness__Syms* symsp, bool first);
    void __Vdpiimwrap_debug_tick_TOP____024unit(CData/*0:0*/ (&debug_req_valid), CData/*0:0*/ debug_req_ready, IData/*31:0*/ (&debug_req_bits_addr), IData/*31:0*/ (&debug_req_bits_op), IData/*31:0*/ (&debug_req_bits_data), CData/*0:0*/ debug_resp_valid, CData/*0:0*/ (&debug_resp_ready), IData/*31:0*/ debug_resp_bits_resp, IData/*31:0*/ debug_resp_bits_data, IData/*31:0*/ (&debug_tick__Vfuncrtn));
    void __Vdpiimwrap_jtag_tick_TOP____024unit(CData/*0:0*/ (&jtag_TCK), CData/*0:0*/ (&jtag_TMS), CData/*0:0*/ (&jtag_TDI), CData/*0:0*/ (&jtag_TRSTn), CData/*0:0*/ jtag_TDO, IData/*31:0*/ (&jtag_tick__Vfuncrtn));
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
