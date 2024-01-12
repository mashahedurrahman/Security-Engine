	.file	"hello_rsa.c"
	.option nopic
# GNU C99 (GCC) version 7.2.0 (riscv64-unknown-elf)
#	compiled by GNU C version 7.5.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version none
# warning: GMP header version 6.2.0 differs from library version 6.3.0.
# warning: MPFR header version 4.0.2 differs from library version 4.2.1.
# warning: MPC header version 1.1.0 differs from library version 1.0.1.
# GGC heuristics: --param ggc-min-expand=30 --param ggc-min-heapsize=4096
# options passed: 
# -iprefix /ecel/UFAD/mrahman1/cva6_for_se/cva6_09222023/riscv_install/bin/../lib/gcc/riscv64-unknown-elf/7.2.0/
# -isysroot /ecel/UFAD/mrahman1/cva6_for_se/cva6_09222023/riscv_install/bin/../riscv64-unknown-elf
# -D PREALLOCATE=1 hello_rsa.c -mcmodel=medany -march=rv64imafdc
# -mabi=lp64d -auxbase-strip hello_rsa.s -g -O2 -std=gnu99 -fverbose-asm
# -ffast-math -fno-common -fno-builtin-printf
# -fno-tree-loop-distribute-patterns
# options enabled:  -faggressive-loop-optimizations -falign-functions
# -falign-jumps -falign-labels -falign-loops -fassociative-math
# -fauto-inc-dec -fbranch-count-reg -fcaller-saves
# -fchkp-check-incomplete-type -fchkp-check-read -fchkp-check-write
# -fchkp-instrument-calls -fchkp-narrow-bounds -fchkp-optimize
# -fchkp-store-bounds -fchkp-use-static-bounds
# -fchkp-use-static-const-bounds -fchkp-use-wrappers -fcode-hoisting
# -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fcx-limited-range -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexpensive-optimizations -ffinite-math-only -fforward-propagate
# -ffp-int-builtin-inexact -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
# -fif-conversion -fif-conversion2 -findirect-inlining -finline
# -finline-atomics -finline-functions-called-once -finline-small-functions
# -fipa-bit-cp -fipa-cp -fipa-icf -fipa-icf-functions -fipa-icf-variables
# -fipa-profile -fipa-pure-const -fipa-ra -fipa-reference -fipa-sra
# -fipa-vrp -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fisolate-erroneous-paths-dereference -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse -flra-remat
# -flto-odr-type-merging -fmerge-constants -fmerge-debug-strings
# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeephole -fpeephole2 -fplt
# -fprefetch-loop-arrays -freciprocal-math -free -freg-struct-return
# -freorder-blocks -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns
# -fschedule-insns2 -fsection-anchors -fsemantic-interposition
# -fshow-column -fshrink-wrap -fshrink-wrap-separate
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop -fssa-phiopt
# -fstdarg-opt -fstore-merging -fstrict-aliasing -fstrict-overflow
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp
# -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-dce
# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
# -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
# -ftree-vrp -funit-at-a-time -funsafe-math-optimizations -fvar-tracking
# -fvar-tracking-assignments -fverbose-asm -fzero-initialized-in-bss -mdiv
# -mfdiv -mplt -mstrict-align

	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	1
	.globl	custom_memcpy
	.type	custom_memcpy, @function
custom_memcpy:
.LFB0:
	.file 1 "hello_rsa.c"
	.loc 1 2 0
	.cfi_startproc
.LVL0:
# hello_rsa.c:7:    for (i=0; i<n; i++)
	.loc 1 7 0
	blez	a2,.L1	#, n,
	addiw	a5,a2,-1	#, tmp114, n
	slli	a5,a5,32	#, tmp115, tmp114
	srli	a5,a5,32	#, tmp115, tmp115
	addi	a5,a5,1	#, tmp116, tmp115
	add	a5,a1,a5	# tmp116, _27, ivtmp.8
.LVL1:
.L3:
# hello_rsa.c:8:       dest_char[i] = src_char[i]; //copy contents byte by byte
	.loc 1 8 0 discriminator 3
	lbu	a4,0(a1)	# _4, MEM[base: _13, offset: 0B]
	addi	a0,a0,1	#, ivtmp.9, ivtmp.9
	addi	a1,a1,1	#, ivtmp.8, ivtmp.8
