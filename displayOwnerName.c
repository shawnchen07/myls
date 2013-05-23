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
#include <pwd.h>

/* Function name: displayFileInfo()
 * Function prototype: void displayOwnerName( const uid_t uid );
 * Description: Displays the file info table.
 * Parameters:
 *      uid_t: uid passed in
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: None
 */

void displayOwnerName( const uid_t uid )
{
  struct passwd *password;
  password = getpwuid(uid);

  if (password != NULL)
  {
    (void) printf("%-9s", password->pw_name);
  }
  else
  {
    (void) printf("%-9d", (int) uid);
  }
} /* end displayOwnerName() */
