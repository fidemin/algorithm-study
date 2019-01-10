#!/usr/local/bin/bash

clear

echo "[TEST] ALGraph"
gcc TestALGraph.c ALGraph.c LinkedListQueue.c && ./a.out

echo "[TEST] TopologicalSort"
gcc TestTopologicalSort.c ALGraph.c LinkedListQueue.c TopologicalSort.c SinglyLinkedList.c && ./a.out

