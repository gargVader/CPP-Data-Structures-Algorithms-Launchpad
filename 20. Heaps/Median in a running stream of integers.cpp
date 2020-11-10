// Median of a stream of running integers

#include <iostream>
#include<queue>
using namespace std;


int main() {

	int n;

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	cin >> n;
	maxHeap.push(n);
	cout << n << " ";

	double curr = n; // current median

	while (cin >> n) {

		// INSERTION:

		// Insert in minHeap
		if (n > curr) {

			if (minHeap.size() > maxHeap.size() + 1) {
				// shift one element from minHeap to maxHeap
				int num = minHeap.top();
				minHeap.pop();
				maxHeap.push(num);
			}

			// Insert
			minHeap.push(n);

		}

		// Insert in maxHeap
		else {

			if (maxHeap.size() > minHeap.size() + 1) {
				// shift one element from maxHeap to minHeap
				int num = maxHeap.top();
				maxHeap.pop();
				minHeap.push(num);
			}
			// Insert
			maxHeap.push(n);
		}

		// PRINTING:

		if (minHeap.size() == maxHeap.size()) {
			curr = (minHeap.top() + maxHeap.top()) / 2.0;
			cout << curr << " ";
		}
		else if (minHeap.size() > maxHeap.size()) {
			curr = minHeap.top();
			cout << curr << " ";
		}
		else {
			curr =  maxHeap.top();
			cout << curr << " ";
		}

	}

}
