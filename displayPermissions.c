/*
 * Filename: displayPermissions.c
 * Author: Shawn Young Chen
 * Userid: cs30xaz
 * Description: Displays the permissions of the file or directory.
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

/* Function name: displayPermissions()
 * Function prototype: void displayPermissions( const mode_t mode );
 * Description: Displays the permissions of the file or directory.
 * Parameters:
 *      const mode_t mode: mode_t variable passed in
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: None
 */

void displayPermissions( const mode_t mode )
{
  /* Prints out the permissions of the owner */
  if ((mode & S_IRUSR) && (mode & S_IREAD))
  {
    (void) printf("r");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IWUSR) && (mode & S_IWRITE))
  {
    (void) printf("w");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IXUSR) && (mode & S_IEXEC))
  {
    (void) printf("x");
  }
  else
  {
    (void) printf("-");
  }

  /* Prints out the permissions of the group */
  if ((mode & S_IRGRP) && (mode & S_IREAD))
  {
    (void) printf("r");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IWGRP) && (mode & S_IWRITE))
  {
    (void) printf("w");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IXGRP) && (mode & S_IEXEC))
  {
    (void) printf("x");
  }
  else
  {
    (void) printf("-");
  }

  /* Prints out misc. permissions of the user */
  if ((mode & S_IROTH) && (mode & S_IREAD))
  {
    (void) printf("r");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IWOTH) && (mode & S_IWRITE))
  {
    (void) printf("w");
  }
  else
  {
    (void) printf("-");
  }

  if ((mode & S_IXOTH) && (mode & S_IEXEC))
  {
    (void) printf("x");
  }
  else
  {
    (void) printf("-");
  }
  
} /* end displayPermissions() */

