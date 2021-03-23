#include<iostream>
#include<climits>
#define MAX 100005
using namespace std;


// Bottom Up: Iterative
int minStepsBottomUp(int n) {

	int dp[MAX] = {0};

	for (int i = 2; i <= n; i++) {

		int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

		if (i % 3 == 0) op1 = dp[i / 3] + 1;
		if (i % 2 == 0) op2 = dp[i / 2] + 1;
		op3 = dp[i - 1] + 1;

		dp[i] = min(op1, min(op2, op3));
	}

	return dp[n];

}

// Top Down: Recursive approach with memoisation
int minSteps(int n, int dp[]) {

	// Base Case
	if (n == 1 || n == 2 || n == 3) {
		return 1;
	}

	// Lookup
	if (dp[n] != 0) {
		return dp[n];
	}

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (n % 3 == 0) {
		op1 = minSteps(n / 3, dp) + 1;
	}

	if (n % 2 == 0) {
		op2 = minSteps(n / 2, dp) + 1;
	}

	op3 = minSteps(n - 1, dp) + 1;

	return dp[n] = min(op1, min(op2, op3));


}


int main() {
	int n = 10;
	int dp[MAX] = {0};
	cout << minSteps(n, dp) << endl;
	cout << minStepsBottomUp(n);
}