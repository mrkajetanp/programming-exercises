#include <stdio.h>

void print_arr(int* arr, int n) {
    int i;
    for (i = 0 ; i < n ; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int* arr, int n) {
    int i;
    for (i = 1 ; i < n ; ++i) {
        int j = i;
        while ((j > 0) && (arr[j] < arr[j-1])) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
        print_arr(arr, n);
    }
}

int main() {
    /* int arr[] = { 1, 4, 3, 5, 6, 2 }; */
    int arr[] = {9, 8, 6, 7, 3, 5, 4, 1, 2};
    print_arr(arr, 9);
    printf("\n");
    insertion_sort(arr, 9);

    return 0;
}
