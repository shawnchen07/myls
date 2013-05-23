#ifndef _MYLS_H
#define _MYLS_H

#define AFLAG 0x1
#define LFLAG 0x2
#define RFLAG 0x4
#define TFLAG 0x8

#include <dirent.h>     /* To pick up MAXNAMLEN - maximum filename length */
#include <sys/stat.h>   /* For struct stat definition */

struct fileInfo {
    char name[MAXNAMLEN];
    struct stat stbuf;
};

int buildFileInfoTable( const char *filename, struct fileInfo ** const tablePtr );

void displayFileInfo( struct fileInfo * const table, const int entries,
                      const int displayMode );

int mtimeSortAscending( const void *p1, const void *p2 );
int mtimeSortDescending( const void *p1, const void *p2 );
int nameSortAscending( const void *p1, const void *p2 );
int nameSortDescending( const void *p1, const void *p2 );
void displayPermissions( const mode_t mode );
void displayOwnerName( const uid_t uid );
void displayGroupName( const gid_t gid );

#endif /* _MYLS_H */
