#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	int size = preorder.size();
	if (size == 0) {
		return;
	}
	int root = preorder[0];
	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, size), slice(inorder, L+1, size));
	cout << root << " ";
}


int main() {
	int arr [] = {27, 16, 9, 12, 54, 36, 72};
	int arr2 [] = {9, 12, 16, 27, 36, 54, 72} ;
	vector<int> preorder(arr, arr + sizeof(arr)/sizeof(arr[0]));
	vector<int> postorder(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
	printPostOrder(preorder, postorder);
}

