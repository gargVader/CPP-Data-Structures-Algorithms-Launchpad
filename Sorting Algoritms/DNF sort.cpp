/*
DNF Sort
========
Array only contains 0s 1s 2s
O(n)
Does in a single pass
*/

#include <bits/stdc++.h>
using namespace std;

void dnfSort(int a[], int n) {

	int low = 0, mid = 0, high = n - 1;

	while (mid <= high) {

		if (a[mid] == 1) {
			mid++;
		}

		if (a[mid] == 0) {
			swap(a[mid], a[low]);
			low++;
			mid++;
		}

		if (a[mid] == 2) {
			swap(a[mid], a[high]);
			high--;
		}

	}

}

int main() {

	int a[] = {2, 1, 1, 1, 1, 0, 1, 1, 0, 0, 2, 0};
	int n = sizeof(a) / sizeof(a[0]);

	dnfSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} cout << endl;

}
