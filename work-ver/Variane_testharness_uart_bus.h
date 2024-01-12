// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Variane_testharness.h for the primary calling header

#ifndef _VARIANE_TESTHARNESS_UART_BUS_H_
#define _VARIANE_TESTHARNESS_UART_BUS_H_  // guard

#include "verilated_heavy.h"
#include "Variane_testharness__Dpi.h"

//==========

class Variane_testharness__Syms;
class Variane_testharness_VerilatedVcd;


//----------

VL_MODULE(Variane_testharness_uart_bus) {
  public:
    
    // PORTS
    // Begin mtask footprint all: 
    VL_IN8(rx,0,0);
    VL_OUT8(tx,0,0);
    VL_IN8(rx_en,0,0);
    
    // INTERNAL VARIABLES
  private:
    Variane_testharness__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Variane_testharness_uart_bus);  ///< Copying not allowed
  public:
    Variane_testharness_uart_bus(const char* name = "TOP");
    ~Variane_testharness_uart_bus();
    
    // INTERNAL METHODS
    void __Vconfigure(Variane_testharness__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
