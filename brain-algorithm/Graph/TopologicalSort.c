#include "TopologicalSort.h"

void ts_dfs(alg_vertex_t* vertex, sll_node_t** list) {
	if (vertex == NULL) {
		return;
	}

	if (vertex->visited) {
		return;
	}

	vertex->visited = 1;

	alg_adjacent_t* current = vertex->adjacents;
	while (current != NULL) {
		if (!current->vertex->visited) {
			ts_dfs(current->vertex, list);
		} 
		current = current->next;
	}

	sll_node_t* node =  sll_create_node(vertex);
	sll_insert_node_before(list, *list, node);
	printf("%d ", node->data->data);
}

void ts_sort(alg_graph_t* graph, sll_node_t** list) {
	printf("-------- Topological Sort --------\n");
	alg_vertex_t* vertex = graph->vertices;

	while (vertex != NULL) {
		ts_dfs(vertex, list);
		vertex = vertex->next;
	}
	printf("\n\n");
}


