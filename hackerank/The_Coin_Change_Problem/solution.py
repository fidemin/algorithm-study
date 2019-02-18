
#!/bin/python3

import math
import os
import random
import re
import sys

N = 251
M = 51
cache = [[-1] * M for _ in range(N)]

# Complete the getWays function below.
def getWaysRecursive(n, c):
    print("start:", n, c)
    ret = cache[n][len(c)]
    if ret != -1:
        return ret

    ret = 0
    for i in range(len(c)):
        if n > c[i]:
            ret += getWaysRecursive(n-c[i], c[i:])
        elif n == c[i]:
            ret += 1
            break
        elif n < c[i]:
            break

    cache[n][len(c)] = ret
    return ret


def getWays(n, c):
    return getWaysRecursive(n, tuple(sorted(c)))


if __name__ == '__main__':

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    c = list(map(int, input().rstrip().split()))

    # Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    ways = getWays(n, c)
    print("result:", ways)

