#include<iostream>
using namespace std;

// Top down
int fib(int n, int dp[]) {
	cout << n << endl;
	// Base Case
	if (n == 0 || n == 1) {
		return n;
	}

	// Lookup
	if (dp[n] != 0) {
		return dp[n];
	}

	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

}

// Bottom up



int main() {
	int n = 4;
	int dp[10000] = {0};
	cout << fib(10, dp) << endl;
}