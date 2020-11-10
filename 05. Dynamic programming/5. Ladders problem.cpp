#include<iostream>
#define MAX 1000
using namespace std;

// Time: O(nk)
// Space: O(n) <- Maximum depth of the tree

int numWaysBottomUp(int n, int k) {

	int dp[MAX] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= i - k && j >= 0; j--) {
			dp[i] += dp[j];
		}
	}

	// for (int i = 0; i < 10; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;

	return dp[n];

}


int numWays(int n, int k, int dp[]) {

	// Base Case
	if (n == 0) {
		return 1;
	}

	// Lookup
	if (dp[n] != 0) {
		return dp[n];
	}

	//cout << n << endl;
	for (int i = 1; i <= k; i++) {
		if (n >= i) {
			dp[n] += numWays(n - i, k, dp);
		} else {
			break;
		}
	}

	return dp[n];

}

// dp[6] = sum of last k elements
int numWaysOptimised(int n, int k) {

	int dp[MAX] = {0};
	dp[0] = 1, dp[1] = 1;

	int csum = 0;
	for (int i = 2; i <= k; i++) {
		// My approach:
		// csum += dp[i - 1];
		// dp[i] = csum;

		// Easier Approach
		dp[i] = 2 * dp[i - 1];
	}



	for (int i = k + 1; i <= n; i++) {
		//cout << csum << " " << dp[i - 1] << " " << dp[i - k - 1] << endl;

		// My approach:
		// dp[i] = csum + dp[i - 1] - dp[i - k - 1];
		// csum += dp[i - 1] - dp[i - k - 1];

		// Easier Approach
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];

	}

	// for (int i = 0; i <= n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;

	return dp[n];

}

int main() {
	int n = 10, k = 5;
	int dp[MAX] = {0}; dp[0] = 1;
	cout << numWays(n, k, dp) << endl;
	cout << numWaysBottomUp(n, k) << endl;
	cout << numWaysOptimised(n, k);
}