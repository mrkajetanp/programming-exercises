#include <stdio.h>
#include <math.h>

long long newAvg(double *arr, long szArray, double navg) {
    if (arr[szArray-1] <= 0)
        return -1;

    double sum = 0;

    for (long i = 0 ; i < szArray ; ++i)
        sum += arr[i];

    double result = ceil(navg * (double)(szArray+1) - sum);

    return (result < 0) ? -1 : result;
}

int main() {
    double arr1[7] = {14.0, 30.0, 5.0, 7.0, 9.0, 11.0, 16.0};
    printf("%lld\n", newAvg(arr1, 7, 90));

    double arr2[8] = {10000.0, 10000.0, 10000.0, 1000.0, 500.0, 60.0, 4.0, 3.0};
    printf("%lld\n", newAvg(arr2, 8, 10000));

    return 0;
}
