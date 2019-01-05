#!/usr/local/bin/bash

clear
echo
echo "[TEST] Merge Sort"

gcc MergeSort.c TestMergeSort.c && ./a.out
