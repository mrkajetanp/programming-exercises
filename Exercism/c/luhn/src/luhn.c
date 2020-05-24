#include "luhn.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool luhn(const char* input) {
  int length = 0;
  char* data = malloc(strlen(input));

  for (size_t i = 0 ; input[i] != '\0' ; ++i) {
    // Return false if input contains invalid characters
    if (!(isdigit(input[i]) || isspace(input[i]))) {
      free(data);
      return false;
    }

    // Filter out spaces
    if (!isspace(input[i]))
      data[length++] = input[i];
  }
  data[length] = '\0';

  // Return if the result is too short
  if (length <= 1) {
      free(data);
      return false;
  }

  int sum = 0;
  // Loop backwards over the digits
  for (int i = length-1 ; i >= 0 ; --i) {
    int x = data[i]-'0';

    // Because we're starting at length-1 every other digit will be on an even index
    if ((length-i)%2 == 0) {
      x *= 2;

      if (x > 9)
        x -= 9;
    }

    sum += x;
  }

  free(data);
  return sum % 10 == 0;
}
