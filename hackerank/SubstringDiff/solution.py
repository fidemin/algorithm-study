#!/bin/python3

import os
import sys

cache = [[-1] * 1500 for _ in range(1500)]

def find_min_diff(n, s1, s2):
    length = len(s1)
    min_ = 987654321
    for i in range(length-n+1):
        for j in range(length-n+1):
            ret = 0
            if s1[i] != s2[j]:
               ret = 1

            if n != 1:
                ret = ret + cache[i+1][j+1]
            cache[i][j] = ret
            if ret < min_:
                min_ = ret

    return min_


# Complete the substringDiff function below.
def substringDiff(k, s1, s2):
    length = len(s1)

    ret = 0
    for n in range(1, length+1):
        min_diff = find_min_diff(n, s1, s2)
        if min_diff <= k:
            ret = n

    return ret


if __name__ == '__main__':

    t = int(input())

    for t_itr in range(t):
        kS1S2 = input().split()

        k = int(kS1S2[0])

        s1 = kS1S2[1]

        s2 = kS1S2[2]

        result = substringDiff(k, s1, s2)
        print(result)
        #print(compare(s1, s2, 0, 5, 0, 5))




