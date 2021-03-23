/*
Count number of binary strings
===============================
You are provided an integers N. You need to count all possible
distinct binary strings of length N such that there are no consecutive 1’s.
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int numStrings(int n, int prev, int dp[][2]) {
	// Base Case
	if (n == 0) {
		return 1;
	}

	// Lookup
	if (dp[n][prev] != -1) {
		return dp[n][prev];
	}

	int op = numStrings(n - 1, 0, dp);
	if (prev != 1) {
		op += numStrings(n - 1, 1, dp);
	}

	return dp[n][prev] = op;
}

void solve(int n) {
	int dp[n + 1];

	dp[0] = 1;
	dp[1]  = 2;

	for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << endl;
}

signed main() {

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		// solve(n);

		int dp[n + 1][2];
		memset(dp, -1, sizeof(dp));

		cout << numStrings(n, 0, dp) << endl;


	}

}

