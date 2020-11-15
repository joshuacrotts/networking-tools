#include "../include/checksum.h"

#define BUFFER_SIZE 256

static char buffer[BUFFER_SIZE];

/**
 * Computes the standard TCP/IP checksum algorithm. The input should be
 * a standard hex string.
 * 
 * @param void.
 * 
 * @return void.
 */
void
compute_checksum() {
  printf("Enter your hex string WITHOUT the hex prefix with length multiple of 4 (AB12CCDD): ");
  char *   hex_string = fgets( buffer, BUFFER_SIZE, stdin );
  uint32_t str_len    = strlen( hex_string ) - 1;

  if ( str_len % 4 != 0 ) {
    fprintf( stderr,
             "Error, your hex string length must be a multiple of four (pairs of bytes).\n" );
    exit( EXIT_FAILURE );
  }

  unsigned int checksum = 0;
  for ( size_t i = 0; i < str_len; i += 4 ) {
    char *  substring = Stds_Substring( hex_string, i, i + 4 );
    int32_t decimal   = hex_to_decimal_str( substring );

    checksum += decimal;
  }

  int remainder = checksum >> 16;
  printf( "Remainder: %d\n", remainder );
  checksum &= 0xffff;
  printf( "Truncating checksum to 16 bits is %d\n", checksum );
  checksum += remainder;
  checksum = 0xffff - checksum;

  sprintf( buffer, "0x%04x", checksum );
  printf( "The checksum in decimal is %u.\n", checksum );
  printf( "The checksum in hex is %s.\n", buffer );
}
