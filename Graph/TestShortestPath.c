#include <stdio.h>
#include "TestRunner.h"
#include "ALGraph.h"
#include "SinglyLinkedList.h"
#include "ShortestPath.h"

int test_sp_dijkstra() {
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
	alg_vertex_t* vertex6 = alg_create_vertex(6);
	alg_add_vertex(graph, vertex6);
	alg_vertex_t* vertex7 = alg_create_vertex(7);
	alg_add_vertex(graph, vertex7);
	alg_vertex_t* vertex8 = alg_create_vertex(8);
	alg_add_vertex(graph, vertex8);
	alg_vertex_t* vertex9 = alg_create_vertex(9);
	alg_add_vertex(graph, vertex9);

	alg_add_edge(vertex2, vertex1, 35);
	alg_add_edge(vertex2, vertex3, 126);
	alg_add_edge(vertex3, vertex4, 117);
	alg_add_edge(vertex1, vertex5, 247);
	alg_add_edge(vertex2, vertex6, 150);
	alg_add_edge(vertex3, vertex6, 162);
	alg_add_edge(vertex3, vertex7, 220);
	alg_add_edge(vertex6, vertex5, 82);
	alg_add_edge(vertex6, vertex7, 154);
	alg_add_edge(vertex7, vertex9, 106);
	alg_add_edge(vertex5, vertex8, 98);
	alg_add_edge(vertex6, vertex8, 120);

	alg_graph_t* result_graph = alg_create_graph();
	sp_dijkstra(graph, vertex2, result_graph); 

	alg_print_graph(result_graph);

	alg_destroy_graph(graph);
	alg_destroy_graph(result_graph);
	return 0;
}

int all_tests() {
	_verify(test_sp_dijkstra);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
