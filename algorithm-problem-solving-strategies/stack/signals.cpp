#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int simple(vector<int>& signals, int k) {
	int ret = 0;
	for (int head = 0; head < signals.size(); ++head) {
		int sum = 0;
		for (int tail = head; tail < signals.size(); ++tail) {
			sum = sum + signals[tail];
			if (sum == k) ret++;
			if (sum > k) break;
		}
	}
	return ret;
}

int optimized(vector<int>& signals, int k) {
	int ret = 0;
	int tail = 0;
	int sum = signals[0];
	for (int head = 0; head < signals.size(); ++head) {
		while(sum < k && tail+1 < signals.size()) {
			sum = sum + signals[++tail];
		}	

		if (sum == k) {
			ret++;	
		}
		sum = sum - signals[head];
		
	}
	return ret;
}

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int n, int k) {
	RNG rng;
	unsigned sum = 0;
	queue<int> lst;
	int tail = 0;
	int ret = 0;
	

	while (tail < n) {
		while (sum < k && tail < n) {
			unsigned next = rng.next();
			lst.push(next);
			sum += next;
			tail++;
		} 

		if (sum == k) ret++;
		sum = sum - lst.front();	
		lst.pop();
	}

	return ret;
}

int main() {
	vector<int> signals;
	signals.push_back(1);
	signals.push_back(4);
	signals.push_back(2);
	signals.push_back(1);
	signals.push_back(4);
	signals.push_back(3);
	signals.push_back(1);
	signals.push_back(6);
	int ret = optimized(signals, 7);
	assert(5 == ret);

	assert(1 == countRanges(20, 8791));
	assert(4 == countRanges(5000, 5265));
	assert(1049 == countRanges(5000000, 3578452));
}
