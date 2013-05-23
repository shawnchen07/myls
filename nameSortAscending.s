/*
 * Filename: nameSortAscending.s
 * Author: Shawn Young Chen
 * Userid: cse30xaz
 * Description: Assembly file that compares characters, returning an int
 *              value that indicates if the characters are same or not.
 * Date: Nov. 28, 2011
 * Sources of Help: Lab tutors, textbook
 */

	.global	nameSortAscending
	.section ".text"

/*
 * Function name: nameSortAscending()
 * Function prototype: int nameSortAscending( const void *p1,
                                              const void *p2 );
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
 *      %i0 - *ptr1
 *	%i1 - *ptr2
 */

nameSortAscending:
	save	%sp, -(92)&-8, %sp

	mov	%i0, %o0
	mov	%i1, %o1
	call	strcmp
	nop

	mov	%o0, %i0

	ret
	restore
