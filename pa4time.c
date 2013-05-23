#include <sys/types.h>
#include <time.h>
#include <stdio.h>

time_t pa4time( time_t *t )
{

    time_t retval = time( 0 );
        
    if ( t != NULL )
    {
      *t = retval;
    }

    return retval;
}
