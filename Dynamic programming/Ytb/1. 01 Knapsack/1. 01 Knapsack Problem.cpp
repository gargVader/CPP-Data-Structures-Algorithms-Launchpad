/*
Given weights and values of n items, put these items in a
knapsack of capacity w to get the maximum total value
in knapsack
*/

#include<bits/stdc++.h>
#define MAX 500
using namespace std;

// max value in knapsack
int solve(int wt[], int price[], int n, int w, int idx) {

	//Base Case
	if (idx == n) {
		return 0;
	}

	int op1 = INT_MIN, op2 = INT_MIN;

	// Take the item
	if (w >= wt[idx]) {
		op1 = solve(wt, price, n, w - wt[idx], idx + 1) + price[idx];
	}
	// Reject the item
	op2 = solve(wt, price, n, w, idx + 1);

	return max(op1, op2);
}


int solveOpt(int wt[], int price[], int n, int w, int idx, int dp[][MAX]) {

	//Base Case
	if (idx == n) {
		return 0;
	}

	// Lookup
	if (dp[idx][w] != 0) {
		return dp[idx][w];
	}

	int op1 = INT_MIN, op2 = INT_MIN;

	// Take the item
	if (w >= wt[idx]) {
		op1 = solveOpt(wt, price, n, w - wt[idx], idx + 1, dp) + price[idx];
	}
	// Reject the item
	op2 = solveOpt(wt, price, n, w, idx + 1, dp);

	return dp[idx][w] = max(op1, op2);
}

int solveOpt2(int wt[], int price[], int n, int w) {

	int dp[MAX][MAX];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= w; j++) {
			int op1 = INT_MIN, op2 = INT_MIN;

			// curr_w -> j, curr_idx -> i

			int curr_w  = j, curr_idx = i;

			// Take the item
			if (curr_w >= wt[curr_idx]) {
				op1 = dp[curr_idx + 1][curr_w - wt[curr_idx]] + price[curr_idx];
			}
			// Reject the item
			// Move on to the next idx without reducing w
			op2 = dp[curr_idx + 1][curr_w];

			dp[curr_idx][curr_w] = max(op1, op2);

			cout << i << " " << j << " " << wt[i] << " " << op1 << " " << op2 << " dp[" << curr_idx << "][" << curr_w << "]=" << max(op1, op2) << endl;
		}
	}

	cout << endl;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	} cout << endl;

	//cout << dp[0][0] << endl;

	return dp[0][w];

}

int main() {

	int wt[] = {1, 1, 1, 1, 1};
	int price[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
	int n = sizeof(wt) / sizeof(wt[0]);
	int w = 5;

	cout << solve(wt, price, n, w, 0) << endl;

	int dp[MAX][MAX] = {0};
	cout << solveOpt(wt, price, n, w, 0, dp) << endl;

	cout << solveOpt2(wt, price, n, w);

}
