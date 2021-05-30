#include <bits/stdc++.h>
#define int long long
#define MAX 100
#define pb push_back
using namespace std;

/*
dp[i][j] tells us the lcs for two strings starting from the ith and jth
index respectively

Base case is O(1) operation. No need to memoise it.
*/

int lcs(string s1, string s2, int i, int j, vector<vector<int>> dp) {

	// Base Case
	if (i == s1.size() || j == s2.size()) {
		return 0;
	}

	// Lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s1[i] == s2[j]) {
		return dp[i][j] = lcs(s1, s2, i + 1, j + 1, dp) + 1;
	} else {
		return dp[i][j] = max(lcs(s1, s2, i, j + 1, dp), lcs(s1, s2, i + 1, j, dp));
	}
}

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

	string s1, s2; cin >> s1 >> s2;

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n, vector<int>(m, -1));

	cout << lcs(s1, s2, 0, 0, dp) << endl;
	cout << lcsBottomUp(s1, s2) << endl;
	// for (auto v : dp) {
	// 	for (auto x : v) cout << x << " ";
	// 	cout << endl;
	// }

}
/*
oxcpqrsvwf
shmtulqrypy

abcd
abedg
*/