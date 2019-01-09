#include <stdio.h>
#include "TestRunner.h"
#include "ALGraph.h"

int test_alg_create_graph() {
	alg_graph_t* graph = alg_create_graph();
	_assert(NULL == graph->vertices);
	_assert(0 == graph->size); 
	alg_destroy_graph(graph);
	return 0;
}

int test_alg_create_vertex() {
	alg_vertex_t* vertex = alg_create_vertex(1);
	_assert(1 == vertex->data);
	_assert(NULL == vertex->adjacents);
	_assert(NULL == vertex->next);
	_assert(0 == vertex->visited);
	alg_destroy_vertex(vertex);
	return 0;
}

int test_alg_add_vertex() {
	alg_graph_t* graph = alg_create_graph();
	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	_assert(vertex1 == graph->vertices);
	_assert(1 == graph->size);

	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);
	_assert(vertex1 == graph->vertices);
	_assert(vertex2 == graph->vertices->next);
	_assert(NULL == graph->vertices->next->next);
	_assert(2 == graph->size);

	alg_add_vertex(graph, vertex2);
	_assert(2 == graph->size);

	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	_assert(vertex1 == graph->vertices);
	_assert(vertex2 == graph->vertices->next);
	_assert(vertex3 == graph->vertices->next->next);
	_assert(NULL == graph->vertices->next->next->next);
	_assert(3 == graph->size);

	alg_add_vertex(graph, vertex3);

	alg_destroy_graph(graph);

	return 0;
}

int test_alg_add_edge() {
	alg_graph_t* graph = alg_create_graph();
	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);
	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	alg_vertex_t* vertex4 = alg_create_vertex(4);
	alg_add_vertex(graph, vertex4);

	alg_add_edge(vertex1, vertex3, 3);
	_assert(vertex3 == graph->vertices->adjacents->vertex);	
	alg_add_edge(vertex1, vertex2, 4);
	_assert(vertex2 == graph->vertices->adjacents->next->vertex);	


	// exception cases
	alg_add_edge(vertex1, vertex2, 5);
	alg_add_edge(vertex2, vertex2, 5);

	alg_destroy_graph(graph);
	return 0;
}

int test_alg_reset_visited() {
	alg_graph_t* graph = alg_create_graph();

	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);

	vertex1->visited = 1;
	vertex2->visited = 2;

	alg_reset_visited(graph);
	_assert(0 == vertex1->visited);
	_assert(0 == vertex2->visited);

	alg_destroy_graph(graph);
	return 0;
}

int test_alg_print_graph() {
	alg_graph_t* graph = alg_create_graph();
	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);
	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	alg_vertex_t* vertex4 = alg_create_vertex(4);
	alg_add_vertex(graph, vertex4);
	alg_vertex_t* vertex5 = alg_create_vertex(5);
	alg_add_vertex(graph, vertex5);

	alg_add_edge(vertex1, vertex2, 1);
	alg_add_edge(vertex1, vertex3, 1);
	alg_add_edge(vertex1, vertex4, 1);
	alg_add_edge(vertex2, vertex3, 1);
	alg_add_edge(vertex2, vertex5, 1);
	alg_add_edge(vertex5, vertex4, 1);

	alg_print_graph(graph);

	alg_destroy_graph(graph);
	return 0;
}

int test_alg_dfs_graph() {
	alg_graph_t* graph = alg_create_graph();

	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);

	alg_dfs(vertex1);
	_assert(1 == vertex1->visited);
	_assert(0 == vertex2->visited);
	alg_reset_visited(graph);

	alg_add_edge(vertex1, vertex2, 1);
	alg_dfs(vertex1);
	_assert(1 == vertex1->visited);
	_assert(1 == vertex2->visited);
	alg_reset_visited(graph);

	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	alg_vertex_t* vertex4 = alg_create_vertex(4);
	alg_add_vertex(graph, vertex4);
	alg_vertex_t* vertex5 = alg_create_vertex(5);
	alg_add_vertex(graph, vertex5);
	alg_vertex_t* vertex6 = alg_create_vertex(6);
	alg_add_vertex(graph, vertex6);
	alg_vertex_t* vertex7 = alg_create_vertex(7);
	alg_add_vertex(graph, vertex7);

	alg_add_edge(vertex2, vertex5, 1);
	alg_add_edge(vertex5, vertex7, 1);
	alg_add_edge(vertex2, vertex4, 1);
	alg_add_edge(vertex4, vertex5, 1);
	alg_add_edge(vertex4, vertex7, 1);
	alg_add_edge(vertex1, vertex3, 1);
	alg_add_edge(vertex3, vertex6, 1);
	alg_add_edge(vertex6, vertex7, 1);

	alg_print_graph(graph);
	alg_dfs(vertex1);

	_assert(1 == vertex1->visited);
	_assert(1 == vertex2->visited);
	_assert(1 == vertex3->visited);
	_assert(1 == vertex4->visited);
	_assert(1 == vertex5->visited);
	_assert(1 == vertex6->visited);
	_assert(1 == vertex7->visited);

	alg_destroy_graph(graph);
	return 0;
}

int test_alg_bfs_graph() {
	alg_graph_t* graph = alg_create_graph();

	alg_vertex_t* vertex1 = alg_create_vertex(1);
	alg_add_vertex(graph, vertex1);
	alg_vertex_t* vertex2 = alg_create_vertex(2);
	alg_add_vertex(graph, vertex2);

	alg_bfs(vertex1);
	_assert(1 == vertex1->visited);
	_assert(0 == vertex2->visited);
	alg_reset_visited(graph);

	alg_add_edge(vertex1, vertex2, 1);
	alg_bfs(vertex1);
	_assert(1 == vertex1->visited);
	_assert(1 == vertex2->visited);
	alg_reset_visited(graph);

	alg_vertex_t* vertex3 = alg_create_vertex(3);
	alg_add_vertex(graph, vertex3);
	alg_vertex_t* vertex4 = alg_create_vertex(4);
	alg_add_vertex(graph, vertex4);
	alg_vertex_t* vertex5 = alg_create_vertex(5);
	alg_add_vertex(graph, vertex5);
	alg_vertex_t* vertex6 = alg_create_vertex(6);
	alg_add_vertex(graph, vertex6);
	alg_vertex_t* vertex7 = alg_create_vertex(7);
	alg_add_vertex(graph, vertex7);

	alg_add_edge(vertex2, vertex5, 1);
	alg_add_edge(vertex5, vertex7, 1);
	alg_add_edge(vertex2, vertex4, 1);
	alg_add_edge(vertex4, vertex5, 1);
	alg_add_edge(vertex4, vertex7, 1);
	alg_add_edge(vertex1, vertex3, 1);
	alg_add_edge(vertex3, vertex6, 1);
	alg_add_edge(vertex6, vertex7, 1);

	alg_print_graph(graph);
	alg_bfs(vertex1);

	_assert(1 == vertex1->visited);
	_assert(1 == vertex2->visited);
	_assert(1 == vertex3->visited);
	_assert(1 == vertex4->visited);
	_assert(1 == vertex5->visited);
	_assert(1 == vertex6->visited);
	_assert(1 == vertex7->visited);

	alg_destroy_graph(graph);
	return 0;
}

int all_tests() {
	_verify(test_alg_create_graph);
	_verify(test_alg_create_vertex);
	_verify(test_alg_add_vertex);
	_verify(test_alg_add_edge);
	_verify(test_alg_print_graph);
	_verify(test_alg_reset_visited);
	_verify(test_alg_dfs_graph);
	_verify(test_alg_bfs_graph);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
