#include "../include/stds.h"

#define MAX_INT_DIGITS 11
#define MAX_LINE_LEN   1024

static char text_buffer[MAX_LINE_LEN];
static char number_buffer[MAX_INT_DIGITS];

/*
 * Finds and returns the substring between the indices
 * [first, last). (last - first) gives the number of characters
 * inside the returning char*.
 *
 * @precondition last > first, first >= 0 and last >= 0,
 *               first < length of str and last < length of
 *               str.
 *
 * @param char * string with substring to find.
 * @param int first index of substring.
 * @param int index to stop the search (not inclusive!).
 *
 * @return char* substring.
 */
char* 
str_substring(const char* str, const int first, const int last){
  char* s = malloc(sizeof(char) * (last - first));
  memcpy(s, str + first, last - first);
  return s;
}

/*
 * Returns the index of the first occurrence of search_str
 * inside s.
 *
 * @param char* string to search in.
 * @param char* string to search for.
 *
 * @return int32_t >= 0 for index, -1 if not in string.
 */
int32_t
str_index_of( char* s, const char* search_str ) {
  const char *ptr = strstr( s, search_str );

  if ( ptr ) {
    int32_t index = ptr - s;
    return index;
  }

  return -1;
}

/*
 * Concatenates a signed 32-bit integer to the end of
 * a string.
 *
 * @return modified string with number on end.
 */
char *
strcat_intptr( const char *s, const int32_t n ) {
  memset(text_buffer, '\0', sizeof(text_buffer));
  strncat(text_buffer, s, strlen(s));
  int32_t digits = snprintf(number_buffer, MAX_INT_DIGITS, "%d", n);
  strncat(text_buffer, number_buffer, digits);
  return text_buffer;
}

/**
 * Concatenates a signed 32-bit integer to the end of
 * a string array.
 * 
 * @param const char [] array for string.
 * @param const int32_t integer to concatenate.
 * 
 * @return char * string with concatenated integer.
 */
char *
strcat_intarray( const char s[], const int32_t n ) {
  memset( text_buffer, '\0', sizeof( text_buffer ) );
  strncat( text_buffer, s, strlen( s ) );
  int32_t digits = snprintf( number_buffer, MAX_INT_DIGITS, "%d", n );
  strncat( text_buffer, number_buffer, digits );
  return text_buffer;
}
