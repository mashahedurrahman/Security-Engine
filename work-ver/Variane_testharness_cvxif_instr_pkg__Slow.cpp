// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Variane_testharness.h for the primary calling header

#include "Variane_testharness_cvxif_instr_pkg.h"
#include "Variane_testharness__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Variane_testharness_cvxif_instr_pkg) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Variane_testharness_cvxif_instr_pkg::__Vconfigure(Variane_testharness__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Variane_testharness_cvxif_instr_pkg::~Variane_testharness_cvxif_instr_pkg() {
}

void Variane_testharness_cvxif_instr_pkg::_initial__TOP__cvxif_instr_pkg__1(Variane_testharness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Variane_testharness_cvxif_instr_pkg::_initial__TOP__cvxif_instr_pkg__1\n"); );
    Variane_testharness* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[0U][0U] = 0x1fe0U;
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[0U][1U] = 0xac0U;
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[0U][2U] = 0U;
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[1U][0U] = 0x1ff0U;
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[1U][1U] = 0x16c0U;
    vlSymsp->TOP__cvxif_instr_pkg.__PVT__CoproInstr[1U][2U] = 0U;
}

void Variane_testharness_cvxif_instr_pkg::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Variane_testharness_cvxif_instr_pkg::_ctor_var_reset\n"); );
    // Body
}
