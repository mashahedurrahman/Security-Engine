// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    
    // DPI IMPORTS
    // DPI import at /home/mashahed/projects/cva6/cva6/corev_apu/tb/common/SimDTM.sv:4:29
    extern int debug_tick(svBit* debug_req_valid, svBit debug_req_ready, int* debug_req_bits_addr, int* debug_req_bits_op, int* debug_req_bits_data, svBit debug_resp_valid, svBit* debug_resp_ready, int debug_resp_bits_resp, int debug_resp_bits_data);
    // DPI import at /home/mashahed/projects/cva6/cva6/corev_apu/tb/common/SimJTAG.sv:3:29
    extern int jtag_tick(svBit* jtag_TCK, svBit* jtag_TMS, svBit* jtag_TDI, svBit* jtag_TRSTn, svBit jtag_TDO);
    
#ifdef __cplusplus
}
#endif
