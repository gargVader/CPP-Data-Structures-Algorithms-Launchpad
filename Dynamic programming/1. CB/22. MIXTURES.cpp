#include<bits/stdc++.h>
#define int long long
#define mod 100
using namespace std;

int pre[1000] = {0};
int dp[1000][1000];

int minSmoke(int a[], int n, int s, int e) {
	// Base Case
	if (s == e) return 0;

	// lookup
	if (dp[s][e] != -1) {
		return dp[s][e];
	}

	int ans = INT_MAX;
	for (int k = s; k < e; k++) {

		int val = minSmoke(a, n, s, k) + minSmoke(a, n, k + 1, e);

		int x = pre[k];
		int y = (s - 1 > 0) ? pre[s - 1] : 0;
		int z = pre[e];
		int w = pre[k];

		val += ((x - y) % mod ) * ((z - w) % mod);
		ans = min(ans, val);
	}
	return dp[s][e] = ans;
}

int minSmokeBottomUp(int a[], int n) {

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	// dp[i][j] = minimum smoke after combining i....j bottles

	for (int d = 1; d <= n - 1; d++) {
		for (int i = 0; i < n; i++) {
			int j = i + d;
			if (i < n && j < n) {

				// Compute dp[i][j]
				int ans = INT_MAX;
				for (int k = i; k < j; k++) {
					int val = dp[i][k] + dp[k + 1][j];
					int x = pre[k];
					int y = (i > 0) ? pre[i - 1] : 0;
					int z = pre[j];
					int w = pre[k];

					val += ((x - y) % mod ) * ((z - w) % mod);
					ans = min(ans, val);
				}
				dp[i][j] = ans;
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }

	return dp[0][n - 1];
}

signed main() {

	int n;

	while (cin >> n) {
		memset(dp, -1, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		int a[n];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		pre[0] = a[0];
		for (int i = 1; i < n; i++) {
			pre[i] += pre[i - 1] + a[i];
		}

		// cout << minSmoke(a, n, 0, n - 1) << endl;
		cout << minSmokeBottomUp(a, n) << endl;

	}

}