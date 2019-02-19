#!/bin/python3

import math
import os
import random
import re
import sys

# could not solve this

MOD = 1000000007

cache = {}

def count_array_recursive(n, k, x, prev, i):
    ret = cache.get((prev, i), None)
    if ret is not None:
        return ret
    count = 0
    for value in range(1, k+1):
        if i != n-2 and prev != value:
            count = (count + count_array_recursive(n, k, x, value, i+1)) % MOD
        elif i == n-2 and prev != value and x != value:
            count = (count + 1) % MOD
    ret = count % MOD
    cache[(prev, i)] = ret
    return ret


# Complete the countArray function below.
def countArray(n, k, x):
    # Return the number of ways to fill in the array.
    #return count_array_recursive(n, k, x, 1, 1)
    i = 1
    total_count = 1

    while (i < n-1):
        total_count = (total_count * (k-1)) % MOD
        i+=1

    total_count -= 1
    total_count = total_count - 2 * (k-1)

    return (total_count) % MOD


if __name__ == '__main__':
    nkx = input().split()

    n = int(nkx[0])

    k = int(nkx[1])

    x = int(nkx[2])

    answer = countArray(n, k, x)
    print(answer)


