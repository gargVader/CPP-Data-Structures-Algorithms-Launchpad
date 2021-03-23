/*
Given a set of non-negative integers, and a value sum, determine if
there is a subset of the given set with sum equal to given sum.
*/

#include <iostream>
#define MAX 500
using namespace std;

int solve(int a[], int n, int num, int dp[][MAX], int count) {



	// Base Case
	if (num == 0) {
		return 1;
	}

	if (num < 0) {
		return 0;
	}

	if (n == 0) {
		return 0;
	}

	// Lookup
	if (dp[n][num] != -1) {
		return dp[n][num];
	}

	int count1 = 0, count2 = 0;

	//Take
	count1 = solve(a, n - 1, num - a[n - 1], dp, count);

	//Reject
	count2 = solve(a, n - 1, num, dp, count);

	return dp[n][num] = count + count1 + count2;
}

bool solveOpt2(int a[], int n, int num) {

	bool dp[n + 1][num + 1] = {0};

	// Initialisation
	for (int i = 0; i <= n ; i++) {
		for (int j = 0; j <= num; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i <= n ; i++) {
		for (int j = 0; j <= num; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	} cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= num; j++) {
			bool f1 = 0, f2 = 0;
			//Take
			if (j >= a[i - 1]) {
				f1 = dp[i - 1][j - a[i - 1]];
			}
			//Reject
			f2 = dp[i - 1][j];
			dp[i][j] = f1 | f2;
		}
	}

	for (int i = 0; i <= n ; i++) {
		for (int j = 0; j <= num; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	} cout << endl;

	return dp[n][num];

}

int main() {

	int a[] = {2, 3, 5, 6, 8, 10};
	int n = sizeof(a) / sizeof(a[0]);
	int num = 0;

	int dp[MAX][MAX] = {0};

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j]  = -1;
		}
	}

	cout << solve(a, n, num, dp, 0) << endl;
	//cout << solveOpt2(a, n, num);

}
