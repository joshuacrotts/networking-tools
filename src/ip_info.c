#include "../include/ip_info.h"

static int32_t get_number_hosts( uint32_t cidr );
static void     print_wildcard_mask( uint32_t cidr );
static void     print_subnet_mask( uint32_t cidr );
static void     print_network_address( uint32_t address, uint32_t cidr );

/**
 *
 */
void
compute_ip_info( void ) {
  uint32_t ip;
  uint32_t cidr;
  uint32_t subnet;

  /* First, read the data in from the user (the ip and the CIDR mask). */
  printf( "Enter your IP in hex WITH the leading 0x prefix: " );
  scanf( "%x", &ip );
  printf( "Enter your subnet in CIDR notation (ex. /23): " );
  scanf( "%d", &cidr );

  /* Compute the actual subnet address. */
  subnet = ( uint32_t ) pow( 2, cidr );

  /* Now compute the other info. */
  int32_t number_of_hosts        = get_number_hosts( cidr );
  int32_t number_of_usable_hosts = number_of_hosts - 2;
  int32_t start_host             = ( ip & subnet ) + 1;
  int32_t end_host               = start_host + number_of_usable_hosts - 1;

  /* Bunch of nasty prints, but it works. */
  printf( "\n\nIPv4 Address: " );
  print_ip( ip );
  printf( "\nSubnet: " );
  print_subnet_mask( cidr );
  printf( "\nWildcard Mask: " );
  print_wildcard_mask( cidr );
  printf( "\nCIDR Notation: /%d", cidr );
  printf( "\nNetwork Address: " );
  print_network_address(ip, cidr);
  printf("\nNumber of Usable Hosts: %d", number_of_usable_hosts);
  printf("\nFirst Host Address: ");
  print_ip(start_host);
  printf("\nEnding Host Address: ");
  print_ip(end_host);
  printf("\nBroadcast Address: ");
  print_ip(end_host + 1);
  printf( "\n\n" );
}

/**
 *
 */
static int32_t
get_number_hosts( uint32_t cidr ) {
  return (int32_t) (pow(2, MAX_SUBNET - cidr));
}

/**
 *
 */
static void
print_wildcard_mask( uint32_t cidr ) {
  uint32_t ip = 0xffffffff & ( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  print_ip( ip );
}

/**
 *
 */
static void
print_subnet_mask( uint32_t cidr ) {
  uint32_t ip = 0xffffffff & ~( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  print_ip( ip );
}

/**
 *
 */
static void
print_network_address( uint32_t address, uint32_t cidr ) {
  uint32_t ip = address & ~( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  print_ip(ip);
}