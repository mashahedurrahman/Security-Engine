// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Variane_testharness.h for the primary calling header

#ifndef _VARIANE_TESTHARNESS_CVXIF_INSTR_PKG_H_
#define _VARIANE_TESTHARNESS_CVXIF_INSTR_PKG_H_  // guard

#include "verilated_heavy.h"
#include "Variane_testharness__Dpi.h"

//==========

class Variane_testharness__Syms;
class Variane_testharness_VerilatedVcd;


//----------

VL_MODULE(Variane_testharness_cvxif_instr_pkg) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Variane_testharness__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    // Begin mtask footprint all: 
    WData/*69:0*/ __PVT__CoproInstr[2][3];
    // enum WData __PVT__CoproInstr  //wide
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Variane_testharness_cvxif_instr_pkg);  ///< Copying not allowed
  public:
    Variane_testharness_cvxif_instr_pkg(const char* name = "TOP");
    ~Variane_testharness_cvxif_instr_pkg();
    
    // INTERNAL METHODS
    void __Vconfigure(Variane_testharness__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__cvxif_instr_pkg__1(Variane_testharness__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
