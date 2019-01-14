#include "ShortestPath.h"

void sp_dijkstra(alg_graph_t* graph, alg_vertex_t* start_v, alg_graph_t* result_graph) {
	int size = graph->size;
	int weight_to[size];
	int weights[size];
	int fringe[size];

	int i = 0;
	alg_vertex_t** result_vertices = (alg_vertex_t**) malloc(sizeof(alg_vertex_t*) * size);
	alg_vertex_t** connect_vertices = (alg_vertex_t**) malloc(sizeof(alg_vertex_t*) * size);

	alg_vertex_t* current = graph->vertices;
	while (current != NULL) {
		alg_vertex_t* result_vertex = alg_create_vertex(current->data);
		alg_add_vertex(result_graph, result_vertex);
		result_vertices[i] = result_vertex;
		weight_to[i] = 30000; // very large number
		weights[i] = 0;
		fringe[i] = 0;
		
		current = current->next;
		i++;
	}	

	pq_queue_t* queue = pq_create_queue(100);
	
	alg_adjacent_t* start_a = alg_create_adjacent(start_v, start_v, 0);
	weight_to[start_v->idx] = 0;

	pq_enqueue(queue, 0, (void*) start_a);

	while (!pq_is_empty(queue)) {
		pq_node_t current_node = pq_dequeue(queue);
		alg_adjacent_t* current_a = (alg_adjacent_t*) current_node.data;
		printf("current vertex idx: %d\n", current_a->vertex->idx);
		printf("from vertex idx: %d\n", current_a->from->idx);

		alg_vertex_t* from_v = current_a->from;
		alg_vertex_t* to_v = current_a->vertex;

		if (from_v == to_v && fringe[to_v->idx] == 0) {
			connect_vertices[to_v->idx] = result_vertices[to_v->idx];
		}

		fringe[to_v->idx] = 1;

		alg_adjacent_t* next_adjacent = to_v->adjacents;

		
		while (next_adjacent != NULL) {
			if (fringe[next_adjacent->vertex->idx] == 0 && (weight_to[next_adjacent->from->idx] + next_adjacent->weight < weight_to[next_adjacent->vertex->idx])) {
				pq_enqueue(queue, next_adjacent->weight, (void*) next_adjacent);
				weight_to[next_adjacent->vertex->idx] = weight_to[next_adjacent->from->idx] + next_adjacent->weight;
				connect_vertices[next_adjacent->vertex->idx] = result_vertices[next_adjacent->from->idx];
				weights[next_adjacent->vertex->idx] = next_adjacent->weight;

			}
			next_adjacent = next_adjacent->next;
		}
	}

	for (int j = 0; j < size; j++) {
		printf("%d : %d\n", j, weight_to[j]);
		if (connect_vertices[j] != result_vertices[j]) {
			printf("%p -> %p : %d\n", connect_vertices[j], result_vertices[j], weights[j]);
			alg_add_edge(connect_vertices[j], result_vertices[j], weights[j]);
		}
	}

	free(result_vertices);
}
