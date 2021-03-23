/*
Given a string s and m queries .
Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not. 

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 100;

int dp[N][N];

bool isPal(string s, int l, int r) {

	// Base Case
	if (r - l <= 1) {
		return s[l] == s[r];
	}

	// Lookup
	if (dp[l][r] != -1) {
		return dp[l][r] == 1;
	}

	return (isPal(s, l + 1, r - 1) && s[l] == s[r]);
}

signed main() {

	string s; cin >> s;
	memset(dp, -1, sizeof(dp));
	int q; cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (isPal(s, l, r)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}
