#include<iostream>
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

int main() {
	int n = 4;
	int price[] = {0, 1, 3, 2, 5};

	int dp[MAX] = {0};

	cout << maxPrice(n, price, 0, dp) << endl;

	// prints the dp array
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	} cout << endl;
}