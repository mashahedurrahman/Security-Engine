// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Variane_testharness.h for the primary calling header

#include "Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1.h"
#include "Variane_testharness__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1::__Vconfigure(Variane_testharness__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1::~Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1() {
}

void Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1::_ctor_var_reset\n"); );
    // Body
    aw_ready = VL_RAND_RESET_I(1);
    w_ready = VL_RAND_RESET_I(1);
    b_id = VL_RAND_RESET_I(5);
    b_valid = VL_RAND_RESET_I(1);
    ar_ready = VL_RAND_RESET_I(1);
    r_id = VL_RAND_RESET_I(5);
    r_data = VL_RAND_RESET_Q(64);
    r_last = VL_RAND_RESET_I(1);
    r_user = VL_RAND_RESET_I(1);
    r_valid = VL_RAND_RESET_I(1);
}
