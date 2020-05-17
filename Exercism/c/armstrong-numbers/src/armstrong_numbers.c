#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>


int is_armstrong_number(int candidate) {
  int len = 0;
  for (int n = candidate ; n != 0 ; n /= 10)
    len++;

  int sum = 0;
  for (int n = candidate ; n != 0 ; n /= 10)
    sum += pow(n%10, len);

  return sum == candidate;
}
