#!/bin/python3

import os
import sys

def max_length_diff(i, j, k, s1, s2):
    best = 0
    bad = 0
    l = 0
    n = len(s1)

    while 1:
        if i + l >= n or j + l >= n:
            best = max([best, l])
            break

        if s1[i+l] != s2[j+l]:
            bad += 1

        if bad > k:
            best = max([best, l])

            while s1[i] == s2[j]:
                i += 1
                j += 1
                l -= 1

            bad -= 1
            i += 1
            j += 1
        else:
            l += 1

    return best


def substringDiff(k, s1, s2):
    best = 0
    for i in range(len(s1)):
        best = max([best, max_length_diff(0, i, k, s1, s2), max_length_diff(i, 0, k, s1, s2)])

    return best

# Complete the substringDiff function below.
def substringDiffBF(k, s1, s2):
    best = 0
    N = len(s1)

    for i in range(0, N):
        for j in range(0, N):
            bad = 0
            for l in range(0, N):
                if i + l >= N or j + l >= N:
                    best = max([best, l])
                    break

                if s1[i+l] != s2[j+l]:
                    bad += 1

                if bad > k:
                    best = max([best, l])
                    break

    return best




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




