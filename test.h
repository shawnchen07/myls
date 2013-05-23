#ifndef TEST

#include <stdio.h>

#define TEST(EX) (void)((EX) || \
(fprintf( stderr, "FAIL: %s File: %s Line: %d\n" , #EX, __FILE__, __LINE__)))

#endif
