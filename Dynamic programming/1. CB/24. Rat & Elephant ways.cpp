/*
Find the number of ways to reach a particular position from a given
starting point in 2D Grid

1) Rat(Right & Down 1 step)
2) Elephant (Right & Down K steps)
*/

#include<bits/stdc++.h>
#define MAX 1000
#define int long long
using namespace std;

int n, m;
int dp[MAX][MAX];
int numWays(int i, int j, string s) {
	// Base Case
	if (i == n && j == m) {
		cout << s << endl;
		return 1;
	}

	// Lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int val = 0;
	if (i + 1 <= n) val += numWays(i + 1, j, s + 'D');
	if (j + 1 <= m) val += numWays(i, j + 1, s + 'R');
	return dp[i][j] = val;
}

int numWaysBottomUp(int n, int m) {

	int dp[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
	}

	return dp[n - 1][m - 1];
}


// O(n * n^2)
int numWaysElephant(int n, int m) {

	int dp[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			} else {
				int val = 0;

				for (int r = 0; r < i; r++) {
					val += dp[r][j];
				}

				for (int c = 0; c < j; c++) {
					val += dp[i][c];
				}

				dp[i][j] = val;
			}
		}
	}
	return dp[n - 1][m - 1];
}


signed main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	// cin >> k;
	// cout << numWays(1, 1, "") << endl;
	cout << numWaysBottomUp(n, m) << endl;
	cout << numWaysElephant(n, m) << endl;

}