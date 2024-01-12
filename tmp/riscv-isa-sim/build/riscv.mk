get_insn_list = $(shell grep ^DECLARE_INSN $(1) | sed 's/DECLARE_INSN(\(.*\),.*,.*)/\1/')
get_opcode = $(shell grep ^DECLARE_INSN.*\\\<$(2)\\\> $(1) | sed 's/DECLARE_INSN(.*,\(.*\),.*)/\1/')

riscv_subproject_deps = \
	fdt \
	softfloat \

riscv_install_prog_srcs = \

riscv_CFLAGS = -fPIC

riscv_hdrs = \
	common.h \
	decode.h \
	devices.h \
	disasm.h \
	dts.h \
	mmu.h \
	processor.h \
	sim.h \
	simif.h \
	trap.h \
	encoding.h \
	cachesim.h \
	memtracer.h \
	mmio_plugin.h \
	tracer.h \
	extension.h \
	rocc.h \
	insn_template.h \
	debug_module.h \
	debug_rom_defines.h \
	remote_bitbang.h \
	jtag_dtm.h \

riscv_install_hdrs = mmio_plugin.h

riscv_precompiled_hdrs = \
	insn_template.h \

riscv_srcs = \
	processor.cc \
	execute.cc \
	dts.cc \
	sim.cc \
	interactive.cc \
	trap.cc \
	cachesim.cc \
	mmu.cc \
	disasm.cc \
	extension.cc \
	extensions.cc \
	rocc.cc \
	devices.cc \
	rom.cc \
	clint.cc \
	debug_module.cc \
	remote_bitbang.cc \
	jtag_dtm.cc \
	$(riscv_gen_srcs) \

riscv_test_srcs =

riscv_gen_hdrs = \
	icache.h \
	insn_list.h \


riscv_insn_ext_i = \
	add \
	addi \
	addiw \
	addw \
	and \
	andi \
	auipc \
	beq \
	bge \
	bgeu \
	blt \
	bltu \
	bne \
	jal \
	jalr \
	lb \
	lbu \
	ld \
	lh \
	lhu \
	lui \
	lw \
	lwu \
	or \
	ori \
	sb \
	sd \
	sh \
	sll \
	slli \
	slliw \
	sllw \
	slt \
	slti \
	sltiu \
	sltu \
	sra \
	srai \
	sraiw \
	sraw \
	srl \
	srli \
	srliw \
	srlw \
	sub \
	subw \
	sw \
	xor \
	xori \
	fence \
	fence_i \

riscv_insn_ext_a = \
	amoadd_d \
	amoadd_w \
	amoand_d \
	amoand_w \
	amomax_d \
	amomaxu_d \
	amomaxu_w \
	amomax_w \
	amomin_d \
	amominu_d \
	amominu_w \
	amomin_w \
	amoor_d \
	amoor_w \
	amoswap_d \
	amoswap_w \
	amoxor_d \
	amoxor_w \
	lr_d \
	lr_w \
	sc_d \
	sc_w \

riscv_insn_ext_c = \
	c_add \
	c_addi \
	c_addi4spn \
	c_addw \
	c_and \
	c_andi \
	c_beqz \
	c_bnez \
	c_ebreak \
	c_fld \
	c_fldsp \
	c_flw \
	c_flwsp \
	c_fsd \
	c_fsdsp \
	c_fsw \
	c_fswsp \
	c_j \
	c_jal \
	c_jalr \
	c_jr \
	c_li \
	c_lui \
	c_lw \
	c_lwsp \
	c_mv \
	c_or \
	c_slli \
	c_srai \
	c_srli \
	c_sub \
	c_subw \
	c_sw \
	c_swsp \
	c_xor \

riscv_insn_ext_m = \
	div \
	divu \
	divuw \
	divw \
	mul \
	mulh \
	mulhsu \
	mulhu \
	mulw \
	rem \
	remu \
	remuw \
	remw \

riscv_insn_ext_f = \
	fadd_s \
	fclass_s \
	fcvt_l_s \
	fcvt_lu_s \
	fcvt_s_l \
	fcvt_s_lu \
	fcvt_s_w \
	fcvt_s_wu \
	fcvt_w_s \
	fcvt_wu_s \
	fdiv_s \
	feq_s \
	fle_s \
	flt_s \
	flw \
	fmadd_s \
	fmax_s \
	fmin_s \
	fmsub_s \
	fmul_s \
	fmv_w_x \
	fmv_x_w \
	fnmadd_s \
	fnmsub_s \
	fsgnj_s \
	fsgnjn_s \
	fsgnjx_s \
	fsqrt_s \
	fsub_s \
	fsw \

