#!/bin/python3

import os
import sys

cache = {}

def compare(s1, s2, start1, end1, start2, end2):
    ret = cache.get((start1, end1, start2, end2), None)
    if ret is not None:
        return ret

    if start1 == end1:
        if s1[start1] != s2[start2]:
            return 1
        else:
            return 0

    ret = 0

    if s1[start1] != s2[start2]:
        ret +=  1

    ret += compare(s1, s2, start1+1, end1, start2+1, end2)
    cache[(start1, end1, start2, end2)] = ret
    return ret


def find_min_diff(n, s1, s2):
    length = len(s1)
    limit = length - n + 1

    ret = 987654321
    for i in range(limit):
        for j in range(limit):
            ret = min([ret, compare(s1, s2, i, i+n-1, j, j+n-1)])

    return ret


# Complete the substringDiff function below.
def substringDiff(k, s1, s2):
    n = len(s1)

    while n > 0:
        ret = find_min_diff(n, s1, s2)
        if ret <= k:
            return n

        n -= 1
    return 0


if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        cache = {}
        kS1S2 = input().split()

        k = int(kS1S2[0])

        s1 = kS1S2[1]

        s2 = kS1S2[2]

        result = substringDiff(k, s1, s2)
        print(result)
        #print(compare(s1, s2, 0, 5, 0, 5))




