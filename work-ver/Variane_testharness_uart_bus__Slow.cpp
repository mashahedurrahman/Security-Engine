// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Variane_testharness.h for the primary calling header

#include "Variane_testharness_uart_bus.h"
#include "Variane_testharness__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Variane_testharness_uart_bus) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Variane_testharness_uart_bus::__Vconfigure(Variane_testharness__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Variane_testharness_uart_bus::~Variane_testharness_uart_bus() {
}

void Variane_testharness_uart_bus::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Variane_testharness_uart_bus::_ctor_var_reset\n"); );
    // Body
    rx = VL_RAND_RESET_I(1);
    tx = VL_RAND_RESET_I(1);
    rx_en = VL_RAND_RESET_I(1);
}
