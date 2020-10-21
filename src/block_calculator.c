#include "../include/stds.h"

void print_ip( int ip );
void print_ip_subnet( int ip, int subnet );

static const int MAX_SUBNET = 32;

int
main( int argc, char *argv[] ) {
  unsigned int ip;
  int          subnet;
  int          blockCount;

  printf( "Enter your beginning address in hex (e.g. 0xffabcd45): " );
  scanf( "%x", &ip );
  printf( "\nEnter your beginning subnet in decimal: " );
  scanf( "%d", &subnet );
  printf( "\nEnter the number of blocks to use in decimal: " );
  scanf( "%d", &blockCount );
  printf( "\n\n" );
  printf( "When entering the subblock addresses in decimal, enter them in reverse order starting "
          "with the largest block.\n\n" );

  int totalAddresses = pow( 2, MAX_SUBNET - subnet );
  printf( "Total addresses: %d.\n", totalAddresses );
  int subblocks[blockCount];

  for ( int i = 0; i < blockCount; i++ ) {
    printf( "Enter the subblock %d address count: ", ( i + 1 ) );
    scanf( "%d", &subblocks[i] );
    printf( "\n" );
  }

  int minAddress = ip;
  int maxAddress = ip + totalAddresses - 1;

  printf( "Minimum address: " );
  print_ip( minAddress );
  printf( "\n" );

  printf( "Maximum address: " );
  print_ip( maxAddress );
  printf( "\n" );

  maxAddress = ip;

  for ( int i = 0; i < blockCount; i++ ) {
    int blockAddress = subblocks[i];

    // Returns the upper-bound of addresses for a # of addresses.
    int blockAddressSize = ( int ) pow( 2, ( ceil( log2( blockAddress ) ) ) );
    int mask             = ( int ) ( MAX_SUBNET - log2( blockAddressSize ) );
    maxAddress += ( blockAddressSize - 1 );

    printf( "The starting address for block %d is ", ( i + 1 ) );
    print_ip_subnet( minAddress, mask );
    printf( "\n" );
    printf( "The ending address for block %d is ", ( i + 1 ) );
    print_ip_subnet( maxAddress, mask );
    printf( "\n" );
    maxAddress++;
    minAddress = maxAddress;
  }

  return 0;
}

/**
 * 
 */
void
print_ip( int ip ) {
  int byteOne   = ip >> 24 & 0xff;
  int byteTwo   = ip >> 16 & 0xff;
  int byteThree = ip >> 8 & 0xff;
  int byteFour  = ip & 0xff;

  printf( "%d.%d.%d.%d", byteOne, byteTwo, byteThree, byteFour );
}

/**
 * 
 */
void
print_ip_subnet( int ip, int subnet ) {
  print_ip( ip );
  printf( "/%d", subnet );
}
