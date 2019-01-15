#include <iostream>
#include <list>

using namespace std;

int josephus(int n, int k) {
	list<int> survivors;
	for (int i = 0; i < n; i++) {
		survivors.push_back(i+1);
	}

	list<int>::iterator toKill = survivors.begin();

	while (n > 2) {
		toKill = survivors.erase(toKill);
		if (toKill == survivors.end()) toKill = survivors.begin();
		--n;


		for (int i = 0; i < (k-1 % n); ++i) {
			++toKill;
			if (toKill == survivors.end()) toKill = survivors.begin();
		}
	}

	for (list<int>::iterator result = survivors.begin(); result != survivors.end(); ++result) {
		cout << *result << " ";
	}
	cout << endl;

	return 0;
}

int main() {
	int n = 6;
	int k = 3;
	
	josephus(6, 3);
}


