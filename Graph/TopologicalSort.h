#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include <stdio.h>
#include <stdlib.h>

#include "ALGraph.h"
#include "SinglyLinkedList.h"


void ts_sort(alg_graph_t* graph, sll_node_t** list);

#endif
