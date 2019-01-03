#!/usr/local/bin/bash

echo "[TEST] SinglyLinkedList"
gcc TestSinglyLinkedList.c SinglyLinkedList.c && ./a.out

echo ""
echo "[TEST] DoublyLinkedList"
gcc TestDoublyLinkedList.c DoublyLinkedList.c && ./a.out
