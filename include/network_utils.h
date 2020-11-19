#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include "stds.h"

extern bool is_valid_hex_str( char str[], size_t arr_size );

extern bool is_valid_binary_str( char str[], size_t arr_size );

extern long long hex_to_decimal_str( char *str );

extern int32_t hex_to_decimal( char ch );

extern bool is_valid_hex_char( char c );

extern bool is_hex_digit( char digit );

extern bool is_hex_letter( char letter );

extern uint32_t get_network_address(uint32_t ip, uint32_t cidr);

extern uint32_t count_set_bits( uint32_t n );

extern uint32_t count_set_bits_str( char str[], size_t arr_size );

extern uint32_t ip_to_hex(char str[], size_t arr_size);

extern void print_mac( uint64_t mac );

extern void print_ip( uint32_t ip );

extern void print_byte_ip(uint32_t byte_one, uint32_t byte_two, uint32_t byte_three, uint32_t byte_four);

extern void print_ip_subnet( uint32_t ip, uint32_t subnet );

#endif // NETWORK_UTILS_H