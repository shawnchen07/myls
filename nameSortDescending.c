/*
 * Filename: nameSortDescending.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Sorts in descending order.
 * Date: Nov 28, 2011
 *
 */

#include "myls.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <dirent.h>
#include <sys/types.h>
#include <libgen.h>

/* Function name: nameSortDescending()
 * Function prototype: int nameSortDescending( const void *p1,
 *                                              const void *p2 );
 * Description: Sorts in descending order.
 * Parameters:
 *      p1: pointer to first object
 *      p2: pointer to second object
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: int
 */

int nameSortDescending( const void *p1, const void *p2 )
{
  /* ptr1 is a file info pointer to the passed in pointer 1 */
  struct fileInfo * ptr1 = (struct fileInfo *) p1;

  /* ptr2 is a file info pointer to the passed in pointer 2 */
  struct fileInfo * ptr2 = (struct fileInfo *) p2;

  /* Subtract the result of the name members from file info struct */
  return strcmp(ptr2->name,ptr1->name);

} /* end nameSortDescending() */

