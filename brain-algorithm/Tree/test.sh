#!/usr/local/bin/bash

clear

echo "[TEST] LCRSTree"
gcc TestLCRSTree.c LCRSTree.c && ./a.out

echo
echo "[TEST] SBTree"
gcc TestSBTree.c SBTree.c && ./a.out

echo
echo "[TEST] Disjointset"
gcc TestDisjointset.c DisjointSet.c && ./a.out
