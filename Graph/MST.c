#include "MST.h"

void mst_prim(alg_graph_t* graph, alg_vertex_t* start_v, alg_graph_t* mst_graph) {
	int size = graph->size;

	//initialize
	int fringe[size];
	int min_weights[size];
	alg_vertex_t** mst_vertices = (alg_vertex_t**) malloc(sizeof(alg_vertex_t*) * size);

	alg_vertex_t* current = graph->vertices;
	

	int i = 0;
	while (current != NULL) {
		alg_vertex_t* mst_vertex = alg_create_vertex(current->data);
		alg_add_vertex(mst_graph, mst_vertex);
		mst_vertices[i] = mst_vertex;
		fringe[i] = 0;
		min_weights[i] = 30000; // very large number
		
		current = current->next;
		i++;
	}

	pq_queue_t* queue = pq_create_queue(100);
	
	alg_adjacent_t* start_a = alg_create_adjacent(start_v, start_v, 0);

	pq_enqueue(queue, 0, (void*) start_a);

	while (!pq_is_empty(queue)) {
		pq_node_t current_node = pq_dequeue(queue);
		alg_adjacent_t* current_a = (alg_adjacent_t*) current_node.data;
		printf("current vertex idx: %d\n", current_a->vertex->idx);
		printf("from vertex idx: %d\n", current_a->from->idx);

		// append edge to mst
		alg_vertex_t* from_v = current_a->from;
		alg_vertex_t* to_v = current_a->vertex;

		if (from_v != to_v && fringe[to_v->idx] == 0) {
			printf("%d <-> %d\n", from_v->idx, to_v->idx);
			alg_add_edge_bidirect(mst_vertices[from_v->idx], mst_vertices[to_v->idx], current_a->weight);
		}

		fringe[to_v->idx] = 1;

		alg_adjacent_t* next_adjacent = to_v->adjacents;

		while (next_adjacent != NULL) {
			if (fringe[next_adjacent->vertex->idx] == 0 && (next_adjacent->weight < min_weights[next_adjacent->vertex->idx])) {
				pq_enqueue(queue, next_adjacent->weight, (void*) next_adjacent);
				min_weights[next_adjacent->vertex->idx] = next_adjacent->weight;

			}
			next_adjacent = next_adjacent->next;
		}
	}

	free(mst_vertices);
}
