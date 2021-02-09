#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int currSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++) {
		currSum += a[i];

		if (currSum < 0) currSum = 0;
		maxSum = max(maxSum, currSum);
	}

	cout << maxSum << endl;

}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

}
