#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int solve(int h[], int n, int idx, int dp[]) {

	//cout << idx << endl;
	// Base Case
	if (idx == n - 1) {
		return 0;
	}

	// Lookup
	if (dp[idx] != -1) {
		return dp[idx];
	}

	int op1 = INT_MAX, op2 = INT_MAX;

	// Take one step
	if (idx + 1 < n)
		op1 = solve(h, n, idx + 1, dp) + abs(h[idx] - h[idx + 1]);
	// Take two steps
	if (idx + 2 < n)
		op2 = solve(h, n, idx + 2, dp) + abs(h[idx] - h[idx + 2]);

	return dp[idx] = min(op1, op2);

}

int main() {

	int n; cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int dp[MAX];
	memset(dp, -1, sizeof(dp));
	cout << solve(h, n, 0, dp) << endl;

}
