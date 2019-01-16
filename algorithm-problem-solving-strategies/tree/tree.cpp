#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	string label;
	TreeNode* parent;
	vector<TreeNode*> children;
};

TreeNode* createTreeNode(string data) {
	TreeNode* node = new TreeNode();
	node->label = data;
	node->parent = NULL;
	return node;
}

void appendChild(TreeNode* root, TreeNode* child) {
	child->parent = root;
	root->children.push_back(child);
}

void destroyTreeNode(TreeNode* node) {
	delete node;
}

void printTreeNode(TreeNode* root) {
	cout << root->label << endl;
	
	for (int i = 0; i < root->children.size(); ++i) {
		printTreeNode(root->children[i]);
	}
}

int heightTreeNode(TreeNode* root) {
	int height = 1;
	
	for (int i = 0; i < root->children.size(); ++i) {
		height = max(height, 1+heightTreeNode(root->children[i]));
	}
	return height;
}

int main() {
	TreeNode* root = createTreeNode("a");
	TreeNode* c1 = createTreeNode("b");
	TreeNode* c11 = createTreeNode("c");
	TreeNode* c12 = createTreeNode("d");
	TreeNode* c2 = createTreeNode("e");

	appendChild(root, c1);
	appendChild(c1, c11);
	appendChild(c1, c12);
	appendChild(root, c2);

	printTreeNode(root);
	cout << heightTreeNode(root) << endl;
}
