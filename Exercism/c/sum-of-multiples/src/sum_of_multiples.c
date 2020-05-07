#include "sum_of_multiples.h"
#include <stdbool.h>

bool arr_contains(int *arr, int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      return true;
    }
  }

  return false;
}

long sum_of_multiples(const unsigned int *multiples, int size, int num) {
  int vec[1000];
  int vec_size = 0;

  for (int i = 0; i < size; ++i) {
    for (int j = 1; j < num; ++j) {
      if (j % multiples[i] == 0 && !arr_contains(vec, vec_size, j))
        vec[vec_size++] = j;
    }
  }

  long sum = 0;
  for (int i = 0; i < vec_size; ++i)
    sum += vec[i];

  return sum;
}
