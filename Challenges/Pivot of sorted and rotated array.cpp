// Find the pivot of a sorted and rotated array
// Pivot will be the largest element
// Minimum = a[pivot+1]

// Modified binary search
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int find(int a[], int n) {

	int s = 0, e = n - 1;

	// check if array is already sorted
	if (a[0] <= a[n - 1]) {
		return 0;
	}

	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] > a[mid + 1]) {
			return mid;
		}

		if (a[mid] >= a[s]) {
			// we are in sorted array1
			s = mid + 1;

		} else {
			// we are sorted array2
			e = mid - 1;
		}

	}

	return 0;

}

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << find(a, n);

}
