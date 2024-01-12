// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Variane_testharness__Syms.h"
#include "Variane_testharness.h"
#include "Variane_testharness___024unit.h"
#include "Variane_testharness_uart_bus.h"
#include "Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1.h"
#include "Variane_testharness_REG_BUS__A20_D20.h"
#include "Variane_testharness_cvxif_instr_pkg.h"



// FUNCTIONS
Variane_testharness__Syms::Variane_testharness__Syms(Variane_testharness* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP____024unit(Verilated::catName(topp->name(), "$unit"))
    , TOP__ariane_testharness__DOT__dram_delayed(Verilated::catName(topp->name(), "ariane_testharness.dram_delayed"))
    , TOP__ariane_testharness__DOT__i_ariane_peripherals__DOT__reg_bus(Verilated::catName(topp->name(), "ariane_testharness.i_ariane_peripherals.reg_bus"))
    , TOP__ariane_testharness__DOT__i_uart_bus(Verilated::catName(topp->name(), "ariane_testharness.i_uart_bus"))
    , TOP__ariane_testharness__DOT__master__BRA__2__KET__(Verilated::catName(topp->name(), "ariane_testharness.master[2]"))
    , TOP__ariane_testharness__DOT__master__BRA__3__KET__(Verilated::catName(topp->name(), "ariane_testharness.master[3]"))
    , TOP__ariane_testharness__DOT__master__BRA__8__KET__(Verilated::catName(topp->name(), "ariane_testharness.master[8]"))
    , TOP__ariane_testharness__DOT__master__BRA__9__KET__(Verilated::catName(topp->name(), "ariane_testharness.master[9]"))
    , TOP__cvxif_instr_pkg(Verilated::catName(topp->name(), "cvxif_instr_pkg"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT____024unit = &TOP____024unit;
    TOPp->__PVT__ariane_testharness__DOT__dram_delayed = &TOP__ariane_testharness__DOT__dram_delayed;
    TOPp->__PVT__ariane_testharness__DOT__i_ariane_peripherals__DOT__reg_bus = &TOP__ariane_testharness__DOT__i_ariane_peripherals__DOT__reg_bus;
    TOPp->__PVT__ariane_testharness__DOT__i_uart_bus = &TOP__ariane_testharness__DOT__i_uart_bus;
    TOPp->__PVT__ariane_testharness__DOT__master__BRA__2__KET__ = &TOP__ariane_testharness__DOT__master__BRA__2__KET__;
    TOPp->__PVT__ariane_testharness__DOT__master__BRA__3__KET__ = &TOP__ariane_testharness__DOT__master__BRA__3__KET__;
    TOPp->__PVT__ariane_testharness__DOT__master__BRA__8__KET__ = &TOP__ariane_testharness__DOT__master__BRA__8__KET__;
    TOPp->__PVT__ariane_testharness__DOT__master__BRA__9__KET__ = &TOP__ariane_testharness__DOT__master__BRA__9__KET__;
    TOPp->__PVT__cvxif_instr_pkg = &TOP__cvxif_instr_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP____024unit.__Vconfigure(this, true);
    TOP__ariane_testharness__DOT__dram_delayed.__Vconfigure(this, true);
    TOP__ariane_testharness__DOT__i_ariane_peripherals__DOT__reg_bus.__Vconfigure(this, true);
    TOP__ariane_testharness__DOT__i_uart_bus.__Vconfigure(this, true);
    TOP__ariane_testharness__DOT__master__BRA__2__KET__.__Vconfigure(this, false);
    TOP__ariane_testharness__DOT__master__BRA__3__KET__.__Vconfigure(this, false);
    TOP__ariane_testharness__DOT__master__BRA__8__KET__.__Vconfigure(this, false);
    TOP__ariane_testharness__DOT__master__BRA__9__KET__.__Vconfigure(this, false);
    TOP__cvxif_instr_pkg.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_ariane_testharness.configure(this, name(), "ariane_testharness", "ariane_testharness", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_ariane_testharness__p_assert.configure(this, name(), "ariane_testharness.p_assert", "p_assert", -12, VerilatedScope::SCOPE_OTHER);
    
    // Setup scope hierarchy
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
    }
}
