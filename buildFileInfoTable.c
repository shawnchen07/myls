/*
 * Filename: buildFileInfoTable.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Builds the file info table database.
 * Date: Nov. 23, 2011
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

/* Function name: buildFileInfoTable()
 * Function prototype: int buildFileInfoTable( const char *filename,
 *                              struct fileInfo ** const tablePtr );
 * Description: Builds the file info table database.
 * Parameters:
 *      const char *filename: name of the file
 *      struct fileInfo ** const tablePtr: address of pointer to fileInfo
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: int
 */

int buildFileInfoTable(const char *filename, struct fileInfo **const tablePtr)
{
  struct stat stbuf;
  struct fileInfo *table;
  struct dirent *direntPtr;
  DIR *dirPtr = NULL;
  char dirContainer[MAXNAMLEN];
  int entries = 0;
  char filenameShort[MAXNAMLEN];

  if (lstat(filename, &stbuf) == -1)
  {
    (void) fprintf(stderr, "lstat -- ");
    (void) perror(filename);
    return 0;
  }

  /* If not a directory, use S_ISDIR() */
  if (S_ISDIR(stbuf.st_mode) != 1) /* File */
  {
    table = (struct fileInfo *) malloc(sizeof(struct fileInfo));

    if (table == NULL)
    {
      (void) fprintf(stderr, "Trying to malloc a struct fileInfo " 
                             "(in buildFileInfoTable())\n");
      return 0;
    }

    /* Fill it with the name of the file and the stat info */
    /* Set tablePtr back to point to fileInfo struct and return 1 */

    (void) strncpy(table[0].name, filename, MAXNAMLEN);
    table[0].stbuf = stbuf;
    *tablePtr = table;

    return 1;
  }

  if (S_ISDIR(stbuf.st_mode) == 1)
  {

    dirPtr = opendir(filename);
    (void) printf("%s:\n", filename);

    if (dirPtr == NULL)
    {
      (void) fprintf(stderr, "opendir -- ");
      (void) perror(filename);
      return 0;
    }

    table = (struct fileInfo *) malloc(sizeof(struct fileInfo));

    if (table == NULL)
    {
      (void) fprintf(stderr, "Trying to malloc a struct fileInfo " 
                             "(in buildFileInfoTable())\n");
      return 0;
    }

    while ( (direntPtr = readdir(dirPtr)) != NULL)
    {
      (void) strncpy(filenameShort, filename, MAXNAMLEN);

      (void) snprintf(dirContainer, MAXNAMLEN, "%s/%s",
                      filenameShort, direntPtr->d_name);
      (void) lstat(dirContainer, &stbuf);
   
      table = (struct fileInfo *) realloc(table,
                 sizeof(struct fileInfo)*(entries+1));

      if (table == ((struct fileInfo *) malloc(sizeof(struct fileInfo)) ))
      {
        (void) fprintf(stderr, "Trying to realloc another struct "
                               "fileInfo (in buildFileInfoTable())\n");
        (void) fprintf(stderr, "Only partial info will be displayed.\n");

        return 0;

      }

      entries++;

     (void) strncpy(table[entries - 1].name, direntPtr->d_name, MAXNAMLEN);
     table[entries - 1].stbuf = stbuf;

     /* Fill in "new spot" = table[entries] */
    }
      *tablePtr = table;

      return entries;
  }

  return 1;
} /* end buildFileInfoTable() */
