#include <stdio.h>
#include "binary_search.h"

int binary_search_idx_rec(int* arr, int key, int low, int high) {
    if (low > high)
        return -1;

    int mid = (low+high) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return binary_search_idx_rec(arr, key, low, mid-1);
    else
        return binary_search_idx_rec(arr, key, mid+1, high);
}

int* binary_search(int x, int* arr, int len) {
    if (!arr || len == 0)
        return NULL;

    int idx = binary_search_idx_rec(arr, x, 0, len);

    if (idx == -1)
        return NULL;

    return &arr[idx];
}
