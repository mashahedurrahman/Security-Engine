
# questa library
library        ?= work
# vcs lib
vcs-library    ?= work-vcs
# library for DPI
dpi-library    ?= work-dpi
# Top level module to compile
top_level      ?= ariane_tb
# Maximum amount of cycles for a successful simulation run
max_cycles     ?= 10000000
# Test case to run
test_case      ?= core_test
# traget option
target-options ?=
# additional definess
defines        ?= WT_DCACHE+RVFI_TRACE
# test name for torture runs (binary name)
test-location  ?= output/test
# custom elf bin to run with sim or sim-verilator
elf-bin        ?= $(TOP)/hello_uart.elf
# board name for bitstream generation. Currently supported: kc705, genesys2
BOARD          ?= genesys2
# root path
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
root-dir := $(dir $(mkfile_path))

ifndef RISCV
$(error RISCV not set - please point your RISCV variable to your RISCV installation)
endif

# By default assume spike resides at the RISCV prefix.
SPIKE_ROOT     ?= $(RISCV)

# target takes one of the following cva6 hardware configuration:
# cv64a6_imafdc_sv39, cv32a6_imac_sv0, cv32a6_imac_sv32, cv32a6_imafc_sv32
target     ?= cv64a6_imafdc_sv39

# Sources
# Package files -> compile first
ariane_pkg := core/include/$(target)_config_pkg.sv
ariane_pkg += core/include/riscv_pkg.sv                              \
              corev_apu/riscv-dbg/src/dm_pkg.sv                      \
              core/include/ariane_pkg.sv                             \
              core/include/ariane_rvfi_pkg.sv                        \
              core/include/std_cache_pkg.sv                          \
              core/include/wt_cache_pkg.sv                           \
              core/include/cvxif_pkg.sv                              \
              corev_apu/axi/src/axi_pkg.sv                           \
              corev_apu/register_interface/src/reg_intf.sv           \
              core/include/axi_intf.sv                               \
              corev_apu/tb/rvfi_pkg.sv                               \
              corev_apu/tb/ariane_soc_pkg.sv                         \
              corev_apu/tb/ariane_axi_soc_pkg.sv                     \
              core/include/ariane_axi_pkg.sv                         \
              core/fpu/src/fpnew_pkg.sv                              \
              common/submodules/common_cells/src/cf_math_pkg.sv      \
              core/cvxif_example/include/cvxif_instr_pkg.sv          \
              core/fpu/src/fpu_div_sqrt_mvp/hdl/defs_div_sqrt_mvp.sv
ariane_pkg := $(addprefix $(root-dir), $(ariane_pkg))

# utility modules
util := core/include/instr_tracer_pkg.sv                              \
        common/local/util/instr_tracer_if.sv                          \
        common/local/util/instr_tracer.sv                             \
        corev_apu/src/tech_cells_generic/src/cluster_clock_gating.sv  \
        corev_apu/tb/common/mock_uart.sv                              \
        common/local/util/sram.sv

ifdef spike-tandem
    util += tb/common/spike.sv
endif

util := $(addprefix $(root-dir), $(util))
# Test packages
test_pkg := $(wildcard tb/test/*/*sequence_pkg.sv*) \
			$(wildcard tb/test/*/*_pkg.sv*)

