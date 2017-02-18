#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ifContainsFive(int num) {
  if (num == 5)  return true;
  while (num > 0) {
    if (num%10 == 5)  return true;
    num /= 10;
  }
  return false;
}

int dontGiveMeFive(int start, int end) {
  int counter = 0;
  for (int i = start; i <= end; i++)
    if (!ifContainsFive(abs(i))) counter++;
  return counter;
}


int main() {
  printf("%d\n", dontGiveMeFive(4,17));
  return 0;
}
