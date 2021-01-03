// O(nlogn)
#include <iostream>
#include<vector>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} cout << endl;
}

bool maxHeap = 1;
bool cmp(int a, int b) {
	if (maxHeap) return a > b;
	else return a < b;
}

void heapify(int a[], int n, int idx) {
	int left = 2 * idx;
	int right = 2 * idx + 1;
	int ans_idx = idx;

	if (left < n && !cmp(a[ans_idx], a[left])) {
		ans_idx = left;
	}

	if (right < n && !cmp(a[ans_idx], a[right])) {
		ans_idx = right;
	}

	// Base Case
	if (idx == ans_idx) {
		return;
	}

	swap(a[idx], a[ans_idx]);
	heapify(a, n, ans_idx);
}

void buildHeap(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
}

void sort(int a[], int n) {

	// Base Case
	// Array is sorted when only one element is present
	if (n == 0) {
		return;
	}

	swap(a[0], a[n - 1]);
	heapify(a, n - 1, 0);
	sort(a, n - 1);
}

void heapsort(int a[], int n) {
	buildHeap(a, n);

	while (n > 0) {
		swap(a[0], a[n - 1]);
		heapify(a, n - 1, 0);
		// shrink size of heap
		n--;
	}
}

int main() {

	int a[] = { -1, 10, 20, 5, 6, 1, 8, 9, 4};
	int n = sizeof(a) / sizeof(int);

	heapsort(a, n);

	// buildHeap(a, n);
	// sort(a, n);

	print(a, n);
}
