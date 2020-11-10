#include "../include/hamming_distance.h"

static uint32_t count_set_bits( uint32_t n );

void
compute_hamming_distance() {
  uint32_t word_one;
  uint32_t word_two;

  printf( "Enter the first word in hex: " );
  scanf( "%X", &word_one );

  printf( "\nEnter the second word in hex: " );
  scanf( "%X", &word_two );

  uint32_t hamming_distance = count_set_bits( word_one ^ word_two );

  printf( "\nThe hamming distance between the two words is %d.\n", hamming_distance );
}

/**
 *
 */
static uint32_t
count_set_bits( unsigned int n ) {
  if ( n == 0 ) {
    return 0;
  } else if ( n & 1 ) {
    return 1 + count_set_bits( n >> 1 );
  } else {
    return count_set_bits( n >> 1 );
  }
}