/*
 * Filename: displayGroupName.s
 * Author: Shawn Young Chen
 * Userid: cse30xaz
 * Description: Assembly file that displays the group name.
 * Date: Nov. 29, 2011
 * Sources of Help: Lab tutors, textbook
 */

	.global	displayGroupName
	.section ".data"
arg1:
	.asciz "%-6s"
arg2:
	.asciz "%-8d"

	.section ".text"

/*
 * Function name: displayGroupName()
 * Function prototype: void displayGroupName( const gid_t gid )
 * Description: Displays the group name.
 * Parameters:
 *      arg 1: const gid_t gid -- gid_t constant passed in
 *
 * Side Effects: None
 * Error Conditions: If a null object is passed in.
 * Return Value: None
 *
 * Registers Used:
 *      %i0 - gid
 *
 *	%l0 - p1
 */

displayGroupName:
	save	%sp, -(92)&-8, %sp

	mov	%i0, %o0
	call	getgrgid		! p1 = getgrgid(gid);
	nop

	mov	%o0, %l0

	cmp	%l0, %g0
	be	else
	nop

	set	arg1, %o0

	ld	[%l0], %o1		! p1->gr_name
	call	printf			! pass in string
	nop				! using printf

	ba	end
	nop

else:
	set	arg2, %o0
	mov	%i0, %o1		! pass in int
	call	printf			! using printf
	nop

end:
	ret
	restore
