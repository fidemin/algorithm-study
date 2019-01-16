#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	vector<TreeNode*> children;
};

int n, y[100], x[100], r[100];

int distance_square(int parent, int child) {
	int x_one = x[parent] - x[child];
	int y_one = y[parent] - y[child];
	return x_one * x_one + y_one * y_one;
}

bool encloses(int parent, int child) {
	int length_square = distance_square(parent, child);
	int diff_r = r[parent] - r[child];
	return r[parent] > r[child] && length_square < (diff_r * diff_r);
}

bool isChild(int parent, int child) {
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; i++) {
		if ( i != parent && i != child && encloses(parent, i) && encloses(i, child)) {
			return false;
		}
	}
	return true;
}

TreeNode* createTree(int root) {
	TreeNode* ret = new TreeNode();
	
	for (int ch = 0; ch < n; ch++) {
		if (isChild(root, ch)) {
			ret->children.push_back(createTree(ch));
		}
	}
	return ret;
}

int longest;

int height(TreeNode* root) {
	vector<int> heights;

	for (int i=0; i< root->children.size(); ++i) {
		heights.push_back(height(root->children[i]));
	}

	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());

	if (heights.size() >= 2) { 
		longest = max(longest, 2 + heights[heights.size() -2] + heights[heights.size()-1]);
	}
	
	return heights.back() + 1;
}

int solve(TreeNode* node) {
	longest = 0;
	return max(longest, height(node));
}

int main() {
	/*
	n = 3;
	x[0] = 5, y[0] = 5, r[0] = 15;
	x[1] = 5, y[1] = 5, r[1] = 10;
	x[2] = 5, y[2] = 5, r[2] = 5;

	TreeNode* tree = createTree(0);
	int h = solve(tree);
	cout << h << endl;
	*/

	n = 8;
	int arr[8][3] = {{21, 15, 20}, {15, 15, 10}, {13, 12, 5}, {12, 12, 3}, {19, 19, 2}, {30, 24, 5}, {32, 10, 7}, {32, 9, 4}};
	for (int i = 0; i < n; i++) {
		x[i] = arr[i][0];
		y[i] = arr[i][1];
		r[i] = arr[i][2];
		cout << x[i] << " " << y[i] << " " << r[i] << " " << endl;
	}
	TreeNode* tree1 = createTree(0);
	int h1 = solve(tree1);
	cout << h1 << endl;
	return 0;
}
