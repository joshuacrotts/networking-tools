#ifndef C_STRING_H
#define C_STRING_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_DIGITS 11

extern char *str_substring( const char *str, const int first, const int last );

extern int32_t str_index_of( char *s, const char *search_str );

extern char *strcat_intptr( const char *s, const int32_t n );

extern char *strcat_intarray( const char s[], const int32_t n );

#endif
