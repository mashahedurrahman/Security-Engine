// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Variane_testharness.h for the primary calling header

#include "Variane_testharness_REG_BUS__A20_D20.h"
#include "Variane_testharness__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Variane_testharness_REG_BUS__A20_D20) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Variane_testharness_REG_BUS__A20_D20::__Vconfigure(Variane_testharness__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Variane_testharness_REG_BUS__A20_D20::~Variane_testharness_REG_BUS__A20_D20() {
}

void Variane_testharness_REG_BUS__A20_D20::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Variane_testharness_REG_BUS__A20_D20::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
}
