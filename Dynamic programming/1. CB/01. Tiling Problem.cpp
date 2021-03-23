/*
Tiling Problem
===============
Given a brick wall of 4*N, and tiles of size 4*1,
you have to find out the total number of ways to
arrange tiles on the wall
*/

#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pb push_back
using namespace std;

int numWays(int n, int m, int dp[]) {

	// Base Case
	if (n == 0 || n == 1) {
		return 1;
	}
	if (n < m) {
		return 1;
	}

	// Lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	int op1 = numWays(n - 1, m, dp);
	int op2 = 0;
	if (n - m >= 0) {
		op2 = numWays(n - m, m, dp);
	}

	return dp[n] = (op1 + op2) % mod;
}

int numWaysBottomUp(int n, int m){

	int dp[n + 1] = {0};

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		dp[i] = dp[i - 1];

		if (i - m >= 0) {
			dp[i] += dp[i - m];
			dp[i] %= mod;
		}
	}
	return dp[n];
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int dp[n + 1];
		memset(dp, -1, sizeof(dp));
		//cout << numWays(n, m, dp) << endl;
		cout << numWaysBottomUp(n, m) << endl;
	}
}
