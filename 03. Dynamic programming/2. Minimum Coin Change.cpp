#include<iostream>
#include <climits>
#define MAX 100005
using namespace std;

int minChangeBottomUp(int coins[], int numCoins, int n) {

	int dp[MAX] = {0};

	for (int i = 1; i <= n; i++) {

		int ans = INT_MAX;

		for (int j = 0; j < numCoins; j++) {
			if (coins[j] > i) continue;
			int temp = dp[i - coins[j]] + 1;
			ans = min(ans, temp);
		}

		dp[i] = ans;

	}

	return dp[n];
}


int minChange(int coins[], int numCoins, int n, int dp[]) {

	// Base Case
	if (n == 0) {
		return 0;
	}

	// Lookup
	if (dp[n] != 0) {
		return dp[n];
	}


	int ans = INT_MAX;

	for (int i = 0; i < numCoins; i++) {
		if (coins[i] > n) continue;

		int temp = minChange(coins, numCoins, n - coins[i], dp) + 1;
		ans = min(temp, ans);
	}

	return dp[n] = ans;


}

int main() {
	int coins[] = {1, 7, 10};
	int numCoins = sizeof(coins) / sizeof(coins[0]);
	int n = 15;
	int dp[MAX] = {0};
	cout << minChange(coins, numCoins, n, dp) << endl;
	cout << minChangeBottomUp(coins, numCoins, n) << endl;
}