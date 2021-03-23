/*
Find the maximum sum that can be formed from a subarray
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int ans = 0;
int maxSum(int a[], int n, int dp[]) {

	// Base Case
	if (n == 0) return 0;

	// Lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	int sum = maxSum(a, n - 1, dp);

	if (sum + a[n] > 0) {
		sum += a[n];
		ans = max(ans, sum);
	}

	return dp[n] = sum;
}

int maxSumBottomUp(int a[], int n) {
	int dp[n] = {0};
	dp[0] = max(0LL, a[0]);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = a[i] + dp[i - 1];
		ans = max(ans, dp[i]);
		if (dp[i] < 0) dp[i] = 0;
	}
	return ans;
}

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int dp[n];
	memset(dp, -1, sizeof(dp));

	maxSum(a, n - 1, dp);
	cout << ans << endl;

	cout << maxSumBottomUp(a, n);
}

/*
10
-3 2 5 -1 6 3 -2 7 -5 2
*/
