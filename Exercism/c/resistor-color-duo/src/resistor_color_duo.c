#include "resistor_color_duo.h"
#include <stdlib.h>
#include <stdio.h>

uint16_t color_code(resistor_band_t* resistor) {
  char buffer[4];
  sprintf(buffer, "%d%d", resistor[0], resistor[1]);
  return atoi(buffer);
}
