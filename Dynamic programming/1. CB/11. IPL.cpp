/*
Problem Name: IPL
Problem Difficulty: None
Problem Constraints: N < 1000000
a[i] < 1000
Problem Description:
In IPL 2025, the amount that each player is paid varies from match to match. The match fee depends on the quality of opposition, the venue etc.


The match fees for each match in the new season have been announced in advance. Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.


Nikhil is the captain and chooses the team for each match. He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.

Input Format: Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.
Sample Input: 8
3 2 3 2 3 5 1 3
Output Format: The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL season.
Sample Output: 17
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int maxEarnings(int a[], int n, int idx, int streak, int dp[][3]) {
	// Base Case
	if (idx == n) {
		return 0;
	}

	// Lookup
	if (dp[idx][streak] != -1) {
		return dp[idx][streak];
	}

	int op1 = INT_MIN, op2 = INT_MIN;
	// take idxth earning
	if (streak < 2)
		op1 = maxEarnings(a, n, idx + 1, streak + 1, dp) + a[idx];
	// reject idxth earning
	op2 = maxEarnings(a, n, idx + 1, 0, dp);

	return dp[idx][streak] = max(op1, op2);
}
signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int dp[n][3];

	memset(dp, -1, sizeof(dp));

	cout << maxEarnings(a, n, 0, 0, dp) << endl;

	for (int i = 0; i < n; i++) {
		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}

}