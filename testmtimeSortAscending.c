/*
 * Filename: testmtimeSortAscending.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Unit test program to test the function mtimeSortAscending.
 * Date: Nov. 11, 2011
 * Sources of Help: Textbook, lab tutors
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "myls.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stddef.h>

FILE *stdError = stderr;

/*
 * int teststrToLong( long value, long minRange, long maxRange );
 *
 * Returns 1 if value is within minRange and maxRange, inclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.


int charCompare( const void *ptr1, const void *ptr2 );
 */

struct stat stbuf;
int mtime_offst = offsetof(struct fileInfo, stbuf.st_mtime);


void
testmtimeSortAscending()
{
    printf( "Testing mtimeSortAscending()\n" );

    struct fileInfo uno;
    struct fileInfo dos;

    strncpy(uno.name, "amazing.z\0", 10);
    strncpy(dos.name, "amazing.a\0", 10);

    TEST( mtimeSortAscending(&uno, &dos) > 0);

    strncpy(uno.name, "amazing.a\0", 10);
    strncpy(dos.name, "amazing.z\0", 10);

    TEST( mtimeSortAscending(&uno, &dos) < 0);

    strncpy(uno.name, "abcd...efg\0", 11);
    strncpy(dos.name, "abcd...efg\0", 11);

    TEST( mtimeSortAscending(&uno, &dos) == 0);

    strncpy(uno.name, "abcd...efg\0", 11);
    strncpy(dos.name, "abdc...efg\0", 11);

    TEST( mtimeSortAscending(&uno, &dos) < 0);

    printf( "Finished running tests on mtimeSortAscending()\n" );
}

int
main()
{
    testmtimeSortAscending();

    return 0;
}






