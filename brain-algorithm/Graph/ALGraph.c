#include "ALGraph.h"

alg_graph_t* alg_create_graph() {
	alg_graph_t* graph = (alg_graph_t*) malloc(sizeof(alg_graph_t));
	graph->size = 0;
	graph->vertices = NULL;
	return graph;
}


void alg_destroy_graph(alg_graph_t* graph) {
	alg_vertex_t* current = graph->vertices;

	while (current != NULL) {
		alg_vertex_t* old = current;
		current = current->next;
		alg_destroy_vertex(old);
	}
	free(graph);

}


alg_vertex_t* alg_create_vertex(int data) {
	alg_vertex_t* vertex = (alg_vertex_t*) malloc(sizeof(alg_vertex_t));
	vertex->data = data;
	vertex->adjacents = NULL;
	vertex->next = NULL;
	vertex->visited = 0;
	return vertex;
}


void alg_destroy_vertex(alg_vertex_t* vertex) {
	alg_adjacent_t* current = vertex->adjacents;

	while (current != NULL) {
		alg_adjacent_t* old = current;
		current = current->next;
		free(old);
	}
	free(vertex);
}


void alg_add_vertex(alg_graph_t* graph, alg_vertex_t* vertex) {
	alg_vertex_t* current = graph->vertices;
	alg_vertex_t* prev = NULL;
	if (current == NULL) {
		graph->vertices = vertex;
		vertex->idx = 0;
		graph->size = 1;
		return;
	}

	while (current != NULL) {
		if (current == vertex) {
			printf("vertex %p already exists in graph\n", vertex);
			return;
		}
		prev = current;
		current = current->next;
	}

	prev->next = vertex; 
	vertex->idx = graph->size;
	graph->size++;
}

alg_adjacent_t* alg_create_adjacent(alg_vertex_t* from, alg_vertex_t* v, int weight) {
	alg_adjacent_t* adjacent = (alg_adjacent_t*) malloc(sizeof(alg_adjacent_t));
	adjacent->next = NULL;
	adjacent->from = from;
	adjacent->vertex = v;
	adjacent->weight = weight;
	return adjacent;
}


void alg_add_edge(alg_vertex_t* v1, alg_vertex_t* v2, int weight) {
	if (v1 == v2) {
		printf("v1 and v2 are same\n");
		return;
	}

	if (v1->adjacents == NULL) {
		v1->adjacents = alg_create_adjacent(v1, v2, weight);
		return;
	}
	
	alg_adjacent_t* current = v1->adjacents;
	alg_adjacent_t* prev = NULL;

	while (current != NULL) {
		if (current->vertex == v2) {
			printf("edge with vertex %p already exists\n", v2);
			return;
		}
		prev = current;
		current = current->next;
	}
	prev->next = alg_create_adjacent(v1, v2, weight);
}

void alg_add_edge_bidirect(alg_vertex_t* v1, alg_vertex_t* v2, int weight) {
	alg_add_edge(v1, v2, weight);
	alg_add_edge(v2, v1, weight);
}

void alg_print_graph(alg_graph_t* graph) {
	printf("-------- PRINT GRAPH --------\n");
	alg_vertex_t* vertex = graph->vertices;

	while (vertex != NULL) {
		printf("%d [", vertex->data);
		alg_adjacent_t* adjacent = vertex->adjacents;
		while (adjacent != NULL) {
			printf("%d ", adjacent->vertex->data);
			adjacent = adjacent->next;
		}
		printf(" ]\n");
		vertex = vertex->next;
	}
	printf("\n\n");
}

void alg_reset_visited(alg_graph_t* graph) {
	alg_vertex_t* current = graph->vertices;
	while (current != NULL) {
		current->visited = 0;
		current = current->next;
	}
}

void alg_dfs_from_vertex(alg_vertex_t* vertex) {
	if (vertex == NULL) {
		return;
	}

	if (vertex->visited) {
		return;
	}

	vertex->visited = 1;
	printf("%d ", vertex->data);

	alg_adjacent_t* current = vertex->adjacents;
	while (current != NULL) {
		if (!current->vertex->visited) {
			alg_dfs_from_vertex(current->vertex);
		} 
		current = current->next;
	}
}

void alg_dfs(alg_vertex_t* vertex) {
	printf("-------- DFS --------\n");
	alg_dfs_from_vertex(vertex);
	printf("\n\n");
}

void alg_bfs(alg_vertex_t* vertex) {
	printf("-------- BFS --------\n");
	if (vertex == NULL) {
		printf("\n\n");
		return;
	}

	llq_queue_t* queue = llq_create_queue();

	if (!vertex->visited) {
		vertex->visited = 1;
		llq_enqueue(queue, llq_create_node((llq_element_type_t) vertex));
		printf("%d ", vertex->data);

		while (!llq_is_empty(queue)) {
			llq_node_t* node = llq_dequeue(queue);
			alg_vertex_t* vertex = (alg_vertex_t*) node->data;
			alg_adjacent_t* adjacent = vertex->adjacents;
			while (adjacent != NULL) {
				if (!adjacent->vertex->visited) {
					adjacent->vertex->visited = 1;
					llq_enqueue(queue, llq_create_node((llq_element_type_t) adjacent->vertex));
					printf("%d ", adjacent->vertex->data);
				}
				adjacent = adjacent->next;
			}
			llq_destroy_node(node);
		}		
	}
	printf("\n\n");
}
