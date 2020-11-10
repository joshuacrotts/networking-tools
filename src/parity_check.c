#include "../include/parity_check.h"

#define MAX_BINARY      1022
#define MAX_BUFFER_SIZE 1024

static int  count_set_bits( char buffer[], size_t arr_size );
static bool is_binary_string_valid( char buffer[], size_t arr_size );

/**
 *
 */
void compute_parity_check() {
  char   buffer[MAX_BUFFER_SIZE];
  size_t string_len = 0;

  printf( "Enter a binary number up to 1022 digits: " );
  fgets( buffer, sizeof( buffer ), stdin );
  // The last char is the vertical return char.
  string_len = strlen( buffer ) - 1;

  if ( string_len > MAX_BINARY ) {
    fprintf( stderr, "Cannot read in a binary number this large." );
    exit( EXIT_FAILURE );
  }

  if ( !is_binary_string_valid( buffer, string_len ) ) {
    fprintf( stderr, "String contains non-binary symbols." );
    exit( EXIT_FAILURE );
  }

  int  signed_bits = count_set_bits( buffer, string_len );
  char added_char  = ( signed_bits & 1 ) != 0 ? '1' : '0';

  buffer[string_len] = added_char;

  printf( "Even-parity bit mod: %s\n", buffer );
}

/**
 *
 */
static int
count_set_bits( char buffer[], size_t arr_size ) {
  int signed_bits = 0;

  for ( size_t i = 0; i < arr_size; i++ ) {
    char ch = buffer[i];
    if ( ch == '1' ) {
      signed_bits++;
    }
  }

  return signed_bits;
}

/**
 *
 */
static bool
is_binary_string_valid( char buffer[], size_t arr_size ) {
  for ( size_t i = 0; i < arr_size; i++ ) {
    char ch = buffer[i];
    if ( ch != '0' && ch != '1' ) {
      return false;
    }
  }

  return true;
}