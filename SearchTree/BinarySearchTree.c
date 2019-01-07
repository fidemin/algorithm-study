#include "BinarySearchTree.h"

bst_node_t* bst_create_node(bst_element_type_t data) {
	bst_node_t* node = (bst_node_t*) malloc(sizeof(bst_node_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bst_node_t* bst_search_node(bst_node_t* node, bst_element_type_t data) {
	bst_node_t* found = node;

	if (found == NULL) {
		return found;	
	}

	if (found->data == data) {
		return found;
	}
	
	if (found->data < data) {
		return bst_search_node(found->right, data);
	}

	if (found->data > data) {
		return bst_search_node(found->left, data);
	}
	
	return NULL;
}


void bst_insert_node(bst_node_t* root, bst_node_t* node) {
	bst_node_t* current = root;

	if (current == NULL) {
		return;
	}

	if (current->data >= node->data) {
		if (current->left == NULL) {
			current->left = node;
			return;
		}
		return bst_insert_node(current->left, node);
	}

	if (current->data < node->data) {	
		if (current->right == NULL) {
			current->right = node;
			return;
		}
		return bst_insert_node(current->right, node);
	}

}

bst_node_t* bst_search_min_node(bst_node_t* root) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->left == NULL) {
		return root;
	}

	return bst_search_min_node(root->left);
}

bst_node_t* bst_remove_node_sub(bst_node_t** root, bst_node_t* current, bst_node_t* parent, bst_element_type_t target) {
	if (current == NULL) {
		return NULL;
	}

	if (current->data > target) {
		return bst_remove_node_sub(root, current->left, current, target);
	}	

	if (current->data < target) {
		return bst_remove_node_sub(root, current->right, current, target);
	}

	if (current->data == target) {
		if (current->left == NULL && current->right == NULL) {
			// 자식이 둘다 없는 경우
			
			if (parent == NULL) {
				// root 혼자만 있는 경우
				return current;
			}

			if (parent->left == current) {
				parent->left = NULL;	
			} else {
				parent->right = NULL;
			}	
		} else if (current->left != NULL && current->right != NULL) {
			// 자식이 둘다 있는 경우
			
			// 오른쪽 자식 노드의 min_node를 찾아 제거해 가져온다.
			bst_node_t* min_node = bst_search_min_node(current->right);
			bst_node_t* removed = bst_remove_node_sub(root, current->right, current, min_node->data);

			// min_node가 제거된 상태에서의 current의 left, right 노드를 가져온다.
			// 꼭 min_node가 제거된 상태에서 가져와야 한다.
			bst_node_t* left = current->left;
			bst_node_t* right = current->right;

			// min_node에 current의 자식 노드를 연결한다.
			removed->left = left;
			removed->right = right;

			// min_node를 현재 current의 parent에 연결한다.
			if (parent != NULL) {
				if (parent->left == current) {
					parent->left = removed;	
				} else {
					parent->right = removed;
				}	
			} else {
				// 제거된 node가 root node인 경우 (parent가 NULL로 넘어온다.)
				// root 노드를 교체해준다.
				(*root) = removed;
			}
			
			
		} else  {
			// 자식이 하나만 NULL인 경우
			bst_node_t* tmp = NULL;

			if (current->left != NULL) {
				tmp = current->left;
			} else {
				tmp = current->right;
			}

			if (parent != NULL) {
				if (parent->left == current) {
					parent->left = tmp;	
				} else {
					parent->right = tmp;
				}	
			} else {
				(*root) = tmp;
			}
		}
		
		return current;
	}

	
	return NULL;
}


bst_node_t* bst_remove_node(bst_node_t** root, bst_element_type_t target) {
	bst_node_t* current = *root;

	return bst_remove_node_sub(root, current, NULL, target);
}

void bst_destroy_node(bst_node_t* node) {
	free(node);
}
