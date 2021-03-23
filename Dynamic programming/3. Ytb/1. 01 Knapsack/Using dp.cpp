/*
Given weights and values of n items, put these items in a
knapsack of capacity w to get the maximum total value
in knapsack
*/

#include<bits/stdc++.h>
using namespace std;

int a = 0, b = 0;

int knapsack(int wt[], int price[], int w, int n) {
	a++;
	// Base Case
	if (n == 0 || w == 0) {
		return 0;
	}

	int op1 = 0, op2 = 0;

	if (wt[n - 1] <= w) {
		op1 = knapsack(wt, price, w - wt[n - 1], n - 1) + price[n - 1];
	}
	op2 = knapsack(wt, price, w, n - 1);

	return max(op1, op2);
}

// Using memoization
int knapsackOptimised(int wt[], int price[], int w, int n, int dp[][500]) {
	b++;
	// Base Case
	if (n == 0 || w == 0) {
		return 0;
	}

	int op1 = 0, op2 = 0;

	if (wt[n - 1] <= w) {
		// Lookup
		if (dp[w - wt[n - 1]][n - 1] == -1) {
			dp[w - wt[n - 1]][n - 1] = knapsackOptimised(wt, price, w - wt[n - 1], n - 1, dp);
		}
		op1 = dp[w - wt[n - 1]][n - 1] + price[n - 1];
	}

	if (dp[w][n - 1] == -1) {
		// Lookup
		dp[w][n - 1] = knapsackOptimised(wt, price, w, n - 1, dp);
	}
	op2 = dp[w][n - 1] ;

	return dp[w][n] = max(op1, op2);
}

int knapsackBottomUp(int wt[], int price[], int w, int n) {

	int dp[w + 1][n + 1];

	// Base Case/Initialisation
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
		}
	}

	for (int i = 1; i < w; i++) {
		for (int j = 1; j < n; j++) {

		}
	}

}


int main() {

	int wt[] = {1, 2, 3, 4, 5, 7, 6};
	int price[] = {40, 20, 35, 100, 10, 20, 93};
	int n = sizeof(wt) / sizeof(wt[0]);
	int w = 7;

	int dp[500][500];
	memset(dp, -1, sizeof(dp));

	cout << knapsack(wt, price, w, n) << " " << a << endl;
	cout << knapsackOptimised(wt, price, w, n, dp) << " " << b << endl;

}
