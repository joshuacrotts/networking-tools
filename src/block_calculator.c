#include "../include/block_calculator.h"

void
compute_block_calculator() {
  uint32_t ip;
  uint32_t subnet;
  uint32_t blockCount;

  printf( "Enter your beginning address in hex (e.g. 0xffabcd45): " );
  scanf( "%x", &ip );
  printf( "\nEnter your beginning subnet in decimal: " );
  scanf( "%d", &subnet );
  printf( "\nEnter the number of blocks to use in decimal: " );
  scanf( "%d", &blockCount );
  printf( "\n\n" );
  printf( "When entering the subblock addresses in decimal, enter them in reverse order starting "
          "with the largest block.\n\n" );

  uint32_t totalAddresses = pow( 2, MAX_SUBNET - subnet );
  printf( "Total addresses: %d.\n", totalAddresses );

  uint32_t *subblocks = malloc( sizeof( uint32_t ) * blockCount );

  for ( int i = 0; i < blockCount; i++ ) {
    printf( "Enter the subblock %d address count: ", ( i + 1 ) );
    scanf( "%d", &subblocks[i] );
    printf( "\n" );
  }

  uint32_t minAddress = ip;
  uint32_t maxAddress = ip + totalAddresses - 1;

  printf( "Minimum address: " );
  print_ip( minAddress );
  printf( "\n" );

  printf( "Maximum address: " );
  print_ip( maxAddress );
  printf( "\n" );

  maxAddress = ip;

  for ( int i = 0; i < blockCount; i++ ) {
    uint32_t blockAddress = subblocks[i];

    // Returns the upper-bound of addresses for a # of addresses.
    uint32_t blockAddressSize = ( uint32_t ) pow( 2, ( ceil( log2( blockAddress ) ) ) );
    uint32_t mask             = ( uint32_t )( MAX_SUBNET - log2( blockAddressSize ) );
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

  free( subblocks );
}

/**
 *
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
print_ip_subnet( uint32_t ip, uint32_t subnet ) {
  print_ip( ip );
  printf( "/%d", subnet );
}
