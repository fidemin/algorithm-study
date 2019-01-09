#!/usr/local/bin/bash

clear
echo "[TEST] CircularQueue"
gcc TestCircularQueue.c CircularQueue.c && ./a.out

echo ""
echo "[TEST] LinkedListQueue"
gcc TestLinkedListQueue.c LinkedListQueue.c && ./a.out


