/*
 * Filename: testnameSortDescending.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Unit test program to test the function nameSortDescending.
 * Date: Nov. 11, 2011
 * Sources of Help: Textbook, lab tutors
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "myls.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
#include <errno.h>
#include <stdio.h>
#include <string.h>

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

void
testnameSortDescending()
{
    printf( "Testing nameSortDescending()\n" );

    struct fileInfo uno;
    struct fileInfo dos;

    strncpy(uno.name, "amazing.z\0", 10);
    strncpy(dos.name, "amazing.a\0", 10);

    TEST( nameSortDescending(&uno, &dos) < 0);

    strncpy(uno.name, "amazing.a\0", 10);
    strncpy(dos.name, "amazing.z\0", 10);

    TEST( nameSortDescending(&uno, &dos) > 0);

    strncpy(uno.name, "abcd...efg\0", 11);
    strncpy(dos.name, "abcd...efg\0", 11);

    TEST( nameSortDescending(&uno, &dos) == 0);

    strncpy(uno.name, "abcd...efg\0", 11);
    strncpy(dos.name, "abdc...efg\0", 11);

    TEST( nameSortDescending(&uno, &dos) > 0);


/*
    strncpy(uno.word, "stop\0", 5);
    strncpy(uno.sorted, "opst\0", 5);
    strncpy(dos.word, "stop\0", 5);
    strncpy(dos.sorted, "opst\0", 5);

    TEST( nameSortDescending(&uno, &dos) == 0);

    strncpy(uno.word, "art\0", 4);
    strncpy(uno.sorted, "art\0", 4);
    strncpy(dos.word, "tar\0", 4);
    strncpy(dos.sorted, "art\0", 4);

    TEST( nameSortDescending(&uno, &dos) < 0);

    strncpy(uno.word, "art\0", 4);
    strncpy(uno.sorted, "art\0", 4);
    strncpy(dos.word, "heart\0", 6);
    strncpy(dos.sorted, "aehrt\0", 6);

    TEST( nameSortDescending(&uno, &dos) > 0);

*/
    printf( "Finished running tests on nameSortDescending()\n" );
}

int
main()
{
    testnameSortDescending();

    return 0;
}





