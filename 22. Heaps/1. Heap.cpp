#include <iostream>
#include<vector>
using namespace std;

class Heap {
	vector<int> v;
	bool minHeap = 1;

	bool cmp(int a, int b) {
		if (minHeap) {
			return a < b;
		} else {
			return a > b;
		}
	}

	void heapify(int idx) {

		int left = 2 * idx;
		int right = 2 * idx + 1;

		int ans_idx = idx;
		int last = v.size() - 1;

		if (left <= last && cmp(v[left], v[idx])) {
			ans_idx = left;
		}

		if (right <= last && cmp(v[right], v[ans_idx])) {
			ans_idx = right;
		}

		// Base Case
		if (ans_idx != idx) {
			swap(v[idx], v[ans_idx]);
			heapify(ans_idx);
		}

		// Function will end when ans_idx==idx, i.e, there is no need to
		// heapify it further.
	}

public:
	Heap(int deafultSize = 10, bool type = true) {
		v.reserve(deafultSize);
		v.push_back(-1); // Blocking 0th index
		minHeap = type;
	}
	// O(logn)
	void push(int d) {
		v.push_back(d);
		int idx = v.size() - 1;
		int parent = idx / 2;

		while (parent >= 1 && cmp(v[idx], v[parent]) ) {
			// swap
			int temp = v[idx];
			v[idx] = v[parent];
			v[parent] = temp;

			idx = parent;
			parent = idx / 2;
		}
	}

	int top() {
		return v[1];
	}

	// removes the root element
	// O(logn)
	void pop() {
		int last = v.size() - 1;
		//swap
		swap(v[last], v[1]);
		v.pop_back();

		// fix postion of v[1]
		heapify(1);

	}

	void print() {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		} cout << endl;
	}

	bool isEmpty() {
		return v.size() == 1;
	}
};

int main() {

	Heap h;
	h.push(1);
	h.push(2);
	h.push(3);
	h.push(17);
	h.push(19);
	h.push(36);
	h.push(7);
	h.push(25);
	h.push(100);

	h.print();
	h.push(5);
	h.print();
	h.pop();
	h.print();

}