riscv_insn_ext_d = \
	fadd_d \
	fclass_d \
	fcvt_d_l \
	fcvt_d_lu \
	fcvt_d_q \
	fcvt_d_s \
	fcvt_d_w \
	fcvt_d_wu \
	fcvt_l_d \
	fcvt_lu_d \
	fcvt_s_d \
	fcvt_w_d \
	fcvt_wu_d \
	fdiv_d \
	feq_d \
	fld \
	fle_d \
	flt_d \
	fmadd_d \
	fmax_d \
	fmin_d \
	fmsub_d \
	fmul_d \
	fmv_d_x \
	fmv_x_d \
	fnmadd_d \
	fnmsub_d \
	fsd \
	fsgnj_d \
	fsgnjn_d \
	fsgnjx_d \
	fsqrt_d \
	fsub_d \

riscv_insn_ext_zfh = \
	fadd_h \
	fclass_h \
	fcvt_l_h \
	fcvt_lu_h \
	fcvt_d_h \
	fcvt_h_d \
	fcvt_h_l \
	fcvt_h_lu \
	fcvt_h_q \
	fcvt_h_s \
	fcvt_h_w \
	fcvt_h_wu \
	fcvt_q_h \
	fcvt_s_h \
	fcvt_w_h \
	fcvt_wu_h \
	fdiv_h \
	feq_h \
	fle_h \
	flh \
	flt_h \
	fmadd_h \
	fmax_h \
	fmin_h \
	fmsub_h \
	fmul_h \
	fmv_h_x \
	fmv_x_h \
	fnmadd_h \
	fnmsub_h \
	fsgnj_h \
	fsgnjn_h \
	fsgnjx_h \
	fsh \
	fsqrt_h \
	fsub_h \

riscv_insn_ext_q = \
	fadd_q \
	fclass_q \
	fcvt_l_q \
	fcvt_lu_q \
	fcvt_q_d \
	fcvt_q_l \
	fcvt_q_lu \
	fcvt_q_s \
	fcvt_q_w \
	fcvt_q_wu \
	fcvt_s_q \
	fcvt_w_q \
	fcvt_wu_q \
	fdiv_q \
	feq_q \
	fle_q \
	flq \
	flt_q \
	fmadd_q \
	fmax_q \
	fmin_q \
	fmsub_q \
	fmul_q \
	fnmadd_q \
	fnmsub_q \
	fsgnj_q \
	fsgnjn_q \
	fsgnjx_q \
	fsq \
	fsqrt_q \
	fsub_q \

riscv_insn_ext_b = \
	add_uw \
	andn \
	bdecompress \
	bdecompressw \
	bcompress \
	bcompressw \
	bfp \
	bfpw \
	bmatflip \
	bmator \
	bmatxor \
	sh1add \
	sh1add_uw \
	sh2add \
	sh2add_uw \
	sh3add \
	sh3add_uw \
	clmul \
	clmulh \
	clmulr \
	clz \
	clzw \
	cmix \
	cmov \
	crc32_b \
	crc32c_b \
	crc32c_d \
	crc32c_h \
	crc32c_w \
	crc32_d \
	crc32_h \
	crc32_w \
	ctz \
	ctzw \
	fsl \
	fslw \
	fsr \
	fsri \
	fsriw \
	fsrw \
	gorc \
	gorci \
	gorciw \
	gorcw \
	grev \
	grevi \
	greviw \
	grevw \
	max \
	maxu \
	min \
	minu \
	orn \
	pack \
	packh \
	packu \
	packuw \
	packw \
	cpop \
	cpopw \
	rol \
	rolw \
	ror \
	rori \
	roriw \
	rorw \
	bclr \
	bclri \
	bext \
	bexti \
	binv \
	binvi \
	bset \
	bseti \
	sext_b \
	sext_h \
	shfl \
	shfli \
	shflw \
	slli_uw \
	slo \
	sloi \
	sloiw \
	slow \
	sro \
	sroi \
	sroiw \
	srow \
	unshfl \
	unshfli \
	unshflw \
	xnor \

