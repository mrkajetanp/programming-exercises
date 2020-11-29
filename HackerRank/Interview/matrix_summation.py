#!/usr/bin/env python3

def matrix_summation(arr):
    def before_sum(array, x, y):
        result = 0
        for i in range(x+1):
            for j in range(y+1):
                result += array[i][j]
        return result - array[x][y]

    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if i == 0 and j == 0:
                continue
            arr[i][j] -= before_sum(arr, i, j)

    return arr


def print_matrix(arr):
    for row in arr:
        for x in row:
            print(x, end=" ")
        print()


test_1 = [
    [1, 2],
    [3, 4]
]
print_matrix(test_1)
print()
print_matrix(matrix_summation(test_1))
print()
test_1 = [
    [2, 5],
    [7, 17]
]
print_matrix(test_1)
print()
print_matrix(matrix_summation(test_1))
print()