# DPI
dpi := $(patsubst corev_apu/tb/dpi/%.cc, ${dpi-library}/%.o, $(wildcard corev_apu/tb/dpi/*.cc))

# filter spike stuff if tandem is not activated
ifndef spike-tandem
    dpi := $(filter-out ${dpi-library}/spike.o ${dpi-library}/sim_spike.o, $(dpi))
endif

# filter dromajo stuff if dromajo is not activated
ifndef DROMAJO
    dpi := $(filter-out ${dpi-library}/dromajo_cosim_dpi.o, $(dpi))
endif

dpi_hdr := $(wildcard corev_apu/tb/dpi/*.h)
dpi_hdr := $(addprefix $(root-dir), $(dpi_hdr))
CFLAGS := -I$(QUESTASIM_HOME)/include         \
          -I$(VCS_HOME)/include \
          -I$(RISCV)/include                  \
          -I$(SPIKE_ROOT)/include             \
          -I$(TOP)             \
          $(if $(DROMAJO), -I../corev_apu/tb/dromajo/src,) \
          -std=c++11 -I../corev_apu/tb/dpi -O3

ifdef XCELIUM_HOME
CFLAGS += -I$(XCELIUM_HOME)/tools/include
else
$(warning XCELIUM_HOME not set which is necessary for compiling DPIs when using XCELIUM)
endif

ifdef spike-tandem
    CFLAGS += -Itb/riscv-isa-sim/install/include/spike
endif


# this list contains the standalone components
src :=  $(filter-out core/ariane_regfile.sv, $(wildcard core/*.sv))                  \
        $(filter-out core/fpu/src/fpnew_pkg.sv, $(wildcard core/fpu/src/*.sv))       \
        $(filter-out core/fpu/src/fpu_div_sqrt_mvp/hdl/defs_div_sqrt_mvp.sv,         \
        $(wildcard core/fpu/src/fpu_div_sqrt_mvp/hdl/*.sv))                          \
        $(wildcard core/frontend/*.sv)                                               \
        $(filter-out core/cache_subsystem/std_no_dcache.sv,                          \
        $(wildcard core/cache_subsystem/*.sv))                                       \
        $(wildcard corev_apu/bootrom/*.sv)                                           \
        $(wildcard corev_apu/clint/*.sv)                                             \
        $(wildcard corev_apu/fpga/src/axi2apb/src/*.sv)                              \
        $(wildcard corev_apu/fpga/src/apb_timer/*.sv)                                \
        $(wildcard corev_apu/fpga/src/axi_slice/src/*.sv)                            \
        $(wildcard corev_apu/src/axi_riscv_atomics/src/*.sv)                         \
        $(wildcard corev_apu/axi_mem_if/src/*.sv)                                    \
        $(wildcard core/pmp/src/*.sv)                                                \
        $(wildcard core/cvxif_example/*.sv)                                          \
        corev_apu/rv_plic/rtl/rv_plic_target.sv                                      \
        corev_apu/rv_plic/rtl/rv_plic_gateway.sv                                     \
        corev_apu/rv_plic/rtl/plic_regmap.sv                                         \
        corev_apu/rv_plic/rtl/plic_top.sv                                            \
        corev_apu/riscv-dbg/src/dmi_cdc.sv                                           \
        corev_apu/riscv-dbg/src/dmi_jtag.sv                                          \
        corev_apu/riscv-dbg/src/dmi_jtag_tap.sv                                      \
        corev_apu/riscv-dbg/src/dm_csrs.sv                                           \
        corev_apu/riscv-dbg/src/dm_mem.sv                                            \
        corev_apu/riscv-dbg/src/dm_sba.sv                                            \
        corev_apu/riscv-dbg/src/dm_top.sv                                            \
        corev_apu/riscv-dbg/debug_rom/debug_rom.sv                                   \
        corev_apu/register_interface/src/apb_to_reg.sv                               \
        corev_apu/axi/src/axi_multicut.sv                                            \
        common/submodules/common_cells/src/deprecated/generic_fifo.sv                \
        common/submodules/common_cells/src/deprecated/pulp_sync.sv                   \
        common/submodules/common_cells/src/deprecated/find_first_one.sv              \
        common/submodules/common_cells/src/rstgen_bypass.sv                          \
        common/submodules/common_cells/src/rstgen.sv                                 \
        common/submodules/common_cells/src/stream_mux.sv                             \
        common/submodules/common_cells/src/stream_demux.sv                           \
        common/submodules/common_cells/src/exp_backoff.sv                            \
        common/submodules/common_cells/src/addr_decode.sv                            \
        common/submodules/common_cells/src/stream_register.sv                        \
        corev_apu/axi/src/axi_cut.sv                                                 \
        corev_apu/axi/src/axi_join.sv                                                \
        corev_apu/axi/src/axi_delayer.sv                                             \
        corev_apu/axi/src/axi_to_axi_lite.sv                                         \
        corev_apu/axi/src/axi_id_prepend.sv                                          \
        corev_apu/axi/src/axi_atop_filter.sv                                         \
        corev_apu/axi/src/axi_err_slv.sv                                             \
        corev_apu/axi/src/axi_mux.sv                                                 \
        corev_apu/axi/src/axi_demux.sv                                               \
        corev_apu/axi/src/axi_xbar.sv                                                \
        corev_apu/fpga-support/rtl/SyncSpRamBeNx64.sv                                \
        common/submodules/common_cells/src/unread.sv                                 \
        common/submodules/common_cells/src/sync.sv                                   \
        common/submodules/common_cells/src/cdc_2phase.sv                             \
        common/submodules/common_cells/src/spill_register_flushable.sv               \
        common/submodules/common_cells/src/spill_register.sv                         \
        common/submodules/common_cells/src/sync_wedge.sv                             \
        common/submodules/common_cells/src/edge_detect.sv                            \
        common/submodules/common_cells/src/stream_arbiter.sv                         \
        common/submodules/common_cells/src/stream_arbiter_flushable.sv               \
        common/submodules/common_cells/src/deprecated/fifo_v1.sv                     \
        common/submodules/common_cells/src/deprecated/fifo_v2.sv                     \
        common/submodules/common_cells/src/fifo_v3.sv                                \
        common/submodules/common_cells/src/lzc.sv                                    \
        common/submodules/common_cells/src/popcount.sv                               \
        common/submodules/common_cells/src/rr_arb_tree.sv                            \
        common/submodules/common_cells/src/deprecated/rrarbiter.sv                   \
        common/submodules/common_cells/src/stream_delay.sv                           \
        common/submodules/common_cells/src/lfsr.sv                                   \
        common/submodules/common_cells/src/lfsr_8bit.sv                              \
        common/submodules/common_cells/src/lfsr_16bit.sv                             \
        common/submodules/common_cells/src/delta_counter.sv                          \
        common/submodules/common_cells/src/counter.sv                                \
        common/submodules/common_cells/src/shift_reg.sv                              \
        corev_apu/src/tech_cells_generic/src/pulp_clock_gating.sv                    \
        corev_apu/src/tech_cells_generic/src/cluster_clock_inverter.sv               \
        corev_apu/src/tech_cells_generic/src/pulp_clock_mux2.sv                      \
        corev_apu/tb/ariane_testharness.sv                                           \
        corev_apu/tb/ariane_peripherals.sv                                           \
        corev_apu/tb/rvfi_tracer.sv                                                  \
        corev_apu/tb/common/uart.sv                                                  \
        #corev_apu/tb/common/SimDTM.sv                                                \
        #corev_apu/tb/common/SimJTAG.sv

# SV32 MMU for CV32, SV39 MMU for CV64
ifeq ($(findstring 32, $(target)),32)
    src += $(wildcard core/mmu_sv32/*.sv)
else
    src += $(wildcard core/mmu_sv39/*.sv)
endif


#mash: add modified axi_lite file
src += corev_apu/axi/src/axi_to_axi_lite_mod.sv


#mash: add SHA IP files
sha_src := SHA/rtl/sha_wrapper.v
sha_src += SHA/rtl/controller.vhd 
sha_src += SHA/rtl/controller384.vhd 
sha_src += SHA/rtl/controller512.vhd 
sha_src += SHA/rtl/decoder.vhd 
sha_src += SHA/rtl/mux4x1.vhd 
sha_src += SHA/rtl/mux512.vhd 
sha_src += SHA/rtl/reg.vhd 
sha_src += SHA/rtl/sha256.v 
sha_src += SHA/rtl/sha384.v 
sha_src += SHA/rtl/sha512.v 
sha_src += SHA/rtl/SHA384_IP.vhd 
sha_src += SHA/rtl/SHA512_IP.vhd 
sha_src += SHA/rtl/sha_controller.vhd 
sha_src += SHA/rtl/SHA_IP.vhd 
sha_src += SHA/rtl/sha_functions.vhd 
sha_src += SHA/rtl/toplevel.vhd
sha_src := $(addprefix $(root-dir), $(sha_src))

#mash: add DH IP files
dh_src := DH/rtl/dh_wrapper.v
dh_src += DH/rtl/serial_multiplier_283.vhd
dh_src := $(addprefix $(root-dir), $(dh_src))

#mash: add ECDSA IP files
ecdsa_src := ECDSA/rtl/ecdsa_wrapper.v
ecdsa_src += ECDSA/rtl/ecdsa_combined.sv
ecdsa_src += ECDSA/rtl/ECDSA_sign.v
ecdsa_src += ECDSA/rtl/ECDSA_verify.v
ecdsa_src += ECDSA/rtl/eeageneric.v
ecdsa_src += ECDSA/rtl/get_2P.v
ecdsa_src += ECDSA/rtl/get_PQ.v
ecdsa_src += ECDSA/rtl/montgomeryLadder.v
ecdsa_src := $(addprefix $(root-dir), $(ecdsa_src))

src := $(addprefix $(root-dir), $(src))

copro_src := core/cvxif_example/include/cvxif_instr_pkg.sv \
             $(wildcard core/cvxif_example/*.sv)
copro_src := $(addprefix $(root-dir), $(copro_src))

uart_src := $(wildcard corev_apu/fpga/src/apb_uart/src/*.vhd)
uart_src := $(addprefix $(root-dir), $(uart_src))

fpga_src :=  $(wildcard corev_apu/fpga/src/*.sv) $(wildcard corev_apu/fpga/src/bootrom/*.sv) $(wildcard corev_apu/fpga/src/ariane-ethernet/*.sv)
fpga_src := $(addprefix $(root-dir), $(fpga_src))

# look for testbenches
tbs := corev_apu/tb/ariane_tb.sv corev_apu/tb/ariane_testharness.sv
tbs := $(addprefix $(root-dir), $(tbs))


# Search here for include files (e.g.: non-standalone components)
incdir := common/submodules/common_cells/include/ corev_apu/axi/include/ corev_apu/register_interface/include/

# Compile and sim flags
compile_flag     += +cover=bcfst+/dut -incr -64 -nologo -quiet -suppress 13262 -permissive +define+$(defines)
questa-flags     += -t 1ns -64 -coverage -classdebug $(gui-sim) $(QUESTASIM_FLAGS)
compile_flag_vhd += -64 -nologo -quiet -2008

# Iterate over all include directories and write them with +incdir+ prefixed
# +incdir+ works for Verilator and QuestaSim
list_incdir := $(foreach dir, ${incdir}, +incdir+$(dir))


# compile DPIs
$(dpi-library)/%.o: corev_apu/tb/dpi/%.cc $(dpi_hdr)
	mkdir -p $(dpi-library)
	$(CXX) -shared -fPIC -std=c++0x -Bsymbolic $(CFLAGS) -c $< -o $@

$(dpi-library)/ariane_dpi.so: $(dpi)
	mkdir -p $(dpi-library)
	# Compile C-code and generate .so file
	$(CXX) -shared -m64 -o $(dpi-library)/ariane_dpi.so $? -L$(RISCV)/lib -L$(SPIKE_ROOT)/lib -Wl,-rpath,$(RISCV)/lib -Wl,-rpath,$(SPIKE_ROOT)/lib -lfesvr
	#$(CXX) -shared -m64 -o $(dpi-library)/ariane_dpi.so $? -L$(RISCV)/lib -L$(SPIKE_ROOT)/lib -Wl,-rpath,$(RISCV)/lib -Wl,-rpath,$(SPIKE_ROOT)/lib
	#$(CXX) -shared -m64 -o $(dpi-library)/ariane_dpi.so $? -L$(RISCV)/lib -L$(SPIKE_ROOT)/lib -Wl,-rpath,$(RISCV)/lib -Wl,-rpath,$(SPIKE_ROOT)/lib -L$(TOP) -lfesvr



#####################################
# xrun-specific commands, variables
#####################################
XRUN               ?= xrun
XRUN_WORK_DIR      ?= xrun_work
XRUN_RESULTS_DIR   ?= xrun_results
XRUN_COMPL_LOG     ?= xrun_compl.log
XRUN_RUN_LOG       ?= xrun_run.log
CVA6_HOME	   ?= $(realpath -s $(root-dir))

XRUN_INCDIR :=+incdir+$(CVA6_HOME)/src/axi_node 	\
	+incdir+$(CVA6_HOME)/src/common_cells/include 	\
	+incdir+$(CVA6_HOME)/core/fpu/src/common_cells/include 	\
	+incdir+$(CVA6_HOME)/corev_apu/axi/include 	\
	+incdir+$(CVA6_HOME)/corev_apu/register_interface/include 	\
	+incdir+$(CVA6_HOME)/common/local/util 	\
	+incdir+$(CVA6_HOME)/src/util
XRUN_TB := $(addprefix $(CVA6_HOME)/, corev_apu/tb/ariane_tb.sv)

XRUN_COMP_FLAGS  ?= -64bit -disable_sem2009 -access +rwc 			\
		    -sv -v200x 			\
		    -sv_lib $(CVA6_HOME)/$(dpi-library)/ariane_dpi.so		\
		    -smartorder -sv -top worklib.$(top_level)			\
		    -xceligen on=1903 +define+$(defines) -timescale 1ns/1ps	\

XRUN_RUN_FLAGS := -R -64bit -disable_sem2009 -access +rwc -timescale 1ns/1ps		\
		-sv_lib	$(CVA6_HOME)/$(dpi-library)/ariane_dpi.so -xceligen on=1903	\

XRUN_DISABLED_WARNINGS := BIGWIX 	\
			ZROMCW 		\
			STRINT 		\
			ENUMERR 	\
			SPDUSD		\
			RNDXCELON

XRUN_DISABLED_WARNINGS 	:= $(patsubst %, -nowarn %, $(XRUN_DISABLED_WARNINGS))

XRUN_COMP = $(XRUN_COMP_FLAGS)		\
	$(XRUN_DISABLED_WARNINGS) 	\
	$(XRUN_INCDIR)		      	\
	$(filter %.sv, $(ariane_pkg)) 	\
	$(filter %.sv, $(util))		\
	$(filter %.vhd, $(uart_src))  	\
	$(filter %.sv, $(src))	      	\
	$(sha_src)              	\
	$(dh_src)              	\
	$(ecdsa_src)              	\
	$(filter %.sv, $(XRUN_TB))	\

XRUN_RUN = $(XRUN_RUN_FLAGS) 		\
	$(XRUN_DISABLED_WARNINGS)	\

xrun_clean:
	@echo "[XRUN] clean up"
	rm -rf $(XRUN_RESULTS_DIR)
	rm -rf $(dpi-library)

xrun_comp: $(dpi-library)/ariane_dpi.so
	@echo "[XRUN] Building Model"
	mkdir -p $(XRUN_RESULTS_DIR)
	cd $(XRUN_RESULTS_DIR) && $(XRUN)   \
		+permissive		    \
		$(XRUN_COMP)                \
		-l $(XRUN_COMPL_LOG)        \
		+permissive-off		    \
		-elaborate

xrun_sim: xrun_comp
	@echo "[XRUN] Simulating selected binary"
	cd $(XRUN_RESULTS_DIR) && $(XRUN)	\
		+permissive			\
		$(XRUN_RUN)			\
		+MAX_CYCLES=$(max_cycles)	\
		-l $(XRUN_RUN_LOG)		\
		+permissive-off			\
		+PRELOAD=$(elf-bin)

#-e "set_severity_pack_assert_off {warning}; set_pack_assert_off {numeric_std}" TODO: This will remove assertion warning at the beginning of the simulation.

xrun_all: xrun_clean xrun_comp xrun_sim


