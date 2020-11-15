#include "../include/block_calculator.h"

/**
 * Runs the IP block calculator. The user should give a starting IP address in hex.
 * Then, give the number of blocks to compute. After this, they will enter the number of
 * addresses dedicated to each block in order of decreasing size.
 * 
 * @param void.
 * 
 * @return void.
 */
void
compute_block_calculator( void ) {
  uint32_t ip;
  uint32_t subnet;
  uint32_t blockCount;

  // Enter the starting address.
  printf( "Enter your beginning address in hex WITH the leading 0x prefix (e.g. 0xFFABCD45): " );
  scanf("%x", &ip);

  // Enter the beginning subnet.
  printf( "\nEnter your beginning subnet in decimal (e.g. 24, 25, ...): " );
  scanf( "%d", &subnet );
  printf( "\nEnter the number of blocks to use in decimal: " );
  scanf( "%d", &blockCount );
  printf( "\n\n" );
  printf( "When entering the subblock addresses in decimal, enter them in reverse order starting "
          "with the largest block.\n\n" );

  uint32_t totalAddresses = (uint32_t) pow( 2, MAX_SUBNET - subnet );
  printf( "Total addresses: %d.\n", totalAddresses );

  uint32_t *subblocks = malloc( sizeof( uint32_t ) * blockCount );

  for ( int i = 0; i < blockCount; i++ ) {
    printf( "Enter the subblock %d address count: ", ( i + 1 ) );
    scanf( "%d", &subblocks[i] );
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
