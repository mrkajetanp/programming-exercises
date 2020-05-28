#include "resistor_color_trio.h"
#include <stdlib.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t* resistor) {
  resistor_value_t result;

  int idx = 0;
  char buffer[4];
  // Append first half of the value
  buffer[idx++] = '0' + resistor[0];

  // Calculate how many zeroes the value will end with and finish appending value
  int zeroes = resistor[2];
  if (resistor[1] == BLACK)
    zeroes++;
  else
    buffer[idx++] = '0' + resistor[1];

  // Set the unit appropriately
  if (zeroes >= 3) {
    result.unit = KILOOHMS;
    zeroes -= 3;
  } else {
    result.unit = OHMS;
  }

  // Append the remaining zeroes
  for (int i = 0 ; i < zeroes ; ++i)
    buffer[idx++] = '0';

  // Close up the string, convert & return
  buffer[idx] = '\0';
  result.value = atoi(buffer);
  return result;
}
