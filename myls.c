/*
 * Filename: main.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Where the code starts, calling other functions
 *              and checking for errors
 * Date: Nov. 17, 2011
 *
 */

#include "myls.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define OFFSET_OF 5;

/* Function name: myls()
 * Function prototype: int main (int argc, char *argv[]);
 * Description: Calls functions and error checks
 * Parameters:
 *      argc: total number of arguments passed in
 *      argv[]: array of arguments passed in
 * Side Effects: Outputs nonzero if error occurs, 1 if none occur
 * Error Conditions: None
 * Return Value: int
 */

  /* global variable, which is used in mtimeSortDescending.s */
  struct stat stbuf;
  int mtime_offst = offsetof(struct fileInfo, stbuf.st_mtime);


int main (int argc, char *argv[])
{
  const char *filename;
  struct fileInfo **const tablePtr = (struct fileInfo **const) malloc(
                                                    sizeof(struct fileInfo));
;
  int c;
  int entries;
  int optstring = 0x0;

  while ((c = getopt(argc, argv, "alrt")) != EOF)
  {
    switch (c)
    {
      case 'a':
        optstring |= AFLAG;
        break;
      case 'l':
        optstring |= LFLAG;
        break;
      case 'r':
        optstring |= RFLAG;
        break;
      case 't':
        optstring |= TFLAG;
        break;
      case '?':
        /* print to stderr and exit */
        (void) fprintf(stderr, "Usage: %s [-alrt] [file ...]\n", argv[0]);
        exit(1);
    }
  }

  if (argv[optind] != NULL)
  {
    /* If multiple arguments are given*/
    for ( ; optind < argc; optind++)
    {
      filename = argv[optind];

      entries = buildFileInfoTable(filename, tablePtr);
    
      (void) displayFileInfo( *tablePtr, entries, (const int) optstring );
      (void) free(*tablePtr);
    }
  }
  else
  {
     entries = buildFileInfoTable(".", tablePtr);
    
    (void) displayFileInfo( *tablePtr, entries, (const int) optstring );
    (void) free(*tablePtr);
  }

  return 0;
} /* end myls() */


