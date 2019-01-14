#include <iostream>
#include <vector>
using namespace std;

void pick_with_loop(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k ++) {
				for (int l = k+1; l < n; l++) {
					cout << i << " " << j << " " << k << " " << l << endl;
				}
			}
		}
	}
}

void printPicked(vector<int>& picked) {
	for (int i = 0; i < picked.size(); i++) {
		cout << picked[i] << " ";
	}
	 
	cout << endl;
}

void pick_recursive(int n, vector<int>& picked, int left) {
	if (left == 0) {
		printPicked(picked);	
		return;
	} 

	int smallest = 0;
	if (picked.size() != 0) {
		smallest = picked.back() + 1;
	}

	for (int i = smallest; i < n; i ++) {
		picked.push_back(i);
		pick_recursive(n, picked, left-1);
		picked.pop_back();
	}
	return;
}

void pick_with_recursion(int n, int numOfPicks) {
	vector<int> picked;
	pick_recursive(n, picked, numOfPicks);
}

int main() {
	pick_with_recursion(4, 4);
	return 0;
}
