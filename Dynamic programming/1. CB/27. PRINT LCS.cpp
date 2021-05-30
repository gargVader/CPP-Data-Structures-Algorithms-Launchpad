#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int lcsBottomUp(string a, string b) {
	int n = a.size();
	int m = b.size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				int op1 = dp[i][j - 1];
				int op2 = dp[i - 1][j];
				dp[i][j] = max(op1, op2);
			}

		}
	}

	string res = "";
	int i = n, j = m;

	while (i != 0 && j != 0) {
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else {
			res += a[i - 1];
			i--, j--;
		}
	}

	reverse(res.begin(), res.end());
	cout << res << endl;

	return dp[n][m];
}

signed main() {


	string a, b;
	cin >> a >> b;
	lcsBottomUp(a, b);
}
