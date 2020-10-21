#include "../include/stds.h"
#include "../include/string_util.h"

#define BUFFER_SIZE 256

static char buffer[BUFFER_SIZE];

static long long hex_to_decimal_str( char *str );
static int       hex_to_decimal( char ch );
static bool      is_hex_digit( char digit );
static bool      is_hex_letter( char letter );

int
main( int argc, char *argv[] ) {
  char *       hex_string = fgets( buffer, BUFFER_SIZE, stdin );
  unsigned int str_len    = strlen( hex_string ) - 1;

  if ( str_len % 4 != 0 ) {
    fprintf( stderr,
             "Error, your hex string length must be a multiple of four (pairs of bytes).\n" );
    exit( EXIT_FAILURE );
  }

  unsigned int checksum = 0;

  for ( int i = 0; i < str_len; i += 4 ) {
    char *substring = str_substring( hex_string, i, i + 4 );
    int   decimal   = hex_to_decimal_str( substring );

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

/**
 * Converts a hex string to a long long number.
 */
static long long
hex_to_decimal_str( char *str ) {
  const int FACTOR  = 16;
  long long decimal = 0;
  for ( int i = strlen( str ) - 1, j = 0; i >= 0; i--, j++ ) {
    int decimalChar = hex_to_decimal( str[j] );
    decimal += ( decimalChar * pow( FACTOR, i ) );
  }
  return decimal;
}

/**
 * Converts one hex character to its decimal counterpart.
 */
static int
hex_to_decimal( char ch ) {
  ch = tolower( ch );
  if ( is_hex_digit( ch ) ) {
    return ch - '0';
  } else if ( is_hex_letter( ch ) ) {
    return ch - 'a' + 10;
  }
  printf( "Invalid character: %c.\n", ch );
  exit( EXIT_FAILURE );
}

static bool
is_hex_digit( char digit ) {
  return digit >= '0' && digit <= '9';
}

static bool
is_hex_letter( char letter ) {
  return letter >= 'a' && letter <= 'f';
}
