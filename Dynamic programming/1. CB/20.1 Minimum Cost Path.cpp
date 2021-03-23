/*
Given a cost matrix and position (m, n). Write a function that returns
the minimum cost to reach (m, n) from (0, 0). You can only traverse
downm right and diagonally lower cells from a given cell.

*/

#include<bits/stdc++.h>
#define int long long
#define MAX 1000
using namespace std;
int a[MAX][MAX];
int dp[MAX][MAX];
int n;
int minCost(int m, int n) {

	// Base Case
	if (m == 0 && n == 0) {
		return a[m][n];
	}

	// Lookup
	if (dp[m][n] != -1) {
		return dp[m][n];
	}


	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (m - 1 >= 0) op1 = minCost(m - 1, n);
	if (n - 1 >= 0) op2 = minCost(m, n - 1);
	if (m - 1 >= 0 && n - 1 >= 0) op3 = minCost(m - 1, n - 1);

	return dp[m][n] = min(op1, min(op2, op3)) + a[m][n];
}

signed main() {

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	cout << minCost(x, y) << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	}
}

/*
3
1 2 3
4 8 2
1 5 3
2 2
*/