#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

#define watch(x) cout<<(#x)<<"="<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<"="<<(x)<<" and "<<(#y)<< "=" <<(y)<<"\n"

int dp[5005][5005];
int n, m;
vector<int> a, b;

int solve(int i, int j) {

	// cout << i << " " << j << endl;

	// Base Case
	if (i >= n) {
		return 0;
	}

	if (j >= m) {
		return INT_MAX;
	}

	// Lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// Take jth girl
	int op1 = abs(a[i] - b[j]) + solve(i + 1, j + 1);
	// Reject jth girl
	int op2 = solve(i, j + 1);

	// watch2(op1, op2);
	return dp[i][j] = min(op1, op2);
}

signed main() {

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++) { cin >> x; a.pb(x);}
	for (int i = 0; i < m; i++) { cin >> x; b.pb(x);}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << solve(0, 0);
}

/*
2 5
5 6
7 8 10 11 12
2+2 = 4
*/