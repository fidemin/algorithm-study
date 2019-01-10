#ifndef AL_GRAPH_H
#define AL_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"


typedef struct _alg_adjacent {
	struct _alg_vertex* from;
	struct _alg_vertex* vertex; // have vertex address
	struct _alg_adjacent* next;
	int weight;
} alg_adjacent_t;

typedef struct _alg_vertex {
	int data;
	alg_adjacent_t* adjacents;
	struct _alg_vertex* next;

	int visited;
	int idx;
} alg_vertex_t;

typedef struct _alg_graph {
	alg_vertex_t* vertices;
	int size;
} alg_graph_t;

alg_graph_t* alg_create_graph();
void alg_destroy_graph(alg_graph_t* graph);
alg_vertex_t* alg_create_vertex(int data);
void alg_destroy_vertex(alg_vertex_t* vertex);
void alg_add_vertex(alg_graph_t* graph, alg_vertex_t* vertex);
void alg_add_edge(alg_vertex_t* v1, alg_vertex_t* v2, int weight);
void alg_add_edge_bidirect(alg_vertex_t* v1, alg_vertex_t* v2, int weight);
void alg_print_graph(alg_graph_t* graph);
void alg_reset_visited(alg_graph_t* graph);
void alg_dfs(alg_vertex_t* vertex);
void alg_bfs(alg_vertex_t* vertex);

#endif
