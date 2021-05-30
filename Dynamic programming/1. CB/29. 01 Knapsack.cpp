#include<bits/stdc++.h>
#define int long long
#define MAX 1005
using namespace std;

int n, capacity;
int wt[MAX], val[MAX];

int dp[MAX][MAX];

// Returns the max value that I can have if I start
// from the index = idx and capacity = curr_c
int maxVal(int idx, int curr_c) {

	// Base Case
	if (idx == n) {
		return 0;
	}

	if (curr_c <= 0) {
		return 0;
	}

	// Lookup
	if (dp[idx][curr_c] != -1) {
		return dp[idx][curr_c];
	}


	int op1 = INT_MIN, op2 = INT_MIN;
	// Take the idxth item
	if (curr_c >= wt[idx]) {
		op1 = maxVal(idx + 1, curr_c - wt[idx]) + val[idx];
	}
	// Reject the idxth item
	op2 = maxVal(idx + 1, curr_c);

	return dp[idx][curr_c] = max(op1, op2);
}

int maxValBottomUp() {

	int dp[n + 1][capacity + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= capacity; j++) {
			// I have j capacity
			int op1 = INT_MIN, op2 = INT_MIN;
			// Take the ith item
			if (j >= wt[i - 1])
				op1 = dp[i - 1][j - wt[i - 1]] + val[i - 1];

			op2 = dp[i - 1][j];
			dp[i][j] = max(op1, op2);
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}

	return dp[n][capacity];
}

signed main() {

	memset(dp, -1, sizeof(dp));

	cin >> n >> capacity;
	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	cout << maxVal(0, capacity) << endl;
	cout << maxValBottomUp() << endl;

}

/*

5 4
1 2 3 2 2
8 4 0 5 3

*/