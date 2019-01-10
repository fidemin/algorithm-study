#!/usr/local/bin/bash

clear

echo "[TEST] ALGraph"
gcc TestALGraph.c ALGraph.c LinkedListQueue.c && ./a.out

if [ $? -eq 0 ]; then
    echo [TEST] ALGraph test success
	echo
else
	echo "[TEST] ALGraph test failed"
	exit 1;
fi

echo
echo "[TEST] TopologicalSort"
gcc TestTopologicalSort.c ALGraph.c LinkedListQueue.c SinglyLinkedList.c TopologicalSort.c && ./a.out

if [ $? -eq 0 ]; then
    echo [TEST] TopologicalSort test success
	echo
else
	echo "[TEST] TopologicalSort test failed"
	exit 1;
fi


echo
echo "[TEST] MST"
gcc TestMST.c PriorityQueue.c ALGraph.c LinkedListQueue.c MST.c && ./a.out
