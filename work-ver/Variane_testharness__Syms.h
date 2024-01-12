// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VARIANE_TESTHARNESS__SYMS_H_
#define _VARIANE_TESTHARNESS__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Variane_testharness.h"
#include "Variane_testharness___024unit.h"
#include "Variane_testharness_uart_bus.h"
#include "Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1.h"
#include "Variane_testharness_REG_BUS__A20_D20.h"
#include "Variane_testharness_cvxif_instr_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Variane_testharness__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Variane_testharness*           TOPp;
    Variane_testharness___024unit  TOP____024unit;
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 TOP__ariane_testharness__DOT__dram_delayed;
    Variane_testharness_REG_BUS__A20_D20 TOP__ariane_testharness__DOT__i_ariane_peripherals__DOT__reg_bus;
    Variane_testharness_uart_bus   TOP__ariane_testharness__DOT__i_uart_bus;
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 TOP__ariane_testharness__DOT__master__BRA__2__KET__;
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 TOP__ariane_testharness__DOT__master__BRA__3__KET__;
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 TOP__ariane_testharness__DOT__master__BRA__8__KET__;
    Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 TOP__ariane_testharness__DOT__master__BRA__9__KET__;
    Variane_testharness_cvxif_instr_pkg TOP__cvxif_instr_pkg;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_ariane_testharness;
    VerilatedScope __Vscope_ariane_testharness__p_assert;
    
    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;
    
    // CREATORS
    Variane_testharness__Syms(Variane_testharness* topp, const char* namep);
    ~Variane_testharness__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
