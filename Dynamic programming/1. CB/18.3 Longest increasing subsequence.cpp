/*
Longest increasing subsequence
==============================
O(n^2)

8
1 5 2 3 4 9 6 10

*/
#include<bits/stdc++.h>
#define int long long
#define MAX 100005
using namespace std;

int n;
int a[MAX];
int dp[MAX];

// dp[i] = element at which the subsequence of length i ends

signed main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}

	for (int i = 0; i < n; i++) {

		// Where can this element be placed?

		int _j = upper_bound(dp, dp + n + 1, a[i]) - dp;
		int j = _j - 1;
		if (dp[j] < a[i] && a[i] < dp[j + 1])
			dp[j + 1] = min(dp[j + 1], a[i]);
	}

	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	} cout << endl;

	for (int i = n; i >= 0; i--) {
		if (dp[i] != INT_MAX) {
			cout << i;
			break;
		}
	}

}