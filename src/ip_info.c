#include "../include/ip_info.h"

static int32_t get_number_hosts( uint32_t cidr );
static void    print_wildcard_mask( uint32_t cidr );
static void    print_subnet_mask( uint32_t cidr );
static void    print_subnet_mask_dot_notation( uint32_t cidr );
static void    print_ip_class(uint32_t ip);

/**
 *
 * 
 * @param void.
 * 
 * @return void.
 */
void
compute_ip_info( void ) {
  uint32_t ip = 0;
  uint32_t cidr = 0;

  /* First, read the data in from the user (the ip and the CIDR mask). */
  printf( "Enter your IP in hex WITH the leading 0x prefix: " );
  scanf( "%x", &ip );
  printf( "Enter your subnet in CIDR notation (ex. /23): " );
  scanf( "%d", &cidr );

  /* Now compute the other info. */
  int32_t number_of_hosts        = get_number_hosts( cidr );
  int32_t number_of_usable_hosts = number_of_hosts - 2;
  int32_t network_address        = get_network_address( ip, cidr );
  int32_t start_host             = network_address + 1;
  int32_t end_host               = start_host + number_of_usable_hosts - 1;

  /* Bunch of nasty prints, but it works. */

  /* Prints the IP address. */
  printf( "\n\nIPv4 Address: " );
  print_ip( ip );

  /* Prints the subnet mask in IP form (xxx.xxx.xxx.xxx). */
  printf( "\nSubnet: " );
  print_subnet_mask( cidr );

  /* Prints the subnet mask in its binary form. */
  printf( "\nBinary Netmask: " );
  print_subnet_mask_dot_notation( cidr );

  /* Prints the wildcard mask. */
  printf( "\nWildcard Mask: " );
  print_wildcard_mask( cidr );

  /* Prints the CIDR notation. */
  printf( "\nCIDR Notation: /%d", cidr );

  /* Prints the network address. */
  printf( "\nNetwork Address: " );
  print_ip( network_address );

    /* Prints the total number of hosts. */
  printf( "\nNumber of Usable Hosts: %d", number_of_hosts );

  /* Prints the number of usable hosts. */
  printf( "\nNumber of Usable Hosts: %d", number_of_usable_hosts );

  /* Prints the first host address. */
  printf( "\nFirst Host Address: " );
  print_ip( start_host );

  /* Prints the last host address. */
  printf( "\nEnding Host Address: " );
  print_ip( end_host );

  /* Prints the broadcast address. */
  printf( "\nBroadcast Address: " );
  print_ip( end_host + 1 );

  /* Prints the IP classful... classification. (A, B, C, D). */
  printf("\nIP Classification (Classful): ");
  print_ip_class(ip);

  printf("\n");
}

/**
 *
 * 
 * @param cidr
 *
 * @return void.
 */
static int32_t
get_number_hosts( uint32_t cidr ) {
  return ( int32_t )( pow( 2, MAX_SUBNET - cidr ) );
}

/**
 *
 * 
 * @param cidr
 * 
 * @return void.
 */
static void
print_wildcard_mask( uint32_t cidr ) {
  uint32_t ip = 0xffffffff & ( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  print_ip( ip );
}

/**
 *
 * 
 * @param cidr
 * 
 * @return void.
 */
static void
print_subnet_mask( uint32_t cidr ) {
  uint32_t ip = 0xffffffff & ~( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  print_ip( ip );
}

/**
 *
 * 
 * @param cidr
 * 
 * @return void.
 */
static void
print_subnet_mask_dot_notation( uint32_t cidr ) {
  uint32_t ip = 0xffffffff & ~( ( int ) pow( 2, MAX_SUBNET - cidr ) - 1 );
  
  /* Iterate bit by bit, and print the bitwise AND by 1 result. */
  for (int i = 1; i <= 32; i++) {
    /* Traverse the number backwards with bitshifts since the binary representation 
       starts from the left. */
    uint32_t bit = ip >> (MAX_SUBNET - i);
    printf(bit & 1 ? "1" : "0");

    // Every 8 bits (byte) we print a .
    if (i % 8 == 0){
      printf(".");
    }
  }
}

/**
 * 
 */
static void print_ip_class(uint32_t ip) {
  uint32_t byte_one = ip >> 24 & 0xff;

  /* Class A is 0.0.0.0 - 127.255.255.255. */
  if (byte_one <= 127) {
    printf("A (0.0.0.0 - 127.255.255.255)");
  } 
  /* Class B is 128.0.0.0 - 191.255.255.255. */
  else if (byte_one <= 191) {
    printf("B (128.0.0.0 - 191.255.255.255)");
  }
  /* Class C is 192.0.0.0 - 223.255.255.255. */
  else if (byte_one <= 223) {
    printf("C (192.0.0.0 - 223.255.255.255)");
  } 
  /* Class D is everything else. */
  else {
    printf("D (224.0.0.0 - 255.255.255.255)");
  }
}