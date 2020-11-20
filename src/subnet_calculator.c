#include "../include/subnet_calculator.h"

/**
 *
 *
 * @param
 *
 * @return
 */
void
compute_subnet_calculator() {
  int prefix_length;
  printf( "Enter the subnet to use and I will calculate the mask (e.g. 24, 25, ...): " );
  scanf( "%d", &prefix_length );
  printf( "\n" );

  unsigned int ip = 0xffffffff & ~( ( int ) pow( 2, MAX_SUBNET - prefix_length ) - 1 );

  int byteOne   = ip >> 24 & 0xff;
  int byteTwo   = ip >> 16 & 0xff;
  int byteThree = ip >> 8 & 0xff;
  int byteFour  = ip & 0xff;

  printf( "The subnet mask is %d.%d.%d.%d\n", byteOne, byteTwo, byteThree, byteFour );
}