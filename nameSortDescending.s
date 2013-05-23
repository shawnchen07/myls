	.file	"nameSortDescending.c"
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"amazing.z"
	.asciz	""
	.align 8
.LLC1:
	.asciz	"amazing.a"
	.asciz	""
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -1416, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	add	%fp, -668, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %o1
	mov	10, %o2
	call	memcpy, 0
	 nop
	add	%fp, -1316, %g1
	mov	%g1, %o0
	sethi	%hi(.LLC1), %g1
	or	%g1, %lo(.LLC1), %o1
	mov	10, %o2
	call	memcpy, 0
	 nop
	add	%fp, -668, %g1
	add	%fp, -1316, %g2
	mov	%g1, %o0
	mov	%g2, %o1
	call	nameSortDescending, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
	ld	[%fp-20], %g1
	mov	%g1, %i0
	return	%i7+8
	 nop
	.size	main, .-main
	.align 4
	.global nameSortDescending
	.type	nameSortDescending, #function
	.proc	04
nameSortDescending:
	save	%sp, -120, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+72], %g1
	ld	[%fp+68], %g2
	mov	%g1, %o0
	mov	%g2, %o1
	call	strcmp, 0
	 nop
	mov	%o0, %g1
	cmp	%g1, 0
	bne	%icc, .LL4
	 nop
	st	%g0, [%fp-20]
	ba,pt	%xcc, .LL5
	 nop
.LL4:
	ld	[%fp+72], %g1
	ld	[%fp+68], %g2
	mov	%g1, %o0
	mov	%g2, %o1
	call	strcmp, 0
	 nop
	mov	%o0, %g1
	cmp	%g1, 0
	ble	%icc, .LL6
	 nop
	mov	1, %g1
	st	%g1, [%fp-20]
	ba,pt	%xcc, .LL5
	 nop
.LL6:
	ld	[%fp+72], %g1
	ld	[%fp+68], %g2
	mov	%g1, %o0
	mov	%g2, %o1
	call	strcmp, 0
	 nop
	mov	%o0, %g1
	cmp	%g1, 0
	bge	%icc, .LL7
	 nop
	mov	-1, %g1
	st	%g1, [%fp-20]
	ba,pt	%xcc, .LL5
	 nop
.LL7:
	ba,pt	%xcc, .LL3
	 nop
.LL5:
	ld	[%fp-20], %g1
	st	%g1, [%fp-24]
.LL3:
	ld	[%fp-24], %i0
	return	%i7+8
	 nop
	.size	nameSortDescending, .-nameSortDescending
	.ident	"GCC: (GNU) 4.3.3"
