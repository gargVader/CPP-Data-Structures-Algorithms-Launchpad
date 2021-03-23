/*
Given a set of non-negative integers, determine the minimum
possible subset sum difference.
*/

#include <iostream>
#define MAX 500
using namespace std;

int solve(int a[], int n) {

	// Base Case
	if (n == 0) {
		return 0;
	}

	// Take
	int sum1 = solve(a, n - 1) + a[n - 1];
	// Reject
	int sum2 = solve(a, n - 1);

	return

}


int main() {

	int a[] = {3, 1, 3};
	int n = sizeof(a) / sizeof(a[0]);

	int dp[MAX][MAX] = {0};

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j]  = -1;
		}
	}

	cout << minSubSumDiff(a, n) << endl;


}
