#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

set<pair<int, int>> s;

void numPaths(int m, int n) {

	int dp[m + 1][n + 1];
	memset(dp, -1, sizeof(dp));

	for (auto p : s) {
		dp[p.first][p.second] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == -1) {
				if (i == 1 && j == 1) {
					dp[i][j] = 1;
				} else {
					int val = 0;
					if (i != 1) {
						val += dp[i - 1][j];
						val %= mod;
					}
					if (j != 1) {
						val += dp[i][j - 1];
						val %= mod;
					}
					dp[i][j] = val;
				}
			}
		}
	}
	cout << dp[m][n] << endl;
}

signed main() {
	int m, n;
	cin >> m >> n;
	int p; cin >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		s.insert({x, y});
	}

	numPaths(m, n);
}