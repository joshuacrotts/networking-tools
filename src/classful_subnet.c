#include "../include/stds.h"

static const int MAX_SUBNET = 32;

int main(int argc, char *argv[]) {
  int classfulSubnet;
  int subnetMask;

  // Given class by the problem.
  printf("Enter the classful Class A, B, or C: ");
  scanf("%x", &classfulSubnet);
  printf("\n");

  // Given mask by the problem.
  printf("Enter the classful Class A, B, or C: ");
  scanf("%x", &subnetMask);
  printf("\n");

  int subnetRes = classfulSubnet ^ subnetMask;

  subnetRes /= -subnetRes & subnetRes;

  printf("Number of subnetworks: %d\n", subnetRes + 1);

  return 0;
}