.LVL2:
	sb	a4,-1(a0)	# _4, MEM[base: _21, offset: 0B]
# hello_rsa.c:7:    for (i=0; i<n; i++)
	.loc 1 7 0 discriminator 3
	bne	a1,a5,.L3	#, ivtmp.8, _27,
.L1:
# hello_rsa.c:9: }
	.loc 1 9 0
	ret
	.cfi_endproc
.LFE0:
	.size	custom_memcpy, .-custom_memcpy
	.align	1
	.globl	custom_memcpy_2
	.type	custom_memcpy_2, @function
custom_memcpy_2:
.LFB4:
	.cfi_startproc
	tail	custom_memcpy	#
	.cfi_endproc
.LFE4:
	.size	custom_memcpy_2, .-custom_memcpy_2
	.section	.text.startup,"ax",@progbits
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB2:
	.loc 1 21 0
	.cfi_startproc
.LVL3:
# hello_rsa.c:30:     *(addr_rsa+96) = 0;
	.loc 1 30 0
	li	a5,1342177280	# tmp141,
	sd	zero,768(a5)	#, MEM[(volatile long long unsigned int *)1342178048B]
.LVL4:
.LBB12:
# hello_rsa.c:33:     for (int i = 31; i >= 1; i--) {
	.loc 1 33 0
	li	a4,1342177280	# tmp142,
.LBE12:
# hello_rsa.c:30:     *(addr_rsa+96) = 0;
	.loc 1 30 0
	addi	a5,a5,248	#, ivtmp.82, tmp141
.LVL5:
.L8:
.LBB13:
# hello_rsa.c:34:         *(addr_rsa+i) = 0;
	.loc 1 34 0 discriminator 3
	sd	zero,0(a5)	#, *_3
	addi	a5,a5,-8	#, ivtmp.82, ivtmp.82
# hello_rsa.c:33:     for (int i = 31; i >= 1; i--) {
	.loc 1 33 0 discriminator 3
	bne	a5,a4,.L8	#, ivtmp.82, tmp142,
.LBE13:
# hello_rsa.c:36:     *(addr_rsa+0) = 8;
	.loc 1 36 0
	li	a3,8	# tmp144,
.LBB14:
# hello_rsa.c:39:     for (int i = 63; i >= 33; i--) {
	.loc 1 39 0
	li	a4,1342177280	# tmp146,
.LBE14:
# hello_rsa.c:36:     *(addr_rsa+0) = 8;
	.loc 1 36 0
	sd	a3,0(a5)	# tmp144, MEM[(volatile long long unsigned int *)1342177280B]
.LVL6:
	addi	a5,a5,504	#, ivtmp.75, ivtmp.82
.LBB15:
# hello_rsa.c:39:     for (int i = 63; i >= 33; i--) {
	.loc 1 39 0
	addi	a3,a4,256	#, tmp145, tmp146
.LVL7:
.L9:
# hello_rsa.c:40:         *(addr_rsa+i) = 0;
	.loc 1 40 0 discriminator 3
	sd	zero,0(a5)	#, *_6
	addi	a5,a5,-8	#, ivtmp.75, ivtmp.75
# hello_rsa.c:39:     for (int i = 63; i >= 33; i--) {
	.loc 1 39 0 discriminator 3
	bne	a5,a3,.L9	#, ivtmp.75, tmp145,
.LBE15:
.LBB16:
# hello_rsa.c:45:     for (int i = 95; i >= 65; i--) {
	.loc 1 45 0
	li	a3,1342177280	# tmp151,
.LBE16:
# hello_rsa.c:42:     *(addr_rsa+32) = 13;
	.loc 1 42 0
	li	a2,13	# tmp149,
	sd	a2,0(a5)	# tmp149, MEM[(volatile long long unsigned int *)1342177536B]
.LVL8:
	addi	a5,a4,760	#, ivtmp.66, tmp146
