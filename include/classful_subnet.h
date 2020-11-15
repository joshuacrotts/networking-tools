#ifndef CLASSFUL_SUBNET_H
#define CLASSFUL_SUBNET_H

#include "stds.h"
#include "network_utils.h"

/**
 * Computes the number of subnetworks that can be used in a given subnet and 
 * subnet mask (classful only!).
 * 
 * @param void.
 * 
 * @return void. 
 */
extern void compute_classful_subnet( void );

#endif // CLASSFUL_SUBNET_H