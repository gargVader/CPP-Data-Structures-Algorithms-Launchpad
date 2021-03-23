/*
Given n friends, each one can remain single or can be paired up
with some other friend. Each friend can be paired only once. Find
out the total number of ways in which friends can remain single or can be paired up.

*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int nCr(int n, int r) {
	if (r > n) return 0;
	if (r * 2 > n) r = n - r;
	if (r == 0) return 1;
	int ans = n;
	for (int i = 2; i <= r; i++) {
		ans *= (n - i + 1);
		ans /= i;
	}
	return ans;
}

int makeP(int n) {
	int res = 1;
	for (int i = n - 1; i >= 0; i -= 2) {
		res *= i;
	}
	return res;
}

// dp[i]  = Number of ways in which i ppl can either pair up or remain
// single
int numOfWays(int n, int dp[]) {

	// Base Case
	if (n == 1 || n == 0) {
		return 1;
	}

	// Lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	// Remain single
	int op1 = numOfWays(n - 1, dp);

	// Pair Up
	int op2 = (n - 1) * numOfWays(n - 2, dp);

	//cout << op1 << " " << op2 << endl;

	return dp[n] = op1 + op2;
}

signed main() {

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		// int dp[n / 2 + 1] = {0};
		// dp[0] = 1;
		// for (int p = 1; 2 * p <= n; p++) {
		// 	int numElements = p * 2;
		// 	// Ways to choose numElements from n elements
		// 	int numWays = nCr(n, numElements);
		// 	// Ways to make p pairs out of p*2 people

		// 	dp[p] = numWays * makeP(numElements);
		// 	//cout << numWays << endl;
		// 	dp[p] += dp[p - 1];
		// }

		// cout << dp[n / 2] << endl;

		int dp[n + 1];
		memset(dp, -1, sizeof(dp));

		cout << numOfWays(n, dp) << endl;

	}

}

