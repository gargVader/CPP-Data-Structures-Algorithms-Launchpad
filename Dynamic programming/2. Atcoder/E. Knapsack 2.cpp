#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
using namespace std;
int n, W;
int *weight, *value;

// dp[index][value] = min weight for subproblem (index, capacity)

int maxVal() {

	int dp[n + 1][MAX] = {0};

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= W; j++) {

			int op1 = INT_MIN, op2 = INT_MIN;

			if (j >= weight[i]) {
				op1 = value[i] + dp[i + 1][j - weight[i]];
			}
			op2 = dp[i + 1][j];

			dp[i][j] = max(op1, op2);
		}
	}

	int val = INT_MIN;

	for (int i = 0; i < n;  i++) {
		for (int j =	)
		}

}

signed main() {

	cin >> n >> W;

	weight = new int[n];
	value = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}

	cout << maxVal() << endl;


}
