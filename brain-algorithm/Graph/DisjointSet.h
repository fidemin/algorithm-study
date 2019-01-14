#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _ds_node {
	struct _ds_node* parent;
	void* data;
	int rank;
} ds_node_t;

ds_node_t* ds_create_node(void* data);
void ds_destroy_node(ds_node_t* node);
void ds_union(ds_node_t* node1, ds_node_t* node2);
ds_node_t* ds_find(ds_node_t* node);

#endif
