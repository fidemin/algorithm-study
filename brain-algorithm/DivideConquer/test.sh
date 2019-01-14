#!/usr/local/bin/bash

clear

echo
echo "[TEST] Merge Sort"
gcc MergeSort.c TestMergeSort.c && ./a.out

echo
echo "[TEST] Exponentiation"
gcc Exponentiation.c TestExponentiation.c && ./a.out


echo
echo "[TEST] Fibonacci"
gcc Fibonacci.c TestFibonacci.c && ./a.out
