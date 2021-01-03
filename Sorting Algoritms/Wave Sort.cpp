/*
Wave Sort
=========
big small big small big small
*/

#include <bits/stdc++.h>
using namespace std;

void convertToWave(int *a, int n) {

	// Your code here
	for (int i = 0; i < n; i += 2) {

		if (i + 1 < n) {
			if (a[i] < a[i + 1]) swap(a[i], a[i + 1]);
		}
		if (i - 1 >= 0) {
			if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);
		}

	}

}

int main() {

	int a[] = {1, 3, 4, 2, 7, 4};
	int n = sizeof(a) / sizeof(a[0]);

	convertToWave(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
