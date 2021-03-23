/*
Problem Name: SUPW
Problem Difficulty:
Problem Constraints: N < = 1000000
Problem Description:
In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.


Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.


Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

Input Format: A single integer N, the number of days in the future for which SUPW data is available.

 N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.


Sample Input: 10
3 2 1 1 2 3 1 3 2 1
Output Format: The output consists of a single non-negative integer, the minimum number of minutes that Nikhil needs to spend on SUPW duties this term


Sample Output: 4
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int minWork(int a[], int n, int idx, int streak, int dp[][3]) {
	// Base Case
	if (idx == n) {
		return 0;
	}

	// Lookup
	if (dp[idx][streak] != -1) {
		return dp[idx][streak];
	}

	int op1 = INT_MAX, op2 = INT_MAX;
	// reject idxth work
	if (streak < 2)
		op1 = minWork(a, n, idx + 1, streak + 1, dp);
	// take idxth work
	op2 = minWork(a, n, idx + 1, 0, dp) + a[idx];

	return dp[idx][streak] = min(op1, op2);
}

int minWorkBottomUp(int a[], int n) {
	int dp[n + 1];

	if (n < 3) return a[n - 1];

	// dp[i] = minimum work to be done to reach here
	dp[0] = a[0];
	dp[1] = a[1];
	dp[2] = min(min(a[0], a[1]), a[2]);

	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + a[i];
	}

	return dp[n];
}

int minWorkBottomUpOptimised(int a[], int n) {
	if (n < 3) return a[n - 1];

	int x = a[0];
	int y = a[1];
	int z = a[2];
	int ans;
	for (int i = 3; i <= n; i++) {

		ans = min(x, min(y, z)) + a[i];

		z = y;
		y = x;
		x = ans;
	}

	return ans;

}

signed main() {

	int n; cin >> n;
	int a[n + 1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int dp[n][3];

	memset(dp, -1, sizeof(dp));

	cout << minWork(a, n, 0, 0, dp) << endl;
	cout << minWorkBottomUp(a, n) << endl;
	cout << minWorkBottomUpOptimised(a, n) << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	// }

}