.LBB17:
# hello_rsa.c:45:     for (int i = 95; i >= 65; i--) {
	.loc 1 45 0
	addi	a4,a3,512	#, tmp150, tmp151
.LVL9:
.L10:
# hello_rsa.c:46:         *(addr_rsa+i) = 0;
	.loc 1 46 0 discriminator 3
	sd	zero,0(a5)	#, *_9
	addi	a5,a5,-8	#, ivtmp.66, ivtmp.66
# hello_rsa.c:45:     for (int i = 95; i >= 65; i--) {
	.loc 1 45 0 discriminator 3
	bne	a5,a4,.L10	#, ivtmp.66, tmp150,
.LBE17:
# hello_rsa.c:48:     *(addr_rsa+64) = 77;
	.loc 1 48 0
	li	a4,77	# tmp154,
	sd	a4,0(a5)	# tmp154, MEM[(volatile long long unsigned int *)1342177792B]
# hello_rsa.c:51:     *(addr_rsa+96) = 1;
	.loc 1 51 0
	li	a5,1	# tmp157,
	sd	a5,768(a3)	# tmp157, MEM[(volatile long long unsigned int *)1342178048B]
# hello_rsa.c:55:         data = *(addr_rsa+129);
	.loc 1 55 0
	li	a5,1342177280	# tmp158,
# hello_rsa.c:56:     } while (data != 1);
	.loc 1 56 0
	li	a3,1	# tmp159,
.L11:
# hello_rsa.c:55:         data = *(addr_rsa+129);
	.loc 1 55 0 discriminator 1
	ld	a4,1032(a5)	# data, MEM[(volatile long long unsigned int *)1342177280B + 1032B]
.LVL10:
# hello_rsa.c:56:     } while (data != 1);
	.loc 1 56 0 discriminator 1
	bne	a4,a3,.L11	#, data, tmp159,
.LBB18:
.LBB19:
# hello_rsa.c:7:    for (i=0; i<n; i++)
	.loc 1 7 0
	li	a0,1342177280	# tmp163,
.LVL11:
.LBE19:
.LBE18:
	addi	a5,a5,776	#, ivtmp.57, tmp158
.LBB21:
.LBB20:
# hello_rsa.c:8:       dest_char[i] = src_char[i]; //copy contents byte by byte
	.loc 1 8 0
	li	a1,1073741824	# tmp160,
.LVL12:
# hello_rsa.c:7:    for (i=0; i<n; i++)
	.loc 1 7 0
	addi	a2,a0,1032	#, tmp162, tmp163
.LVL13:
.L12:
# hello_rsa.c:8:       dest_char[i] = src_char[i]; //copy contents byte by byte
	.loc 1 8 0
	lbu	a3,0(a5)	# _64, *_62
	add	a4,a1,a5	# ivtmp.57, tmp161, tmp160
	addi	a5,a5,1	#, ivtmp.57, ivtmp.57
.LVL14:
	sb	a3,-776(a4)	# _64, MEM[(char *)_86]
# hello_rsa.c:7:    for (i=0; i<n; i++)
	.loc 1 7 0
	bne	a5,a2,.L12	#, ivtmp.57, tmp162,
.LBE20:
.LBE21:
# hello_rsa.c:68:     *(addr_rsa+96) = 0;
	.loc 1 68 0
	li	a5,9	# tmp136,
	slli	a5,a5,28	#, ivtmp.49, tmp136
	sd	zero,768(a0)	#, MEM[(volatile long long unsigned int *)1342178048B]
.LVL15:
.LBB22:
.LBB23:
# hello_rsa.c:17:       dest_char[j] = src_char[j]; //copy contents byte by byte
	.loc 1 17 0
	li	a1,-1073741824	# tmp166,
# hello_rsa.c:16:    for (j=0; j<n; j++)
	.loc 1 16 0
	addi	a2,a5,256	#, tmp168, ivtmp.49
.LVL16:
.L13:
# hello_rsa.c:17:       dest_char[j] = src_char[j]; //copy contents byte by byte
	.loc 1 17 0
	lbu	a3,0(a5)	# _58, *_56
	add	a4,a1,a5	# ivtmp.49, tmp167, tmp166
	addi	a5,a5,1	#, ivtmp.49, ivtmp.49
