#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int currSum = 0, maxSum = 0;

	for (int i = 0; i < n; i++) {
		int num = (-1) * a[i];
		currSum += num;

		if (currSum < 0) currSum = 0;
		maxSum = max(maxSum, currSum);
	}
	int ans1 = sum + maxSum;
	currSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++) {
		currSum += a[i];

		if (currSum < 0) currSum = 0;
		maxSum = max(maxSum, currSum);
	}

	cout << max(ans1, maxSum) << endl;

}

int main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

}
