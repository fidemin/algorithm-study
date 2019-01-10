#ifndef MST_H
#define MST_H

#include <stdio.h>
#include <stdlib.h>

#include "ALGraph.h"
#include "PriorityQueue.h"
#include "DisjointSet.h"

void mst_prim(alg_graph_t* graph, alg_vertex_t* start_v, alg_graph_t* mst_graph);


void mst_kruskal(alg_graph_t* graph, alg_vertex_t* start_v, alg_graph_t* mst_graph);

#endif
