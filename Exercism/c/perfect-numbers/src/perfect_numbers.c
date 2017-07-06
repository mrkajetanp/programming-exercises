#include "perfect_numbers.h"

int aliquot_sum(int num) {
    int result = 0;

    for (int i = 1 ; i < num; ++i) {
        if (num%i == 0)
            result += i;
    }

    return result;
}

kind classify_number(int num) {
    if (num <= 0)
        return -1;

    int aliquot = aliquot_sum(num);

    if (aliquot == num)
        return perfect_number;
    else if (aliquot > num)
        return abundant_number;
    else
        return deficient_number;
}
