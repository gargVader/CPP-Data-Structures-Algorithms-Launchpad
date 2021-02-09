#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void sort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int curr = arr[i];
		while (j >= 0 and arr[j] > curr) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = curr;
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
		cout << a[i] << " ";
	}
}
