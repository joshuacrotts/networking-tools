#include "../include/network_utils.h"

/**
 * Determines whether a char array (string) is a valid hex string.
 * A valid hex string consists of [0-9] [A-Fa-f] characters.
 *
 * @param char str[]
 *
 * @return true if the string is a valid hex string, false otherwise.
 */
bool
is_valid_hex_str( char str[], size_t len ) {
  size_t arr_size = len;
  for ( int i = 0; i < arr_size - 1; i++ ) {
    if ( !is_valid_hex_char( str[i] ) ) {
      return false;
    }
  }

  if ( str[arr_size - 1] == '\n' ) {
    str[arr_size - 1] = '\0';
    return true;
  } else {
    return false;
  }
}

/**
 * Determines if an array
 *
 * @param char buffer[]
 * @param size_t arr_size
 *
 * @return
 */
bool
is_valid_binary_str( char buffer[], size_t len ) {
  size_t arr_size = len;
  for ( size_t i = 0; i < arr_size; i++ ) {
    char ch = buffer[i];
    if ( ch != '0' && ch != '1' ) {
      return false;
    }
  }

  return true;
}

/**
 *
 *
 * @param
 *
 * @return
 */
long long
hex_to_decimal_str( char *str ) {
  const int FACTOR  = 16;
  long long decimal = 0;
  for ( size_t i = strlen( str ) - 1, j = 0; i >= 0; i--, j++ ) {
    if ( str[j] == '\0' )
      break;
    int32_t decimalChar = hex_to_decimal( str[j] );
    decimal += ( decimalChar * ( int32_t ) pow( FACTOR, i ) );
  }
  return decimal;
}

/**
 *
 *
 * @param
 *
 * @return
 */
int32_t
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

/**
 *
 *
 * @param
 *
 * @return
 */
bool
is_valid_hex_char( char c ) {
  return is_hex_digit( c ) || is_hex_letter( c );
}

/**
 *
 *
 * @param
 *
 * @return
 */
bool
is_hex_digit( char digit ) {
  return digit >= '0' && digit <= '9';
}

/**
 * Returns whether or not the char is a hex LETTER (A - F or a-f).
 *
 * @param char letter.
 *
 * @return true if letter is 
 */
bool
is_hex_letter( char letter ) {
  return letter >= 'a' && letter <= 'f' || letter >= 'A' && letter <= 'F';
}

uint32_t
get_network_address( uint32_t address, uint32_t cidr ) {
  uint32_t ip = address & ~( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  return ip;
}

/**
 * Counts the number of set bits in a 32-bit integer.
 *
 * @param n integer.
 *
 * @return number of 1's in binary representation of n.
 */
uint32_t
count_set_bits( uint32_t n ) {
  if ( n == 0 ) {
    return 0;
  } else if ( n & 1 ) {
    return 1 + count_set_bits( n >> 1 );
  } else {
    return count_set_bits( n >> 1 );
  }
}

/**
 * Counts the number of set bits in a string of binary numbers.
 *
 * @param char array of 1's and 0's.
 * @param size of char array.
 *
 * @return number of 1's.
 */
uint32_t
count_set_bits_str( char buffer[], size_t arr_size ) {
  uint32_t signed_bits = 0;

  for ( size_t i = 0; i < arr_size; i++ ) {
    char ch = buffer[i];
    if ( ch == '1' ) {
      signed_bits++;
    }
  }

  return signed_bits;
}

/**
 * Prints a 6-byte mac address.
 *
 * @param mac address in numeric form.
 *
 * @return void.
 */
void
print_mac( uint64_t mac ) {
  for ( int i = 5; i >= 0; i-- ) {
    printf( "%I64x", mac >> ( i * BYTE ) & 0xff );
    if ( i != 0 )
      printf( ":" );
  }
  printf( "\n" );
}

/**
 * Prints an IPv4 address out byte by byte.
 *
 * @param ip address in numeric form.
 *
 * @return void.
 */
void
print_ip( uint32_t ip ) {
  uint8_t byteOne   = ip >> 24 & 0xff;
  uint8_t byteTwo   = ip >> 16 & 0xff;
  uint8_t byteThree = ip >> 8 & 0xff;
  uint8_t byteFour  = ip & 0xff;

  printf( "%d.%d.%d.%d", byteOne, byteTwo, byteThree, byteFour );
}

/**
 *
 */
void
print_byte_ip( uint32_t byte_one, uint32_t byte_two, uint32_t byte_three, uint32_t byte_four ) {
  printf( "%d.%d.%d.%d", byte_one, byte_two, byte_three, byte_four );
}

/**
 *
 * Prints an IP address in the standard (xxx.xxx.xxx.xxx) format, along with
 * its CIDR subnet notation.
 *
 * @param ip
 * @param subnet
 *
 * @return void.
 */
void
print_ip_subnet( uint32_t ip, uint32_t subnet ) {
  print_ip( ip );
  printf( " /%d", subnet );
}

/**
 *
 *
 * @param ip_str[]
 * @param array_size
 */
uint32_t
ip_to_hex( char ip_str[], size_t array_size ) {
  char *bytes = strtok( ip_str, "." );

  uint32_t byte_count = 0;
  int32_t  ip         = 0;

  while ( bytes != NULL ) {
    ip |= ( atoi( bytes ) << ( MAX_SUBNET - byte_count - BYTE ) );
    bytes = strtok( NULL, "." );
    byte_count += 8;
  }

  return ip;
}