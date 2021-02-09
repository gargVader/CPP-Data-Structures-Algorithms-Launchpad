#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int target; cin >> target;

	sort(a, a + n);

	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		int rem = target - a[i];
		while (l < r) {
			int sum = a[l] + a[r];

			if (sum == rem) {
				cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
				l++, r--;
			} else if (sum > rem) {
				r--;
			} else {
				l++;
			}


		}
	}

}
