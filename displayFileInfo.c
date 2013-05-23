/*
 * Filename: displayFileInfo.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Displays the file info table.
 * Date: Nov 27, 2011
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
#include <sys/stat.h>
#include <sys/mkdev.h>

/* Function name: displayFileInfo()
 * Function prototype: void displayFileInfo( struct fileInfo * const table,
 *                              const int entries, const int displayMode );
 * Description: Displays the file info table.
 * Parameters:
 *      table: table passed in
 *      entries: number of entries
 *      displayMode: display mode integer
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: int
 */

void displayFileInfo( struct fileInfo * const table, 
                      const int entries, const int displayMode )
{
  char buff[MAXNAMLEN];
  int i;
  time_t theTime;
  int bFlag = 0;
  int cFlag = 0;

  /* Set the TFLAG */
  if (TFLAG & displayMode)
  {
    /* Set T and R flags */
    if (RFLAG & displayMode)
    {
      /* (void) printf("1\n"); */
      (void) qsort(table, entries,
                   sizeof(struct fileInfo), mtimeSortAscending);
      
      if (!(AFLAG & displayMode) && !(LFLAG & displayMode))
      {
        /* Print name of every file in the table */
        for (i=0; i<entries; i++)
        {
          (void) strncpy (buff, table[i].name, MAXNAMLEN);

          if (buff[0] != '.')
          {
            (void) printf("%s\n",(table+i)->name);
          }
        }
      }

    }

    /* Set T flag only */
    else
    {
      /* (void) printf("2\n"); */
      (void) qsort(table, entries,
                   sizeof(struct fileInfo), mtimeSortDescending);
      
      if (!(AFLAG & displayMode) && !(LFLAG & displayMode))
      {
        /* Print name of every file in the table */
        for (i=0; i<entries; i++)
        {
          (void) strncpy (buff, table[i].name, MAXNAMLEN);

          if (buff[0] != '.')
          {
            (void) printf("%s\n",(table+i)->name);
          }
        }
      }
    }
  }

  /* Set R flag only */
  else if ((RFLAG & displayMode) && !(TFLAG & displayMode))
  {
    /* (void) printf("3\n"); */

    (void) qsort(table, entries, sizeof(struct fileInfo), nameSortDescending);

    if (!(LFLAG & displayMode))
    {
      if (!(AFLAG & displayMode))
      {
        /* Print name of every file in the table */
        for (i=0; i<entries; i++)
        {
          (void) strncpy (buff, table[i].name, MAXNAMLEN);

          if (buff[0] != '.')
          {
            (void) printf("%s\n",(table+i)->name);
          }
        }
      }
    }
  }

  /* Neither T or R set */
  if (!(TFLAG & displayMode) && !(RFLAG & displayMode))
  {
    /* (void) printf("4\n"); */

    (void) qsort(table, entries, sizeof(struct fileInfo), nameSortAscending);
  }

  /* Set L and A flags */
  if ((LFLAG & displayMode) && (AFLAG & displayMode))
  {
    /* (void) printf("5\n"); */

    /* Print name of every file in the table */
    for (i=0; i<entries; i++)
    {
      (void) strncpy (buff, table[i].name, MAXNAMLEN);

        if (S_ISDIR(((table[i]).stbuf).st_mode) == 1)
        {
          (void) printf("d");
          /*dFlag = 1;*/
        }

        else if (S_ISLNK(((table[i]).stbuf).st_mode) == 1)
        {
          (void) printf("l");
        }

        else if (S_ISBLK((table[i].stbuf).st_mode) == 1)
        {
          (void) printf("b");
          bFlag = 1;
        }

        else if (S_ISCHR((table[i].stbuf).st_mode) == 1)
        {
          (void) printf("c");
          cFlag = 1;
        }

        else
        {
          (void) printf("-");
        }

        (void) displayPermissions((table[i].stbuf).st_mode);

        (void) printf("%4d ", (int)((table[i].stbuf).st_nlink));

        displayOwnerName((table[i].stbuf).st_uid);

        displayGroupName((table[i].stbuf).st_gid);

        if (bFlag || cFlag)
        {
          (void) printf("%6d,%3d",(int)major((table[i].stbuf).st_rdev),
                        (int)minor((table[i].stbuf).st_rdev));

          bFlag = 0;
          cFlag = 0;
        }
        else
        {
          (void) printf("%10ld", (table[i].stbuf).st_size);
        }

        theTime = (table[i].stbuf).st_mtime;

        if ( ((int) theTime) > (time(NULL) - 15724800) )
        {
          /* char * ctime( time_t * ) */
          char * time1 = ctime( &theTime );

          char * s1 = strchr (time1, ' ');
          char * s2 = strrchr (time1, ':');
          

          *s2 = '\0';

          (void) printf(" %s", s1+1);

        }

        else
        {
          /* char * ctime( time_t * ) */
          char * time1 = ctime( &theTime );

          char * r1 = strchr (time1, ' ');
          char * r2 = strchr (time1, ':');
          r2 -= 3;

          char * r3 = strrchr (time1, ' ');
          char * r4 = strrchr (time1, '\n');

          *r2 = '\0';
          *r4 = '\0';

          (void) printf(" %s  %s", r1+1, r3+1);
        }

        (void) printf(" %s\n", (table+i)->name);
    }

  }

  /* Set L flag */
  if ((LFLAG & displayMode) && !(AFLAG & displayMode))
  {
    /* (void) printf("6\n"); */

    /* Print name of every file in the table */
    for (i=0; i<entries; i++)
    {
      (void) strncpy (buff, table[i].name, MAXNAMLEN);

      if (buff[0] != '.')
      {

        if (S_ISDIR(((table[i]).stbuf).st_mode) == 1)
        {
          (void) printf("d");
        }

        else if (S_ISLNK((table[i].stbuf).st_mode == 1))
        {
          (void) printf("l");
        }

        else if (S_ISBLK((table[i].stbuf).st_mode) == 1)
        {
          (void) printf("b");
          bFlag = 1;
        }

        else if (S_ISCHR((table[i].stbuf).st_mode) == 1)
        {
          (void) printf("c");
          cFlag = 1;
        }

        else
        {
          (void) printf("-");
        }

        (void) displayPermissions((table[i].stbuf).st_mode);

        (void) printf("%4d ", (int)((table[i].stbuf).st_nlink));

        displayOwnerName((table[i].stbuf).st_uid);

        displayGroupName((table[i].stbuf).st_gid);

        if (bFlag || cFlag)
        {
          (void) printf("%6d,%3d",(int)major((table[i].stbuf).st_rdev),
                        (int)minor((table[i].stbuf).st_rdev));

          bFlag = 0;
          cFlag = 0;
        }
        else
        {
          (void) printf("%10ld", (table[i].stbuf).st_size);
        }

        theTime = (table[i].stbuf).st_mtime;

        if ( ((int) theTime) > (time(NULL) - 15724800) )
        {
          /* char * ctime( time_t * ) */
          char * time1 = ctime( &theTime );

          char * s1 = strchr (time1, ' ');
          char * s2 = strrchr (time1, ':');
          

          *s2 = '\0';

          (void) printf(" %s", s1+1);

        }

        else
        {
          /* char * ctime( time_t * ) */
          char * time1 = ctime( &theTime );

          char * r1 = strchr (time1, ' ');
          char * r2 = strchr (time1, ':');
          r2 -= 3;

          char * r3 = strrchr (time1, ' ');
          char * r4 = strrchr (time1, '\n');

          *r2 = '\0';
          *r4 = '\0';

          (void) printf(" %s  %s", r1+1, r3+1);
        }

        (void) printf(" %s\n", (table+i)->name);
      }
    }

  }
  
  /* Set A flag */
  if ((AFLAG & displayMode) && !(LFLAG & displayMode))
  {
    /* (void) printf("7\n"); */

    if (entries == 1)
    {
      (void) printf("%s\n",table[0].name);
    }
    else
    {
      /* Print name of every file in the table */
      for (i=0; i<entries; i++)
      {
        (void) printf("%s\n",(table+i)->name);
      }
    }
  }

  if (!(AFLAG & displayMode) && !(LFLAG & displayMode) &&
      !(RFLAG & displayMode) && !(TFLAG & displayMode))
  {
    /* (void) printf("8\n"); */

    for (i=0; i<entries; i++)
    {
      (void) strncpy (buff, table[i].name, MAXNAMLEN);

      if (buff[0] != '.')
      {
        (void) printf("%s\n",(table+i)->name);
      }
    }
  }

} /* end displayFileInfo() */
