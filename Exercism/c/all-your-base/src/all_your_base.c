#include "all_your_base.h"
#include <math.h>

void swap(int8_t*, int8_t*);
void swap(int8_t* a, int8_t* b) {
    *a = *a ^ *b; // a holds a+b
    *b = *a ^ *b; // b holds a
    *a = *a ^ *b; // a holds b
}

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t len) {
    // If digits start with 0 or input bases are incorrect, return 0
    if (digits[0] == 0 || input_base < 2 || output_base < 2) {
        digits[0] = 0;
        return 0;
    }

    size_t decimal_number = 0;

    // Convert to decimal
    int idx = 0;
    for (int i = len ; i > 0 ; --i) {
        // If any digit is invalid, return 0
        if (digits[i-1] >= input_base) {
            digits[0] = 0;
            return 0;
        }

        decimal_number += digits[i-1] * pow(input_base, (idx++));
    }

    int output_length = 0;

    // Put new digits into digits array
    while (decimal_number != 0) {
        digits[output_length++] = decimal_number%output_base;
        decimal_number /= output_base;
    }

    // Reverse digits array
    for (int i = 0 ; i < output_length/2 ; ++i)
        swap(&digits[i], &digits[output_length-i-1]);

    return output_length;
}
