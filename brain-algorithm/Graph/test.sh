#!/usr/local/bin/bash

function check_success() {
	if [ $? -eq 0 ]; then
		echo [TEST] $1 test success
		echo
	else
		echo "[TEST] $1 test failed"
		exit 1;
	fi	
}

clear

echo "[TEST] ALGraph"
gcc TestALGraph.c ALGraph.c LinkedListQueue.c && ./a.out

check_success "ALGraph"

echo
echo "[TEST] TopologicalSort"
gcc TestTopologicalSort.c ALGraph.c LinkedListQueue.c SinglyLinkedList.c TopologicalSort.c && ./a.out

check_success "Topological Sort"

echo
echo "[TEST] MST"
gcc TestMST.c PriorityQueue.c ALGraph.c LinkedListQueue.c MST.c DisjointSet.c && ./a.out

check_success "MST"

echo
echo "[TEST] Shortest Path"
gcc TestShortestPath.c PriorityQueue.c ALGraph.c LinkedListQueue.c ShortestPath.c DisjointSet.c && ./a.out

check_success "Shortest Path"
