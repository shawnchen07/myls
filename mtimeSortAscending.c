/*
 * Filename: mtimeSortAscending.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Sorts in ascending order.
 * Date: Nov 28, 2011
 *
 */

#include "myls.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stddef.h>

/* Function name: mtimeSortAscending()
 * Function prototype: int mtimeSortAscending( const void *p1,
 *                                              const void *p2 );
 * Description: Sorts in ascending order.
 * Parameters:
 *      p1: pointer to first object
 *      p2: pointer to second object
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: int
 */

int mtimeSortAscending( const void *p1, const void *p2 )
{
  return  ((struct fileInfo *) p1)->stbuf.st_mtime -
           ((struct fileInfo *) p2)->stbuf.st_mtime ;

} /* end mtimeSortAscending() */
