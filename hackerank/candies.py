

#!/bin/python3

import math
import os
import random
import re
import sys


def is_ascending(arr, current):
    if arr[current] < arr[current+1]:
        return True
    elif arr[current] > arr[current+1]:
        return False

    return None


def cut_to_partials(arr):
    n = len(arr)
    current = 0
    cut_idx = 0
    result = []
    while current < n-1:
        if current == 0:
            ascending = is_ascending(arr, current)
            current += 1
            continue

        pre_ascending = ascending
        ascending = is_ascending(arr, current)

        if (pre_ascending is None and ascending is None) or (pre_ascending != ascending):
            result.append(arr[cut_idx: current+1])
            cut_idx = current

        if current == n - 2:
            result.append(arr[cut_idx: current+2])

        current += 1

    return result


def partial_candies(partials):

    for partial in partials:
        min_value = 0
        current_depth = 0
        for i in range(len(partial)-1):
            pre_current_depth = current_depth

            if partial[i] > partial[i+1]:
                min_value -= 1
                current_depth -= 1
            elif partial[i] < partial[i+1]:
                current_depth += 1

            partial[i] = pre_current_depth

            if i == len(partial)-2:
                partial[i+1] = current_depth

        for j in range(len(partial)):
            partial[j] = partial[j] + (-min_value + 1)

    return partials


def final_candies(partials):
    result = partials.pop(0)
    while partials:
        partial = partials.pop(0)
        last = result[len(result)-1]
        result[len(result)-1] = max([last, partial[0]])
        result += partial[1:]
    return result

# Complete the candies function below.
def candies(n, arr):
    # small arr
    if n == 1:
        return 1
    elif n == 2:
        if arr[0] == arr[1]:
            return 2
        else:
            return 3

    partials = cut_to_partials(arr)
    partials = partial_candies(partials)
    candies_arr = final_candies(partials)

    return sum(candies_arr)


if __name__ == '__main__':
    print(candies(3, [1, 2, 2]))
    print(candies(10, [2, 4, 2, 6, 1, 7, 8, 9, 2, 1]))
