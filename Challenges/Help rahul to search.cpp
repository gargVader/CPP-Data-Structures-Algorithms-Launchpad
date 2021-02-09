#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int find(int a[], int n, int key) {

	int s = 0, e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key) {
			return mid;
		}

		if (a[mid] > a[s]) {
			// I am at sorted array1
			if (key <= a[mid] && key > a[s]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}

		} else {
			// I am at sorted array2
			if (key >= a[mid] && key <= a[e]) {
				s = mid + 1;
			} else {
				e = mid - 1;
			}

		}

	}

	return -1;

}

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int key; cin >> key;

	cout << find(a, n, key);

}