.LVL17:
	sb	a3,0(a4)	# _58, MEM[(char *)_108]
# hello_rsa.c:16:    for (j=0; j<n; j++)
	.loc 1 16 0
	bne	a5,a2,.L13	#, ivtmp.49, tmp168,
.LBE23:
.LBE22:
.LBB25:
# hello_rsa.c:78:     for (int i = 63; i >= 33; i--) {
	.loc 1 78 0
	li	a5,1342177280	# tmp172,
.LBE25:
.LBB26:
.LBB24:
# hello_rsa.c:16:    for (j=0; j<n; j++)
	.loc 1 16 0
	li	a4,1342177280	# tmp137,
	addi	a4,a4,504	#, ivtmp.41, tmp137
.LBE24:
.LBE26:
.LBB27:
# hello_rsa.c:78:     for (int i = 63; i >= 33; i--) {
	.loc 1 78 0
	addi	a3,a5,256	#, tmp171, tmp172
.L14:
# hello_rsa.c:79:         *(addr_rsa+i) = 0;
	.loc 1 79 0 discriminator 3
	sd	zero,0(a4)	#, *_12
.LVL18:
	addi	a4,a4,-8	#, ivtmp.41, ivtmp.41
# hello_rsa.c:78:     for (int i = 63; i >= 33; i--) {
	.loc 1 78 0 discriminator 3
	bne	a4,a3,.L14	#, ivtmp.41, tmp171,
.LBE27:
.LBB28:
# hello_rsa.c:84:     for (int i = 95; i >= 65; i--) {
	.loc 1 84 0
	li	a3,1342177280	# tmp177,
.LBE28:
# hello_rsa.c:81:     *(addr_rsa+32) = 37;
	.loc 1 81 0
	li	a2,37	# tmp175,
	sd	a2,0(a4)	# tmp175, MEM[(volatile long long unsigned int *)1342177536B]
.LVL19:
	addi	a5,a5,760	#, ivtmp.32, tmp172
.LBB29:
# hello_rsa.c:84:     for (int i = 95; i >= 65; i--) {
	.loc 1 84 0
	addi	a4,a3,512	#, tmp176, tmp177
.LVL20:
.L15:
# hello_rsa.c:85:         *(addr_rsa+i) = 0;
	.loc 1 85 0 discriminator 3
	sd	zero,0(a5)	#, *_15
	addi	a5,a5,-8	#, ivtmp.32, ivtmp.32
# hello_rsa.c:84:     for (int i = 95; i >= 65; i--) {
	.loc 1 84 0 discriminator 3
	bne	a5,a4,.L15	#, ivtmp.32, tmp176,
.LBE29:
# hello_rsa.c:87:     *(addr_rsa+64) = 77;
	.loc 1 87 0
	li	a4,77	# tmp180,
	sd	a4,0(a5)	# tmp180, MEM[(volatile long long unsigned int *)1342177792B]
# hello_rsa.c:90:     *(addr_rsa+96) = 1;
	.loc 1 90 0
	li	a5,1	# tmp183,
	sd	a5,768(a3)	# tmp183, MEM[(volatile long long unsigned int *)1342178048B]
# hello_rsa.c:94:         data = *(addr_rsa+129);
	.loc 1 94 0
	li	a5,1342177280	# tmp184,
# hello_rsa.c:95:     } while (data != 1);
	.loc 1 95 0
	li	a3,1	# tmp185,
.L16:
# hello_rsa.c:94:         data = *(addr_rsa+129);
	.loc 1 94 0 discriminator 1
	ld	a4,1032(a5)	# data, MEM[(volatile long long unsigned int *)1342177280B + 1032B]
.LVL21:
# hello_rsa.c:95:     } while (data != 1);
	.loc 1 95 0 discriminator 1
	bne	a4,a3,.L16	#, data, tmp185,
.LBB30:
# hello_rsa.c:98:     for (int i = 128; i >= 97; i--) {
	.loc 1 98 0
	li	a4,1342177280	# tmp187,
.LVL22:
.LBE30:
	addi	a5,a5,1024	#, ivtmp.23, tmp184
