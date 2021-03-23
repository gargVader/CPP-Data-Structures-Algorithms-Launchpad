#include<bits/stdc++.h>
#define int long long
#define MAX 100005
using namespace std;

// int dp[100][MAX];

bool subsetSum(int a[], int n, int idx, int tr) {
	// Base Case
	if (tr == 0) {
		return 1;
	}

	if (idx == n) {
		return 0;
	}

	// Lookup
	// if (dp[idx][tr] != -1) {
	// 	return dp[idx][tr];
	// }


	// Take a[idx]
	bool f1 = 0, f2 = 0;
	if (a[idx] <= tr) {
		f1 = subsetSum(a, n, idx + 1, tr - a[idx]);
	}
	// Reject a[idx]
	f2 = subsetSum(a, n, idx + 1, tr);

	// return dp[idx][tr] = (f1 || f2);
	return f1 || f2;
}

signed main() {

	int n, tr; cin >> n >> tr;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// memset(dp, -1, sizeof(dp));

	cout << subsetSum(a, n, 0, tr);
}