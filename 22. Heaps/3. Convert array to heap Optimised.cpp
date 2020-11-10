// O(n)
// Bottom to top

#include <iostream>
#include<vector>
using namespace std;

// For maxHeap
bool cmp(int a, int b) {
	return a > b;
}

void print(vector<int> v) {
	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << " ";
	} cout << endl;
}

void heapify(vector<int> &v, int idx) {
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int ans_idx = idx;

	if (left < v.size() && !cmp(v[ans_idx], v[left])) {
		ans_idx = left;
	}

	if (right < v.size() && !cmp(v[ans_idx], v[right])) {
		ans_idx = right;
	}

	// Base Case
	if (ans_idx == idx) return;

	swap(v[idx], v[ans_idx]);
	heapify(v, ans_idx);

}

void buildHeap(vector<int> &v) {

	for (int i = v.size() / 2; i >= 1; i--) {
		cout << v[i] << endl;
		heapify(v, i);
		print(v);
	}

}

int main() {

	vector<int> v{ -1, 10, 20, 5, 6, 1, 8, 9, 4};

	buildHeap(v);

	print(v);
}
