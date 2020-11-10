#include "../include/main.h"

static void display_menu();
static void handle_input( uint32_t val );
static void strip_input();

int
main( int argc, char *argv[] ) {
  printf( "Welcome to a small tool for CSC-677." );
  int choice = -1;
  while ( true ) {
    display_menu();
    printf( "\nChoose an option: " );
    scanf( "%d", &choice );
    while ( choice <= 0 || choice > 8 ) {
      printf( "\nThis is an invalid menu option. Try again: " );
      scanf( "%d", &choice );
    }

    handle_input( choice );
    do {
      printf( "\nContinue? 1 for yes, 0 for no: " );
      scanf( "%d", &choice );
    } while ( choice != 0 && choice != 1 );

    if (exit == 0) {
      exit(EXIT_SUCCESS);
    }
  }
}

/**
 *
 */
static void
display_menu() {
  printf( "\n1. Binary Division Calculator (Long Division Bits)" );
  printf( "\n2. Subnet Block Calculator" );
  printf( "\n3. Classful Subnet Generator" );
  printf( "\n4. Checksum Calculator (For Hex Strings)" );
  printf( "\n5. (NOT WORKING YET) Random Value Generation" );
  printf( "\n6. Hamming Distance" );
  printf( "\n7. Parity Bit Checker" );
  printf( "\n8. IP Subnet Calculator" );
}

/**
 *
 */
static void
handle_input( uint32_t input ) {
  strip_input();
  switch ( input ) {
  case 1:
    compute_binary_division();
    break;
  case 2:
    compute_block_calculator();
    break;
  case 3:
    compute_checksum();
    break;
  case 4:
    compute_checksum();
    break;
  case 5:
    break;
  case 6:
    compute_hamming_distance();
    break;
  case 7:
    compute_parity_check();
    break;
  case 8:
    compute_subnet_calculator();
  }
}

/**
 *
 */
static void
strip_input() {
  int c;
  do {
    c = getchar();
  } while ( c != EOF && c != '\n' );
}