.LBB31:
	addi	a4,a4,768	#, tmp186, tmp187
.L17:
# hello_rsa.c:99:         data = *(addr_rsa+i);
	.loc 1 99 0 discriminator 3
	ld	a3,0(a5)	# data, *_18
.LVL23:
	addi	a5,a5,-8	#, ivtmp.23, ivtmp.23
# hello_rsa.c:98:     for (int i = 128; i >= 97; i--) {
	.loc 1 98 0 discriminator 3
	bne	a5,a4,.L17	#, ivtmp.23, tmp186,
.LBE31:
# hello_rsa.c:197: }
	.loc 1 197 0
	li	a0,0	#,
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.text
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0x2b7
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x8
	.byte	0x1
	.4byte	.LASF12
	.byte	0xc
	.4byte	.LASF13
	.4byte	.LASF14
	.4byte	.Ldebug_ranges0+0x180
	.8byte	0
	.4byte	.Ldebug_line0
	.byte	0x2
	.4byte	.LASF15
	.byte	0x1
	.byte	0x15
	.4byte	0x19a
	.8byte	.LFB2
	.8byte	.LFE2-.LFB2
	.byte	0x1
	.byte	0x9c
	.4byte	0x19a
	.byte	0x3
	.4byte	.LASF0
	.byte	0x1
	.byte	0x15
	.4byte	0x19a
	.4byte	.LLST5
	.byte	0x3
	.4byte	.LASF1
	.byte	0x1
	.byte	0x15
	.4byte	0x1a1
	.4byte	.LLST6
	.byte	0x4
	.4byte	.LASF2
	.byte	0x1
	.byte	0x16
	.4byte	0x1b9
	.4byte	0x50000000
	.byte	0x4
	.4byte	.LASF3
	.byte	0x1
	.byte	0x17
	.4byte	0x1b9
	.4byte	0x90000000
	.byte	0x5
	.4byte	.LASF4
	.byte	0x1
	.byte	0x18
	.4byte	0x1bf
	.4byte	.LLST7
	.byte	0x6
	.4byte	.Ldebug_ranges0+0
	.4byte	0xac
	.byte	0x7
	.string	"i"
	.byte	0x1
	.byte	0x21
	.4byte	0x19a
	.4byte	.LLST8
	.byte	0
	.byte	0x6
	.4byte	.Ldebug_ranges0+0x30
	.4byte	0xc3
	.byte	0x7
	.string	"i"
	.byte	0x1
	.byte	0x27
	.4byte	0x19a
	.4byte	.LLST9
	.byte	0
	.byte	0x6
	.4byte	.Ldebug_ranges0+0x60
	.4byte	0xda
	.byte	0x7
	.string	"i"
	.byte	0x1
	.byte	0x2d
	.4byte	0x19a
	.4byte	.LLST10
	.byte	0
	.byte	0x6
	.4byte	.Ldebug_ranges0+0xf0
	.4byte	0xed
	.byte	0x8
	.string	"i"
	.byte	0x1
	.byte	0x4e
	.4byte	0x19a
	.byte	0
	.byte	0x6
	.4byte	.Ldebug_ranges0+0x120
	.4byte	0x104
	.byte	0x7
	.string	"i"
	.byte	0x1
	.byte	0x54
	.4byte	0x19a
	.4byte	.LLST12
	.byte	0
	.byte	0x6
	.4byte	.Ldebug_ranges0+0x150
	.4byte	0x117
	.byte	0x8
	.string	"i"
	.byte	0x1
	.byte	0x62
	.4byte	0x19a
	.byte	0
	.byte	0x9
	.4byte	0x223
	.8byte	.LBB18
	.4byte	.Ldebug_ranges0+0x90
	.byte	0x1
	.byte	0x3e
	.4byte	0x153
	.byte	0xa
	.4byte	0x245
	.byte	0xa
	.4byte	0x23a
	.byte	0xa
	.4byte	0x22f
	.byte	0xb
	.4byte	.Ldebug_ranges0+0x90
	.byte	0xc
	.4byte	0x29e
	.byte	0xc
	.4byte	0x2a7
	.byte	0xc
	.4byte	0x2b0
	.byte	0
	.byte	0
	.byte	0xd
	.4byte	0x1cb
	.8byte	.LBB22
	.4byte	.Ldebug_ranges0+0xc0
	.byte	0x1
	.byte	0x4b
	.byte	0xe
	.4byte	0x1ed
	.2byte	0x100
	.byte	0xf
	.4byte	0x1e2
	.4byte	0x90000000
	.byte	0xf
	.4byte	0x1d7
	.4byte	0x50000000
	.byte	0xb
	.4byte	.Ldebug_ranges0+0xc0
	.byte	0x10
	.4byte	0x1f6
	.4byte	.LLST11
	.byte	0xc
	.4byte	0x1ff
	.byte	0xc
	.4byte	0x20a
	.byte	0
	.byte	0
	.byte	0
	.byte	0x11
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0x12
	.byte	0x8
	.4byte	0x1a7
	.byte	0x12
	.byte	0x8
	.4byte	0x1b4
	.byte	0x13
	.byte	0x1
	.byte	0x8
	.4byte	.LASF5
	.byte	0x14
	.4byte	0x1ad
	.byte	0x12
	.byte	0x8
	.4byte	0x1c6
	.byte	0x13
	.byte	0x8
	.byte	0x7
	.4byte	.LASF6
	.byte	0x15
	.4byte	0x1bf
	.byte	0x16
	.4byte	.LASF10
	.byte	0x1
	.byte	0xb
	.byte	0x1
	.4byte	0x216
	.byte	0x17
	.4byte	.LASF7
	.byte	0x1
	.byte	0xb
	.4byte	0x216
	.byte	0x18
	.string	"src"
	.byte	0x1
	.byte	0xb
	.4byte	0x216
	.byte	0x18
	.string	"n"
	.byte	0x1
	.byte	0xb
	.4byte	0x19a
	.byte	0x8
	.string	"j"
	.byte	0x1
	.byte	0xc
	.4byte	0x19a
	.byte	0x19
	.4byte	.LASF8
	.byte	0x1
	.byte	0xe
	.4byte	0x21d
	.byte	0x19
	.4byte	.LASF9
	.byte	0x1
	.byte	0xf
	.4byte	0x21d
	.byte	0
	.byte	0x12
	.byte	0x8
	.4byte	0x21c
	.byte	0x1a
	.byte	0x12
	.byte	0x8
	.4byte	0x1ad
	.byte	0x16
	.4byte	.LASF11
	.byte	0x1
	.byte	0x2
	.byte	0x1
	.4byte	0x26e
	.byte	0x17
	.4byte	.LASF7
	.byte	0x1
	.byte	0x2
	.4byte	0x216
	.byte	0x18
	.string	"src"
	.byte	0x1
	.byte	0x2
	.4byte	0x216
	.byte	0x18
	.string	"n"
	.byte	0x1
	.byte	0x2
	.4byte	0x19a
	.byte	0x8
	.string	"i"
	.byte	0x1
	.byte	0x3
	.4byte	0x19a
	.byte	0x19
	.4byte	.LASF8
	.byte	0x1
	.byte	0x5
	.4byte	0x21d
	.byte	0x19
	.4byte	.LASF9
	.byte	0x1
	.byte	0x6
	.4byte	0x21d
	.byte	0
	.byte	0x1b
	.4byte	0x223
	.8byte	.LFB0
	.8byte	.LFE0-.LFB0
	.byte	0x1
	.byte	0x9c
	.byte	0x1c
	.4byte	0x22f
	.4byte	.LLST0
	.byte	0x1c
	.4byte	0x23a
	.4byte	.LLST1
	.byte	0x1d
	.4byte	0x245
	.byte	0x1
	.byte	0x5c
	.byte	0x10
	.4byte	0x24e
	.4byte	.LLST2
	.byte	0x10
	.4byte	0x257
	.4byte	.LLST3
	.byte	0x10
	.4byte	0x262
	.4byte	.LLST4
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.byte	0x1
	.byte	0x11
	.byte	0x1
	.byte	0x25
	.byte	0xe
	.byte	0x13
	.byte	0xb
	.byte	0x3
	.byte	0xe
	.byte	0x1b
	.byte	0xe
	.byte	0x55
	.byte	0x17
	.byte	0x11
	.byte	0x1
	.byte	0x10
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x2
	.byte	0x2e
	.byte	0x1
	.byte	0x3f
	.byte	0x19
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x27
	.byte	0x19
	.byte	0x49
	.byte	0x13
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x7
	.byte	0x40
	.byte	0x18
	.byte	0x97,0x42
	.byte	0x19
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x3
	.byte	0x5
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x4
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x1c
	.byte	0x6
	.byte	0
	.byte	0
	.byte	0x5
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x6
	.byte	0xb
	.byte	0x1
	.byte	0x55
	.byte	0x17
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x7
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x8
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x9
	.byte	0x1d
	.byte	0x1
	.byte	0x31
	.byte	0x13
	.byte	0x52
	.byte	0x1
	.byte	0x55
	.byte	0x17
	.byte	0x58
	.byte	0xb
	.byte	0x59
	.byte	0xb
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0xa
	.byte	0x5
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x1
	.byte	0x55
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0xc
	.byte	0x34
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0xd
	.byte	0x1d
	.byte	0x1
	.byte	0x31
	.byte	0x13
	.byte	0x52
	.byte	0x1
	.byte	0x55
	.byte	0x17
	.byte	0x58
	.byte	0xb
	.byte	0x59
	.byte	0xb
	.byte	0
	.byte	0
	.byte	0xe
	.byte	0x5
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0x1c
	.byte	0x5
	.byte	0
	.byte	0
	.byte	0xf
	.byte	0x5
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0x1c
	.byte	0x6
	.byte	0
	.byte	0
	.byte	0x10
	.byte	0x34
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x11
	.byte	0x24
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x3
	.byte	0x8
	.byte	0
	.byte	0
	.byte	0x12
	.byte	0xf
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x13
	.byte	0x24
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x3
	.byte	0xe
	.byte	0
	.byte	0
	.byte	0x14
	.byte	0x26
	.byte	0
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x15
	.byte	0x35
	.byte	0
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x16
	.byte	0x2e
	.byte	0x1
	.byte	0x3f
	.byte	0x19
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x27
	.byte	0x19
	.byte	0x20
	.byte	0xb
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x17
	.byte	0x5
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x18
	.byte	0x5
	.byte	0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x19
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x1a
	.byte	0x35
	.byte	0
	.byte	0
	.byte	0
	.byte	0x1b
	.byte	0x2e
	.byte	0x1
	.byte	0x31
	.byte	0x13
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x7
	.byte	0x40
	.byte	0x18
	.byte	0x97,0x42
	.byte	0x19
	.byte	0
	.byte	0
	.byte	0x1c
	.byte	0x5
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x1d
	.byte	0x5
	.byte	0
	.byte	0x31
	.byte	0x13
	.byte	0x2
	.byte	0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST5:
	.8byte	.LVL3
	.8byte	.LVL11
	.2byte	0x1
	.byte	0x5a
	.8byte	.LVL11
	.8byte	.LFE2
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5a
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST6:
	.8byte	.LVL3
	.8byte	.LVL12
	.2byte	0x1
	.byte	0x5b
	.8byte	.LVL12
	.8byte	.LFE2
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5b
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST7:
	.8byte	.LVL10
	.8byte	.LVL13
	.2byte	0x1
	.byte	0x5e
	.8byte	.LVL21
	.8byte	.LVL22
	.2byte	0x1
	.byte	0x5e
	.8byte	0
	.8byte	0
