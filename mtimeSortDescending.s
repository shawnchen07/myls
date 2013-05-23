/*
 * Filename: mtimeSortDescending.s
 * Author: Shawn Young Chen
 * Userid: cse30xaz
 * Description: Assembly file that compares characters, returning an int
 *              value that indicates if the characters are same or not.
 * Date: Nov. 28, 2011
 * Sources of Help: Lab tutors, textbook
 */

	.global	mtimeSortDescending
	.section ".text"

/*
 * Function name: mtimeSortDescending()
 * Function prototype: int mtimeSortDescending( const void *p1, 
 *                                              const void *p2 );
 * Description: Compares characters.
 * Parameters:
 *      arg 1: const void *ptr1 -- pointer to first character
 *      arg 2: const void *ptr2 -- pointer to second character
 *
 * Side Effects: Returns an int
 * Error Conditions: If a pointer to a null object is passed in.
 * Return Value: int
 *
 * Registers Used:
 *      %o0 - *ptr1
 *	%o1 - *ptr2
 */

mtimeSortDescending:

	set     mtime_offst, %o3
	ld	[%o3], %o4		! loading the offset int
	ld	[%o0 + %o4], %o0	! add offset to arg1
	ld	[%o1 + %o4], %o1	! add offset to arg2

	sub	%o1, %o0, %o0

	retl				! leaf return
	nop