riscv_insn_ext_v_alu_int = \
	vaadd_vv \
	vaaddu_vv \
	vaadd_vx \
	vaaddu_vx \
	vadc_vim \
	vadc_vvm \
	vadc_vxm \
	vadd_vi \
	vadd_vv \
	vadd_vx \
	vand_vi \
	vand_vv \
	vand_vx \
	vasub_vv \
	vasubu_vv \
	vasub_vx \
	vasubu_vx \
	vcompress_vm \
	vdiv_vv \
	vdiv_vx \
	vdivu_vv \
	vdivu_vx \
	vdot_vv \
	vdotu_vv \
	vid_v \
	viota_m \
	vmacc_vv \
	vmacc_vx \
	vmadc_vim \
	vmadc_vvm \
	vmadc_vxm \
	vmadd_vv \
	vmadd_vx \
	vmand_mm \
	vmandnot_mm \
	vmax_vv \
	vmax_vx \
	vmaxu_vv \
	vmaxu_vx \
	vmerge_vim \
	vmerge_vvm \
	vmerge_vxm \
	vfirst_m \
	vmin_vv \
	vmin_vx \
	vminu_vv \
	vminu_vx \
	vmnand_mm \
	vmnor_mm \
	vmor_mm \
	vmornot_mm \
	vpopc_m \
	vmsbc_vvm \
	vmsbc_vxm \
	vmsbf_m \
	vmseq_vi \
	vmseq_vv \
	vmseq_vx \
	vmsgt_vi \
	vmsgt_vx \
	vmsgtu_vi \
	vmsgtu_vx \
	vmsif_m \
	vmsle_vi \
	vmsle_vv \
	vmsle_vx \
	vmsleu_vi \
	vmsleu_vv \
	vmsleu_vx \
	vmslt_vv \
	vmslt_vx \
	vmsltu_vv \
	vmsltu_vx \
	vmsne_vi \
	vmsne_vv \
	vmsne_vx \
	vmsof_m \
	vmul_vv \
	vmul_vx \
	vmulh_vv \
	vmulh_vx \
	vmulhsu_vv \
	vmulhsu_vx \
	vmulhu_vv \
	vmulhu_vx \
	vmv_s_x \
	vmv_v_i \
	vmv_v_v \
	vmv_v_x \
	vmv_x_s \
	vmv1r_v \
	vmv2r_v \
	vmv4r_v \
	vmv8r_v \
	vmxnor_mm \
	vmxor_mm \
	vnclip_wi \
	vnclip_wv \
	vnclip_wx \
	vnclipu_wi \
	vnclipu_wv \
	vnclipu_wx \
	vnmsac_vv \
	vnmsac_vx \
	vnmsub_vv \
	vnmsub_vx \
	vnsra_wi \
	vnsra_wv \
	vnsra_wx \
	vnsrl_wi \
	vnsrl_wv \
	vnsrl_wx \
	vor_vi \
	vor_vv \
	vor_vx \
	vredand_vs \
	vredmax_vs \
	vredmaxu_vs \
	vredmin_vs \
	vredminu_vs \
	vredor_vs \
	vredsum_vs \
	vredxor_vs \
	vrem_vv \
	vrem_vx \
	vremu_vv \
	vremu_vx \
	vrgather_vi \
	vrgather_vv \
	vrgather_vx \
	vrgatherei16_vv \
	vrsub_vi \
	vrsub_vx \
	vsadd_vi \
	vsadd_vv \
	vsadd_vx \
	vsaddu_vi \
	vsaddu_vv \
	vsaddu_vx \
	vsbc_vvm \
	vsbc_vxm \
	vsext_vf2 \
	vsext_vf4 \
	vsext_vf8 \
	vslide1down_vx \
	vslide1up_vx \
	vslidedown_vi \
	vslidedown_vx \
	vslideup_vi \
	vslideup_vx \
	vsll_vi \
	vsll_vv \
	vsll_vx \
	vsmul_vv \
	vsmul_vx \
	vsra_vi \
	vsra_vv \
	vsra_vx \
	vsrl_vi \
	vsrl_vv \
	vsrl_vx \
	vssra_vi \
	vssra_vv \
	vssra_vx \
	vssrl_vi \
	vssrl_vv \
	vssrl_vx \
	vssub_vv \
	vssub_vx \
	vssubu_vv \
	vssubu_vx \
	vsub_vv \
	vsub_vx \
	vwadd_vv \
	vwadd_vx \
	vwadd_wv \
	vwadd_wx \
	vwaddu_vv \
	vwaddu_vx \
	vwaddu_wv \
	vwaddu_wx \
	vwmacc_vv \
	vwmacc_vx \
	vwmaccsu_vv \
	vwmaccsu_vx \
	vwmaccu_vv \
	vwmaccu_vx \
	vwmaccus_vx \
	vwmul_vv \
	vwmul_vx \
	vwmulsu_vv \
	vwmulsu_vx \
	vwmulu_vv \
	vwmulu_vx \
	vwredsum_vs \
	vwredsumu_vs \
	vwsub_vv \
	vwsub_vx \
	vwsub_wv \
	vwsub_wx \
	vwsubu_vv \
	vwsubu_vx \
	vwsubu_wv \
	vwsubu_wx \
	vxor_vi \
	vxor_vv \
	vxor_vx \
	vzext_vf2 \
	vzext_vf4 \
	vzext_vf8 \

