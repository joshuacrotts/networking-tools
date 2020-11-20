#include "../include/hamming_distance.h"

/**
 * Runs the Hamming distance algorithm on two hex
 * strings.
 *
 * @param void.
 *
 * @return void.
 */
void
compute_hamming_distance( void ) {
  uint32_t word_one;
  uint32_t word_two;

  printf( "Enter the first word in hex (0xacbff414): " );
  scanf( "%X", &word_one );

  printf( "\nEnter the second word in hex (0xacbff414): " );
  scanf( "%X", &word_two );

  uint32_t hamming_distance = count_set_bits( word_one ^ word_two );

  printf( "\nThe hamming distance between the two words is %d.\n", hamming_distance );
}
