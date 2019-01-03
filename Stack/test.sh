#!/usr/local/bin/bash

clear
echo "[TEST] ArrayStack"
gcc TestArrayStack.c ArrayStack.c && ./a.out

echo ""
echo "[TEST] LinkedListStack"
gcc TestLinkedListStack.c LinkedListStack.c && ./a.out
