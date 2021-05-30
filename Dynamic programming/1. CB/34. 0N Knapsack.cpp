#include<bits/stdc++.h>
#define int long long
#define INF 1e18
#define pb 	push_back
#define MAX 1005
using namespace std;

int n, cap;
int wt[MAX], val[MAX];
int dp[MAX][MAX];

// Returns the max val for arr starting from idx
int maxVal(int idx, int cap) {

	// Base Case
	if (idx == n || cap <= 0) {
		return 0;
	}

	// Lookup
	if (dp[idx][cap] != -1) {
		return dp[idx][cap];
	}


	int op1 = INT_MIN, op2 = INT_MIN;
	// Take idxth item
	if (cap >= wt[idx])
		op1 = maxVal(idx, cap - wt[idx]) + val[idx];
	op2 = maxVal(idx - 1, cap);

	return dp[idx][cap] = max(op1, op2);


}

signed main() {

	memset(dp, -1, sizeof(dp));
	cin >> n >> cap;

	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	cout << maxVal(0, cap);


}