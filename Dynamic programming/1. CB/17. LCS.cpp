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

signed main() {

	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n, vector<int>(m, -1));

	cout << lcs(s1, s2, 0, 0, dp);

	for (auto v : dp) {
		for (auto x : v) cout << x << " ";
		cout << endl;
	}

}
