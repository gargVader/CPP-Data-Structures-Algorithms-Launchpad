#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int solve(int h[], int n, int k, int idx, int dp[]) {

	//cout << idx << endl;
	// Base Case
	if (idx == n - 1) {
		return 0;
	}

	// Lookup
	if (dp[idx] != -1) {
		return dp[idx];
	}

	int ans = INT_MAX;
	for (int i = 1; i <= k ; i++) {
		if (idx + i < n) {
			// Take i steps
			int op = solve(h, n, k, idx + i, dp) + abs(h[idx] - h[idx + i]);
			ans = min(ans, op);
		}
	}

	return dp[idx] = ans;
}

int main() {

	int n, k; cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int dp[MAX];
	memset(dp, -1, sizeof(dp));
	cout << solve(h, n, k, 0, dp) << endl;

}
