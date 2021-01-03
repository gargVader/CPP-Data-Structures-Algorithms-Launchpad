#include <bits/stdc++.h>
#define MAX 100005
#define int long long
using namespace std;

// Gives maxVal in knapsack
// of capacity w, when size of wt[] and price[]
int maxVal(int wt[], int value[], int n, int w, int idx, int dp[][MAX]) {

	//cout << w << endl;

	// Base Case
	if (idx == n || w == 0) {
		return 0;
	}

	// Lookup
	if (dp[idx][w] != 0) {
		return dp[idx][w];
	}

	int op1 = INT_MIN, op2 = INT_MIN;

	if (w >= wt[idx]) {
		// Take the item
		op1 = maxVal(wt, value, n, w - wt[idx], idx + 1 , dp) + value[idx];
	}
	// Reject the item
	op2 = maxVal(wt , value, n, w, idx + 1, dp);


	return dp[idx][w] = max(op1, op2);
}

signed main() {

	int n, w; cin >> n >> w;

	int wt[n], value[n];

	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> value[i];
	}

	int dp[n][MAX];
	memset(dp, 0, sizeof(dp));

	cout << maxVal(wt, value, n, w, 0 , dp) << endl;

}
