#include "../include/main.h"

#define MAX_CHOICES 10

static void clear_screen( void );
static void display_menu( void );
static void handle_input( uint32_t val );

int
main( int argc, char *argv[] ) {
  Stds_SetRandomSeed();
  printf( "Welcome to a small tool for CSC-677." );
  int choice = -1;
  while ( true ) {
    display_menu();
    printf( "\nChoose an option: " );
    scanf( "%d", &choice );
    while ( choice <= 0 || choice > MAX_CHOICES ) {
      printf( "\nThis is an invalid menu option. Try again: " );
      scanf( "%d", &choice );
    }

    // If the option is 9, we quit.
    if (choice == MAX_CHOICES) {
      return 0;
    }

    clear_screen();
    handle_input( choice );
    do {
      printf( "\nContinue? 1 for yes, 0 for no: " );
      scanf( "%d", &choice );
    } while ( choice != 0 && choice != 1 );

    if ( choice == 0 ) {
      exit( EXIT_SUCCESS );
    } else {
      clear_screen();
    }
  }
}

/**
 *
 */
void
strip_input( void ) {
  int c;
  do {
    c = getchar();
  } while ( c != EOF && c != '\n' );
}

/**
 *
 */
static void
display_menu( void ) {
  printf( "\n1. Binary Division Calculator (Long Division Bits)" );
  printf( "\n2. Subnet Block Calculator" );
  printf( "\n3. Classful Subnet Generator" );
  printf( "\n4. Checksum Calculator (For Hex Strings)" );
  printf( "\n5. Random Value Generation" );
  printf( "\n6. Hamming Distance" );
  printf( "\n7. Parity Bit Checker" );
  printf( "\n8. IP Subnet Calculator" );
  printf( "\n9. Generate IP Information");
  printf( "\n%d. EXIT", MAX_CHOICES );
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
    compute_classful_subnet();
    break;
  case 4:
    compute_checksum();
    break;
  case 5:
    compute_data();
    break;
  case 6:
    compute_hamming_distance();
    break;
  case 7:
    compute_parity_check();
    break;
  case 8:
    compute_subnet_calculator();
    break;
  case 9:
    compute_ip_info();
    break;
  }
}

/**
 *
 */
static void
clear_screen( void ) {
  #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    system("cls");
  #elif __APPLE__ || __linux__ || __unix__
    system("clear");
  #endif
}