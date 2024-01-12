# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Variane_testharness.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Threaded output mode?  0/1/N threads (from --threads)
VM_THREADS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing threaded output mode?  0/1/N threads (from --trace-thread)
VM_TRACE_THREADS = 0
# Separate FST writer thread? 0/1 (from --trace-fst with --trace-thread > 0)
VM_TRACE_FST_WRITER_THREAD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Variane_testharness \
	Variane_testharness__1 \
	Variane_testharness__2 \
	Variane_testharness__3 \
	Variane_testharness__4 \
	Variane_testharness__5 \
	Variane_testharness__6 \
	Variane_testharness__7 \
	Variane_testharness__8 \
	Variane_testharness__9 \
	Variane_testharness__10 \
	Variane_testharness__11 \
	Variane_testharness__12 \
	Variane_testharness__13 \
	Variane_testharness__14 \
	Variane_testharness__15 \
	Variane_testharness__16 \
	Variane_testharness__17 \
	Variane_testharness__18 \
	Variane_testharness__19 \
	Variane_testharness__20 \
	Variane_testharness__21 \
	Variane_testharness___024unit \
	Variane_testharness_uart_bus \
	Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1 \
	Variane_testharness_REG_BUS__A20_D20 \
	Variane_testharness_cvxif_instr_pkg \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Variane_testharness__Slow \
	Variane_testharness__1__Slow \
	Variane_testharness__2__Slow \
	Variane_testharness__3__Slow \
	Variane_testharness__4__Slow \
	Variane_testharness__5__Slow \
	Variane_testharness__6__Slow \
	Variane_testharness__7__Slow \
	Variane_testharness__8__Slow \
	Variane_testharness__9__Slow \
	Variane_testharness__10__Slow \
	Variane_testharness__11__Slow \
	Variane_testharness__12__Slow \
	Variane_testharness__13__Slow \
	Variane_testharness__14__Slow \
	Variane_testharness__15__Slow \
	Variane_testharness__16__Slow \
	Variane_testharness__17__Slow \
	Variane_testharness__18__Slow \
	Variane_testharness__19__Slow \
	Variane_testharness__20__Slow \
	Variane_testharness__21__Slow \
	Variane_testharness__22__Slow \
	Variane_testharness___024unit__Slow \
	Variane_testharness_uart_bus__Slow \
	Variane_testharness_AXI_BUS__A40_AB40_AC5_AD1__Slow \
	Variane_testharness_REG_BUS__A20_D20__Slow \
	Variane_testharness_cvxif_instr_pkg__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Variane_testharness__Dpi \
	Variane_testharness__Trace \
	Variane_testharness__Trace__1 \
	Variane_testharness__Trace__2 \
	Variane_testharness__Trace__3 \
	Variane_testharness__Trace__4 \
	Variane_testharness__Trace__5 \
	Variane_testharness__Trace__6 \
	Variane_testharness__Trace__7 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Variane_testharness__Syms \
	Variane_testharness__Trace__Slow \
	Variane_testharness__Trace__1__Slow \
	Variane_testharness__Trace__2__Slow \
	Variane_testharness__Trace__3__Slow \
	Variane_testharness__Trace__4__Slow \
	Variane_testharness__Trace__5__Slow \
	Variane_testharness__Trace__6__Slow \
	Variane_testharness__Trace__7__Slow \
	Variane_testharness__Trace__8__Slow \
	Variane_testharness__Trace__9__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_vpi \
	verilated_vcd_c \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
