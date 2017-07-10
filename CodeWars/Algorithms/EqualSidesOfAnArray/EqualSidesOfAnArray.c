#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_subarr(const int* arr, int from, int to) {
    int sum = 0;

    for (int i = from ; i < to ; ++i)
        sum += arr[i];

    return sum;
}

int find_even_index(const int *values, int length) {

    for (int i = 0 ; i < length ; ++i) {
        if (sum_subarr(values, 0, i) == sum_subarr(values, i+1, length))
            return i;
    }

    return -1;
}

int main() {
    {
        int arr[] = { 1,2,3,4,3,2,1 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 1,100,50,-51,1,1 };
        int expected = 1;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 1,2,3,4,5,6 };
        int expected = -1;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 20,10,30,10,10,15,35 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 20,10,-80,10,10,15,35 };
        int expected = 0;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 10,-80,10,10,15,35,20 };
        int expected = 6;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { 0,0,0,0,0 };
        int expected = 0;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }

    {
        int arr[] = { -1,-2,-3,-4,-3,-2,-1 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(expected == result);
    }
}
