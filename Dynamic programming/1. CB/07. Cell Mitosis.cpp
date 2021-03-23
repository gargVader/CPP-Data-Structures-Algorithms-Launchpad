#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 200005;
int dp[N];
int x, y, z, n;
// dp[n] =  Cost to generate n cells
int minCost(int n) {

	// cout << n << endl;
	// Base Case
	if (n == 1) {
		return 0;
	}

	// Lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (n % 2 == 0) {
		op1 = minCost(n / 2) + x;
		op2 = minCost(n - 1) + y;
		// I will not take op3 as n+1 will be odd, as it will definitely
		// take more steps. Reason being that from n+1, I cannot divide 2.
		// Either I have to subtract 1 and again come back to the same pos which
		// is redundant or I can again go one step forward to n+2. Between n and n+2,
		// n will obviously take lesser steps.
	} else {
		op2 = minCost(n - 1) + y;
		op3 = minCost((n + 1) / 2) + z + x;
	}

	//cout << op1 << " " << op2 << " " << op3 << endl;

	return dp[n] = min(op1, min(op2, op3));
}

int minCostBottomUp() {

	dp[0] = 1;
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
		} else {
			dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + z + x);
		}
	}

	return dp[n];

}


signed main() {

	cin >> n;
	cin >> x >> y >> z;
	memset(dp, -1, sizeof(dp));

	cout << minCost(n) << endl;
	cout << minCostBottomUp() << endl;
}
