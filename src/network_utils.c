#include "../include/network_utils.h"

/**
 * 
 * 
 * @param char str[]
 * 
 * @return true if the string is a valid hex string, false otherwise.
 */
bool
is_valid_hex_str( char str[] ) {
  size_t arr_size = strlen(str);
  for ( int i = 0; i < arr_size - 1; i++ ) {
    if (!is_valid_hex_char(str[i])) {
      return false;
    }
  }

  if (str[arr_size - 1] == '\n') {
    str[arr_size - 1] = '\0';
    return true;
  } else {
    return false;
  }
}

/**
 * 
 * 
 * @param char buffer[]
 * @param size_t arr_size
 * 
 * @return
 */
bool
is_valid_binary_str( char buffer[], size_t arr_size ) {
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
    if (str[j] == '\0') break;
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
 * 
 *
 * @param
 * 
 * @return
 */
bool
is_hex_letter( char letter ) {
  return letter >= 'a' && letter <= 'f';
}

/**
 * 
 *
 * @param
 * 
 * @return
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
 * 
 *
 * @param
 * 
 * @return
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
 * 
 *
 * @param
 * 
 * @return
 */
void print_mac(uint64_t mac) {
  for (int i = 5; i >= 0; i--) {
    printf("%x", mac >> (i * 8) & 0xff);
    if (i != 0)
      printf(":");
  }
  printf("\n");
}

/**
 * 
 *
 * @param
 * 
 * @return
 */
void
print_ip( uint32_t ip ) {
  uint8_t byteOne   = ip >> 24 & 0xff;
  uint8_t byteTwo   = ip >> 16 & 0xff;
  uint8_t byteThree = ip >> 8 & 0xff;
  uint8_t byteFour  = ip & 0xff;

  printf( "%d.%d.%d.%d\n", byteOne, byteTwo, byteThree, byteFour );
}

/**
 * 
 *
 * @param
 * 
 * @return
 */
void
print_ip_subnet( uint32_t ip, uint32_t subnet ) {
  print_ip( ip );
  printf( "/%d", subnet );
}