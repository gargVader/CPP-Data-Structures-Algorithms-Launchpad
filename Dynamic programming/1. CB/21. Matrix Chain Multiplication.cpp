/*
Matrix Chain Multiplication
===========================
Given a sequence of matrices, find the least number of multiplications
required to compute the matrix multiplication

Sample input:
5
40 20 30 10 30

Sample output:
26000

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
#include<bits/stdc++.h>
#define int long long
#define MAX 1000
using namespace std;

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

int dp[MAX][MAX];
int minOps(int a[], int n, int s, int e) {
	// Base Case
	if (s == e) {
		return 0;
	}

	int val = INT_MAX;
	for (int k = s; k < e; k++) {
		int curr = minOps(a, n, s, k) + minOps(a, n, k + 1, e);
		curr += a[s] * a[k + 1] * a[e + 1];
		val = min(val, curr);
	}
	return dp[s][e] = val;
}

int minOpsBottomUp(int a[], int n) {
	int dp[n][n] = {0};

	// Initiase diagonals with 0
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int d = 1; d <= n - 2; d++) {

		for (int i = 1; i < n; i++) {
			int j = i + d;

			if (i < n && j < n) {
				// cout << i << " " << j << endl;
				int ans = INT_MAX;
				for (int k = i; k < j; k++) {
					int curr = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k + 1 - 1] * a[j + 1 - 1];
					ans = min(ans, curr);
				}
				dp[i][j] = ans;
			}
		}
	}

	// for (int i = 1; i < n; i++) {
	// 	for (int j = 1; j < n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }

	return dp[1][n - 1];
}

signed main() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// cout << minOps(a, n, 0, n - 2) << endl;
	cout << minOpsBottomUp(a, n) << endl;
}