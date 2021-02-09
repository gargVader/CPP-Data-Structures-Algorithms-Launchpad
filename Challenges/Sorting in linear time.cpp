#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void sort(int a[], int n) {

	int low = 0, mid = 0, high = n - 1;

	while (mid <= high) {


		if (a[mid] == 1) {
			mid++;
		} else if (a[mid] == 0) {
			swap(a[mid], a[low]);
			low++;
			mid++;
		} else {
			swap(a[mid], a[high]);
			high--;
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
