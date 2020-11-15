#ifndef DATA_GENERATION_H
#define DATA_GENERATION_H

#include <float.h>

#include "network_utils.h"
#include "stds.h"

extern uint32_t get_random_ip( void );

extern uint64_t get_random_mac( void );

extern void compute_data( void );

#endif // DATA_GENERATION_H