riscv_insn_ext_v_alu_fp = \
	vfadd_vf \
	vfadd_vv \
	vfclass_v \
	vfcvt_f_x_v \
	vfcvt_f_xu_v \
	vfcvt_rtz_x_f_v \
	vfcvt_rtz_xu_f_v \
	vfcvt_x_f_v \
	vfcvt_xu_f_v \
	vfdiv_vf \
	vfdiv_vv \
	vfdot_vv \
	vfmacc_vf \
	vfmacc_vv \
	vfmadd_vf \
	vfmadd_vv \
	vfmax_vf \
	vfmax_vv \
	vfmerge_vfm \
	vfmin_vf \
	vfmin_vv \
	vfmsac_vf \
	vfmsac_vv \
	vfmsub_vf \
	vfmsub_vv \
	vfmul_vf \
	vfmul_vv \
	vfmv_f_s \
	vfmv_s_f \
	vfmv_v_f \
	vfncvt_f_f_w \
	vfncvt_f_x_w \
	vfncvt_f_xu_w \
	vfncvt_rod_f_f_w \
	vfncvt_rtz_x_f_w \
	vfncvt_rtz_xu_f_w \
	vfncvt_x_f_w \
	vfncvt_xu_f_w \
	vfnmacc_vf \
	vfnmacc_vv \
	vfnmadd_vf \
	vfnmadd_vv \
	vfnmsac_vf \
	vfnmsac_vv \
	vfnmsub_vf \
	vfnmsub_vv \
	vfrdiv_vf \
	vfredmax_vs \
	vfredmin_vs \
	vfredosum_vs \
	vfredsum_vs \
	vfrece7_v \
	vfrsub_vf \
	vfrsqrte7_v \
	vfsgnj_vf \
	vfsgnj_vv \
	vfsgnjn_vf \
	vfsgnjn_vv \
	vfsgnjx_vf \
	vfsgnjx_vv \
	vfsqrt_v \
	vfslide1down_vf \
	vfslide1up_vf \
	vfsub_vf \
	vfsub_vv \
	vfwadd_vf \
	vfwadd_vv \
	vfwadd_wf \
	vfwadd_wv \
	vfwcvt_f_f_v \
	vfwcvt_f_x_v \
	vfwcvt_f_xu_v \
	vfwcvt_rtz_x_f_v \
	vfwcvt_rtz_xu_f_v \
	vfwcvt_x_f_v \
	vfwcvt_xu_f_v \
	vfwmacc_vf \
	vfwmacc_vv \
	vfwmsac_vf \
	vfwmsac_vv \
	vfwmul_vf \
	vfwmul_vv \
	vfwnmacc_vf \
	vfwnmacc_vv \
	vfwnmsac_vf \
	vfwnmsac_vv \
	vfwredosum_vs \
	vfwredsum_vs \
	vfwsub_vf \
	vfwsub_vv \
	vfwsub_wf \
	vfwsub_wv \
	vmfeq_vf \
	vmfeq_vv \
	vmfge_vf \
	vmfgt_vf \
	vmfle_vf \
	vmfle_vv \
	vmflt_vf \
	vmflt_vv \
	vmfne_vf \
	vmfne_vv \

riscv_insn_ext_v_amo = \
	vamoswapei8_v \
	vamoaddei8_v \
	vamoandei8_v \
	vamomaxei8_v \
	vamomaxuei8_v \
	vamominei8_v \
	vamominuei8_v \
	vamoorei8_v \
	vamoxorei8_v \
	vamoswapei16_v \
	vamoaddei16_v \
	vamoandei16_v \
	vamomaxei16_v \
	vamomaxuei16_v \
	vamominei16_v \
	vamominuei16_v \
	vamoorei16_v \
	vamoxorei16_v \
	vamoswapei32_v \
	vamoaddei32_v \
	vamoandei32_v \
	vamomaxei32_v \
	vamomaxuei32_v \
	vamominei32_v \
	vamominuei32_v \
	vamoorei32_v \
	vamoxorei32_v \
	vamoswapei64_v \
	vamoaddei64_v \
	vamoandei64_v \
	vamomaxei64_v \
	vamomaxuei64_v \
	vamominei64_v \
	vamominuei64_v \
	vamoorei64_v \
	vamoxorei64_v \

