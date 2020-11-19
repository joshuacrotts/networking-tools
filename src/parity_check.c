#include "../include/parity_check.h"

#define MAX_BINARY      1022
#define MAX_BUFFER_SIZE 1024

/**
 * 
 *
 * @param
 * 
 * @return
 */
void compute_parity_check() {
  char   buffer[MAX_BUFFER_SIZE];
  size_t string_len = 0;

  printf( "Enter a binary number up to 1022 digits (0011101101): " );
  fgets( buffer, sizeof( buffer ), stdin );
  // The last char is the vertical return char.
  string_len = strlen( buffer ) - 1;

  if ( string_len > MAX_BINARY ) {
    fprintf( stderr, "Cannot read in a binary number this large." );
    exit( EXIT_FAILURE );
  }

  if ( !is_valid_binary_str( buffer, string_len ) ) {
    fprintf( stderr, "String contains non-binary symbols." );
    exit( EXIT_FAILURE );
  }

  int  signed_bits = count_set_bits_str( buffer, string_len );
  char added_char  = ( signed_bits & 1 ) != 0 ? '1' : '0';

  buffer[string_len] = added_char;

  printf( "Even-parity bit mod: %s\n", buffer );
}
