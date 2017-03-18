#include <stdio.h>

void insertion_sort_one(int* arr, int n) {
    int i;
    int temp = arr[n-1];
    for (i = n-1 ; arr[i-1] > temp ; --i)
        arr[i] = arr[i-1];
    arr[i] = temp;
}

void print_arr(int* arr, int n) {
    int i;
    for (i = 0; i < n ; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 2, 4, 6, 8, 3 };

    print_arr(arr, 5);
    insertion_sort_one(arr, 5);
    print_arr(arr, 5);

    return 0;
}
