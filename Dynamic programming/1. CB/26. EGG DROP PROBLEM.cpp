/*
Egg Drop Problem
================
Minimum number of moves to find out the critical floor
given that you have n eggs
*/

#include<bits/stdc++.h>
#define int long long
#define MAX 100
using namespace std;

int minMovesBottomUp(int n, int k) {

	int dp[n + 1][k + 1] = {0};

	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
	}

	for (int j = 1; j <= k; j++) {
		dp[1][j] = 1;
	}

	// eggs
	for (int j = 2; j <= k; j++) {
		// num of floors
		for (int i = 2; i <= n; i++) {
			int ans = INT_MAX;
			for (int x = 1; x <= i; x++) {
				// drop from xth floor
				// op1: break
				int op1 = 1 + dp[x - 1][j - 1];
				// op2: survive
				int op2 = 1 + dp[i - x][j];
				ans = min(ans, max(op1, op2));
			}

			dp[i][j] = ans;
		}
	}

	return dp[n][k];

}

signed main() {
	int n, k; cin >> n >> k;
	cout << minMovesBottomUp(n, k) << endl;

}