/*
Partition problem is to determine
whether a given set can be partitioned into two subsets
such that the sum of elements in both subsets is the same.
*/

#include <iostream>
using namespace std;

#include <iostream>
#define MAX 500
using namespace std;

bool solve(int a[], int n, int num, int dp[][MAX]) {

	// Base Case
	if (num == 0) {
		return 1;
	}

	if (n == 0) {
		return 0;
	}

	// Lookup
	if (dp[n][num] != -1) {
		return dp[n][num];
	}

	//Take
	if (num >= a[n - 1]) {
		bool f1 = solve(a, n - 1, num - a[n - 1], dp);
		if (f1) return dp[n][num] = 1;
	}
	//Reject
	bool f2 = solve(a, n - 1, num, dp);
	if (f2) return dp[n][num] = 1;
	return dp[n][num] = 0;
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

	int a[] = {1, 5, 3};
	int n = sizeof(a) / sizeof(a[0]);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	if (sum % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	sum /= 2;

	int dp[MAX][MAX] = {0};

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j]  = -1;
		}
	}

	cout << solve(a, n, sum, dp) << endl;
	cout << solveOpt2(a, n, sum);

}