.LLST8:
	.8byte	.LVL4
	.8byte	.LVL5
	.2byte	0x2
	.byte	0x4f
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST9:
	.8byte	.LVL6
	.8byte	.LVL7
	.2byte	0x3
	.byte	0x8
	.byte	0x3f
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST10:
	.8byte	.LVL8
	.8byte	.LVL9
	.2byte	0x3
	.byte	0x8
	.byte	0x5f
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST12:
	.8byte	.LVL19
	.8byte	.LVL20
	.2byte	0x3
	.byte	0x8
	.byte	0x5f
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST11:
	.8byte	.LVL15
	.8byte	.LVL16
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.8byte	.LVL16
	.8byte	.LVL17
	.2byte	0x7
	.byte	0x7f
	.byte	0x80,0x80,0x80,0x80,0x7
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST0:
	.8byte	.LVL0
	.8byte	.LVL1
	.2byte	0x1
	.byte	0x5a
	.8byte	.LVL1
	.8byte	.LFE0
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5a
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST1:
	.8byte	.LVL0
	.8byte	.LVL1
	.2byte	0x1
	.byte	0x5b
	.8byte	.LVL1
	.8byte	.LFE0
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5b
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST2:
	.8byte	.LVL0
	.8byte	.LVL1
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.8byte	.LVL1
	.8byte	.LVL2
	.2byte	0x7
	.byte	0x7b
	.byte	0
	.byte	0xf3
	.byte	0x1
	.byte	0x5b
	.byte	0x1c
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST3:
	.8byte	.LVL0
	.8byte	.LVL1
	.2byte	0x1
	.byte	0x5b
	.8byte	.LVL1
	.8byte	.LFE0
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5b
	.byte	0x9f
	.8byte	0
	.8byte	0
