#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int numWays(int n, int coins[], int m) {
	//cout << n << endl;
	// Base Case
	if (n == 0) {
		return 1;
	}

	if (n < 0) return 0;

	int res = 0;
	for (int i = 0; i < m; i++) {
		// select the mth coin
		int op1 = numWays(n - coins[i], coins, m);
		// Reject the mth coin
		int op2 = numWays(n, coins, m);
		res += op1 + op2;
	}

	return res;
}

signed main() {

	int n, m;
	cin >> n >> m;

	int coins[m];

	for (int i = 0; i < m; i++) {
		cin >> coins[i];
	}

	cout << numWays(n, coins, m - 1) << endl;

}
