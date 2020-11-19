#include "../include/binary_division.h"

/**
 * Prints out a binary polynomial string representation of an unsigned integer.
 * For instance, 110011 will print x^5 + x^4 + x^1 + 1.
 * 
 * @param uint32_t integer to convert and print in a binary string.
 * 
 * @return void.
 */
void
print_binary_polynomial( uint32_t n ) {
  // 4 should be a big enough buffer...
  uint32_t binary_size =(uint32_t) floor( log2( n ) + 1 );
  uint32_t poly_size   = binary_size * 4;

  for ( size_t i = 0; i < binary_size - 1; i++ ) {
    uint32_t next_digit = ( n >> ( binary_size - i - 1 ) ) & 1;
    if ( next_digit == 1 ) {
      printf( "x^%lu + ", binary_size - i - 1 );
    }
  }

  uint32_t last_digit = ( n >> ( binary_size - 1 ) ) & 1;
  if ( last_digit == 1 ) {
    printf( "1" );
  }
}

/**
 * Prints out a binary string representation of an unsigned integer.
 * For instance, 11001111.
 * 
 * This method does NOT handle leading zeroes. So, if you're trying to
 * print out the binary version of 17, and expect to get 00010001, this
 * is not the function for you.
 * 
 * @param uint32_t integer to convert and print in a binary string.
 * 
 * @return void.
 */
void
print_binary( uint32_t n ) {
  uint32_t  digits = (uint32_t) floor( log2( n ) + 1 );
  uint32_t *binary = malloc( sizeof( uint32_t ) * digits );
  int32_t   i      = 0;

  while ( n > 0 ) {
    binary[i] = n & 1;
    n >>= 1;
    i++;
  }

  for ( int j = digits - 1; j >= 0; j-- ) {
    printf( "%d", binary[j] );
  }

  free( binary );
}

/**
 * Runs the binary division algorithm.
 * 
 * @param void.
 * 
 * @return void.
 */
void compute_binary_division( void ) {
  uint32_t divisor;
  uint32_t dividend;
  uint32_t quotient;
  uint32_t remainder;

  printf( "Enter the dividend in decimal: " );
  scanf( "%ud", &dividend );
  printf( "\nEnter the divisor in decimal: " );
  scanf( "%ud", &divisor );

  uint32_t dividend_size = (uint32_t) floor( log2( dividend ) + 1 );
  uint32_t divisor_size  = (uint32_t) floor( log2( divisor ) + 1 );
  uint32_t running_dividend = dividend >> ( dividend_size - divisor_size );

  quotient = 1;

  for ( size_t si = divisor_size - 1; si < dividend_size; ) {
    uint32_t curr_result      = running_dividend ^ divisor;
    uint32_t curr_result_size = (uint32_t) floor( log2( curr_result ) + 1 );

    while ( curr_result_size != divisor_size ) {
      si++;
      if ( si >= dividend_size ) {
        running_dividend = curr_result;
        break;
      }

      uint32_t next_digit = ( dividend >> ( dividend_size - si - 1 ) ) & 1;
      curr_result <<= 1;
      quotient <<= 1;
      curr_result |= next_digit;
      curr_result_size++;

      quotient |= ( curr_result_size != divisor_size ) ? 0 : 1;
    }

    running_dividend = curr_result;
  }

  printf( "Quotient: " );
  print_binary( quotient );
  printf( " => " );
  print_binary_polynomial( quotient );
  printf( "\n" );

  if ( running_dividend != 0 ) {
    printf( "Remainder: " );
    print_binary( running_dividend );
    printf( " => " );
    print_binary_polynomial( running_dividend );
    printf( "\n" );
  } else {
    printf( "Remainder: %d\n", 0 );
  }
}