#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void sort(int a[], int n) {

	for (int j = n - 1; j >= 0; j--) {

		int idx = 0;
		int mx = INT_MIN;

		// find max number from 0...j
		for (int i = 0; i <= j; i++) {
			if (a[i] >= mx) {
				idx = i;
				mx = a[i];
			}
		}
		// swap it with a[j]
		swap(a[idx], a[j]);
	}

}

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
