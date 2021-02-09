#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void sort(int a[], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
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
