#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <stdio.h>
#include <stdlib.h>

#include "ALGraph.h"
#include "PriorityQueue.h"

void sp_dijkstra(alg_graph_t* graph, alg_vertex_t* start_v, alg_graph_t* result_graph);

#endif