.LLST4:
	.8byte	.LVL0
	.8byte	.LVL1
	.2byte	0x1
	.byte	0x5a
	.8byte	.LVL1
	.8byte	.LFE0
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5a
	.byte	0x9f
	.8byte	0
	.8byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x3c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.8byte	.LFB2
	.8byte	.LFE2-.LFB2
	.8byte	0
	.8byte	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.8byte	.LBB12
	.8byte	.LBE12
	.8byte	.LBB13
	.8byte	.LBE13
	.8byte	0
	.8byte	0
	.8byte	.LBB14
	.8byte	.LBE14
	.8byte	.LBB15
	.8byte	.LBE15
	.8byte	0
	.8byte	0
	.8byte	.LBB16
	.8byte	.LBE16
	.8byte	.LBB17
	.8byte	.LBE17
	.8byte	0
	.8byte	0
	.8byte	.LBB18
	.8byte	.LBE18
	.8byte	.LBB21
	.8byte	.LBE21
	.8byte	0
	.8byte	0
	.8byte	.LBB22
	.8byte	.LBE22
	.8byte	.LBB26
	.8byte	.LBE26
	.8byte	0
	.8byte	0
	.8byte	.LBB25
	.8byte	.LBE25
	.8byte	.LBB27
	.8byte	.LBE27
	.8byte	0
	.8byte	0
	.8byte	.LBB28
	.8byte	.LBE28
	.8byte	.LBB29
	.8byte	.LBE29
	.8byte	0
	.8byte	0
	.8byte	.LBB30
	.8byte	.LBE30
	.8byte	.LBB31
	.8byte	.LBE31
	.8byte	0
	.8byte	0
	.8byte	.Ltext0
	.8byte	.Letext0
	.8byte	.LFB2
	.8byte	.LFE2
	.8byte	0
	.8byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF10:
	.string	"custom_memcpy_2"
.LASF11:
	.string	"custom_memcpy"
.LASF3:
	.string	"addr_dram"
.LASF0:
	.string	"argc"
.LASF5:
	.string	"char"
.LASF7:
	.string	"dest"
.LASF12:
	.string	"GNU C99 7.2.0 -mcmodel=medany -march=rv64imafdc -mabi=lp64d -g -O2 -std=gnu99 -ffast-math -fno-common -fno-builtin-printf -fno-tree-loop-distribute-patterns"
.LASF8:
	.string	"src_char"
.LASF6:
	.string	"long long unsigned int"
.LASF13:
	.string	"hello_rsa.c"
.LASF15:
	.string	"main"
.LASF9:
	.string	"dest_char"
.LASF4:
	.string	"data"
.LASF14:
	.string	"/home/UFAD/mrahman1/cva6_for_se/cva6_09222023"
.LASF2:
	.string	"addr_rsa"
.LASF1:
	.string	"argv"
	.ident	"GCC: (GNU) 7.2.0"
