#include <stdio.h>
#include <stdlib.h>

int twistANumber (int num) {
	int i = num, counter = 0;
	while (i != 0) {
		i /= 10;
		++counter;
	}
	char buffer[counter+1];

	sprintf (buffer, "%d", num);

	for (i = 0 ; buffer[i] != '\0' ; ++i) {
		if (buffer[i] == '3')
			buffer[i] = '7';
		else if (buffer[i] == '7')
			buffer[i] = '3';
	}
	return atoi (buffer);
}

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort (int *arr, int n) {
	int i, j;
	for (i = 0 ; i < n ; ++i) {
		j = i;
		while ((j > 0) && (arr[j-1] > arr[j])) {
			swap (&arr[j-1], &arr[j]);
			j--;
		}
	}
}

int* sortTwisted37(int* array, int arrayLength) {
	int i;
	int * resArr = calloc (arrayLength, sizeof(int));

	for (i = 0 ; i < arrayLength ; ++i) 
		resArr[i] = twistANumber (array[i]);

	insertionSort (resArr, arrayLength);

	for (i = 0 ; i < arrayLength ; ++i) 
		resArr[i] = twistANumber (resArr[i]);
	return resArr;
}

int main () {
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 17};
	int arr2[] = {9, 2, 4, 7, 3};
	int arr3[] = {12, 13, 17};
	int *arrDone = sortTwisted37 (arr2, 5);

	for (int i = 0; i < 5; ++i)
		printf ("%d ", arrDone[i]);
	printf ("\n");

	free (arrDone);

	return 0;
}