#include "series.h"
#include <stdlib.h>
#include <string.h>

SeriesResults_t series(char *inputText, unsigned int substringLength) {
  SeriesResults_t *result = malloc(sizeof result);
  result->substringCount = 0;

  unsigned int input_len = strlen(inputText);
  if (substringLength > input_len || substringLength == 0)
    return *result;

  result->substring = malloc(sizeof(char *) * input_len - substringLength + 1);

  int idx = 0;

  while (idx + substringLength <= input_len) {
    result->substring[result->substringCount] = malloc(substringLength + 1);
    strncpy(result->substring[result->substringCount++], inputText + idx,
            substringLength);

    idx++;
  }

  return *result;
}
