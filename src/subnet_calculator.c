#include "../include/stds.h"

static const int MAX_SUBNET = 32;

int
main( int argc, char *argv[] ) {
  int prefix_length;
  printf( "Enter the subnet to use and I will calculate the mask: " );
  scanf( "%x", &prefix_length );
  printf( "\n\n" );

  unsigned int ip = 0xffffffff & ~( ( int ) pow( 2, MAX_SUBNET - prefix_length ) - 1 );

  int byteOne   = ip >> 24 & 0xff;
  int byteTwo   = ip >> 16 & 0xff;
  int byteThree = ip >> 8 & 0xff;
  int byteFour  = ip & 0xff;

  printf( "The subnet mask is %d.%d.%d.%d\n", byteOne, byteTwo, byteThree, byteFour );
}
