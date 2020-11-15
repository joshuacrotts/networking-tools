#include "../include/classful_subnet.h"

/**
 * Computes the number of subnetworks that can be used in a given subnet and 
 * subnet mask (classful only!).
 * 
 * @param void.
 * 
 * @return void. 
 */
void compute_classful_subnet() {
  int classfulSubnet;
  int subnetMask;

  // Given class by the problem.
  printf("Enter the classful Class A, B, or C for the *subnet* (in hex WITH 0x prefix e.g. 0xff000000, 0xffff0000, 0xffffff00): ");
  scanf("%x", &classfulSubnet);
  printf("\n");

  // Given mask by the problem.
  printf("Enter the classful Class A, B, or C for the *mask* (in hex WITH 0x prefix e.g. 0xff000000, 0xffff0000, 0xffffff00): ");
  scanf("%x", &subnetMask);
  printf("\n");

  int subnetRes = classfulSubnet ^ subnetMask;
  subnetRes /= -subnetRes & subnetRes;

  printf("Number of subnetworks: %d\n", subnetRes + 1);
}
