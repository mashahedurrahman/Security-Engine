// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Variane_testharness.h for the primary calling header

#ifndef _VARIANE_TESTHARNESS_AXI_BUS__A40_AB40_AC5_AD1_H_
#define _VARIANE_TESTHARNESS_AXI_BUS__A40_AB40_AC5_AD1_H_  // guard

#include "verilated_heavy.h"
#include "Variane_testharness__Dpi.h"

//==========

class Variane_testharness__Syms;
class Variane_testharness_VerilatedVcd;


//----------

VL_MODULE(Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1) {
  public:
    
    // LOCAL SIGNALS
    // Begin mtask footprint all: 
    CData/*0:0*/ aw_ready;
    CData/*0:0*/ w_ready;
    CData/*4:0*/ b_id;
    CData/*0:0*/ b_valid;
    CData/*0:0*/ ar_ready;
    CData/*4:0*/ r_id;
    CData/*0:0*/ r_last;
    CData/*0:0*/ r_user;
    CData/*0:0*/ r_valid;
    QData/*63:0*/ r_data;
    
    // INTERNAL VARIABLES
  private:
    Variane_testharness__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1);  ///< Copying not allowed
  public:
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1(const char* name = "TOP");
    ~Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1();
    
    // INTERNAL METHODS
    void __Vconfigure(Variane_testharness__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
