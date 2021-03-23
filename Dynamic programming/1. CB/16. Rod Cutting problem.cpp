#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

// Gives me the max price that I can get by selling rod of length n optimally
int maxPrice(int n, int price[], int cost, int dp[]) {

	// Base Case
	if (n == 0) {
		return cost;
	}

	// Look up
	if (dp[n] != 0) {
		return dp[n];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// I assume that selling i length will be optimal
		int op = maxPrice(n - i, price, cost, dp) + price[i];
		ans = max(ans, op);
	}
	dp[n] = ans;
	return ans;
}


int maxPriceBottomUp(int price[], int n) {

	int dp[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		// I am trying to sell rod of length = i
		int ans = INT_MIN;

		// I try to break the rod into j, i-j
		// j, I can get from dp[]
		// i-j length I will sold singly
		for (int j = 0; j < i; j++) {
			int op = dp[j] + price[i - j];
			ans = max(ans, op);
		}

		dp[i] = ans;
	}

	return dp[n];

}



int main() {
	int n = 9;
	int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};

	int dp[MAX] = {0};

	cout << maxPrice(n, price, 0, dp) << endl;

	// prints the dp array
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	} cout << endl;
	cout << maxPriceBottomUp(price, n) << endl;
}