// O(nlogn)
// top to bottom

#include <iostream>
#include<vector>
using namespace std;

// for max heap
bool cmp(int a, int b) {
	return a > b;
}

void heapify(vector<int> &a, int idx) {

	int parent = idx / 2;

	// Base Case
	if (parent == idx) return;

	if (!cmp(a[parent], a[idx])) {
		swap(a[idx], a[parent]);
		heapify(a, parent);
	}
}


void buildHeapRec(vector<int> &v) {

	for (int i = 0; i < v.size(); i++) {
		heapify(v, i);
	}

}

void buildHeap(vector<int> &v) {

	for (int i = 1; i < v.size(); i++) {
		int idx = i;
		int parent = i / 2;

		while (idx > 0 && v[idx] > v[parent]) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}

}

int main() {

	vector<int> v{10, 20, 5, 6, 1, 8, 9, 4};

	buildHeapRec(v);
	// buildHeap(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} cout << endl;

}

// 4, 1, 3, 7, 8, 17, 2, 9, 10
// 20 10 8 9 1 5 6 4
