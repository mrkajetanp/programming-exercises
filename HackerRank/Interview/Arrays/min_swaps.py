#!/usr/bin/env python3

def minimumSwaps(arr):
    result = 0
    indices = {v: i for i, v in enumerate(arr)}
    sorted_arr = sorted(arr)

    for i in range(len(arr)):
        if arr[i] == sorted_arr[i]:
            continue

        idx_to_swap = indices[sorted_arr[i]]
        arr[i], arr[idx_to_swap] = arr[idx_to_swap], arr[i]
        indices[arr[i]] = idx_to_swap
        indices[sorted_arr[i]] = i
        result += 1

    return result

    #         to_swap_ix = index_dict[correct_value]
    #         arr[to_swap_ix],arr[i] = arr[i], arr[to_swap_ix]
    #         index_dict[v] = to_swap_ix
    #         index_dict[correct_value] = i
    #         swaps += 1

print(minimumSwaps([7, 1, 3, 2, 4, 5, 6]))
print(minimumSwaps([4, 3, 1, 2]))
print(minimumSwaps([2, 3, 4, 1, 5]))
print(minimumSwaps([1, 3, 5, 2, 4, 6, 7]))
print(minimumSwaps([]))
print(minimumSwaps([2, 1]))