riscv_insn_ext_v_ldst = \
	vle8_v \
	vle16_v \
	vle32_v \
	vle64_v \
	vloxei8_v \
	vloxei16_v \
	vloxei32_v \
	vloxei64_v \
	vlse8_v \
	vlse16_v \
	vlse32_v \
	vlse64_v \
	vluxei8_v \
	vluxei16_v \
	vluxei32_v \
	vluxei64_v \
	vle8ff_v \
	vle16ff_v \
	vle32ff_v \
	vle64ff_v \
	vl1re8_v \
	vl2re8_v \
	vl4re8_v \
	vl8re8_v \
	vl1re16_v \
	vl2re16_v \
	vl4re16_v \
	vl8re16_v \
	vl1re32_v \
	vl2re32_v \
	vl4re32_v \
	vl8re32_v \
	vl1re64_v \
	vl2re64_v \
	vl4re64_v \
	vl8re64_v \
	vse8_v \
	vse16_v \
	vse32_v \
	vse64_v \
	vsse8_v \
	vsoxei8_v \
	vsoxei16_v \
	vsoxei32_v \
	vsoxei64_v \
	vsse16_v \
	vsse32_v \
	vsse64_v \
	vsuxei8_v \
	vsuxei16_v \
	vsuxei32_v \
	vsuxei64_v \
	vs1r_v \
	vs2r_v \
	vs4r_v \
	vs8r_v \

riscv_insn_ext_v_ctrl = \
	vsetvli \
	vsetvl \

riscv_insn_ext_v = \
	$(riscv_insn_ext_v_alu_fp) \
	$(riscv_insn_ext_v_alu_int) \
	$(riscv_insn_ext_v_amo) \
	$(riscv_insn_ext_v_ctrl) \
	$(riscv_insn_ext_v_ldst) \

riscv_insn_ext_h = \
	hfence_gvma \
	hfence_vvma \
	hlv_b \
	hlv_bu \
	hlv_h \
	hlv_hu \
	hlvx_hu \
	hlv_w \
	hlv_wu \
	hlvx_wu \
	hlv_d \
	hsv_b \
	hsv_h \
	hsv_w \
	hsv_d \

riscv_insn_priv = \
	csrrc \
	csrrci \
	csrrs \
	csrrsi \
	csrrw \
	csrrwi \
	dret \
	ebreak \
	ecall \
	mret \
	sfence_vma \
	sret \
	wfi \


riscv_insn_list = \
	$(riscv_insn_ext_a) \
	$(riscv_insn_ext_c) \
	$(riscv_insn_ext_i) \
	$(riscv_insn_ext_m) \
	$(riscv_insn_ext_f) \
	$(riscv_insn_ext_d) \
	$(riscv_insn_ext_zfh) \
	$(riscv_insn_ext_q) \
	$(riscv_insn_ext_b) \
	$(if $(HAVE_INT128),$(riscv_insn_ext_v),) \
	$(riscv_insn_ext_h) \
	$(riscv_insn_priv) \

riscv_gen_srcs = \
	$(addsuffix .cc,$(riscv_insn_list))

icache_entries := `grep "ICACHE_ENTRIES =" $(src_dir)/riscv/mmu.h | sed 's/.* = \(.*\);/\1/'`

icache.h: mmu.h
	$(src_dir)/riscv/gen_icache $(icache_entries) > $@.tmp
	mv $@.tmp $@

insn_list.h: $(src_dir)/riscv/riscv.mk.in
	for insn in $(foreach insn,$(riscv_insn_list),$(subst .,_,$(insn))) ; do \
		printf 'DEFINE_INSN(%s)\n' "$${insn}" ; \
	done > $@.tmp
	mv $@.tmp $@

$(riscv_gen_srcs): %.cc: insns/%.h insn_template.cc
	sed 's/NAME/$(subst .cc,,$@)/' $(src_dir)/riscv/insn_template.cc | sed 's/OPCODE/$(call get_opcode,$(src_dir)/riscv/encoding.h,$(subst .cc,,$@))/' > $@

riscv_junk = \
	$(riscv_gen_srcs) \
