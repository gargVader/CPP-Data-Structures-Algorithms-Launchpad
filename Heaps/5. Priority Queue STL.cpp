#include <iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int> pq2; // max heap
	priority_queue<int, vector<int>, greater<int>> pq; // min heap
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int no; cin >> no;
		pq.push(no); // O(logn)
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

}

// Can be used to make comparators for priority queue STL class
