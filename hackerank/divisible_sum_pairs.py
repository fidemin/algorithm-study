
#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

def factorial(n):
    if n == 1 or n == 0:
        return 1

    return n * factorial(n-1)

def combination(n, k):
    if k > n:
        return 0

    return int(factorial(n) / factorial(k) / factorial(n-k))

# Complete the divisibleSumPairs function below.
def divisibleSumPairs(n, k, ar):
    mode = Counter()
    for ele in ar:
        mode[ele%k] += 1

    count = 0
    count += combination(mode[0], 2)
    if k % 2 != 0:
        for i in range(1, k//2+1):
            count += mode[i] * mode[k-i]
    else:
        for i in range(1, k//2+1):
            if i != k//2:
                count += mode[i] * mode[k-i]
            else:
                count += combination(mode[i], 2)

    return count


if __name__ == '__main__':
    n = 6
    k = 3
    ar = [1,3,2,6,1,2]
    print(divisibleSumPairs(n, k, ar))

