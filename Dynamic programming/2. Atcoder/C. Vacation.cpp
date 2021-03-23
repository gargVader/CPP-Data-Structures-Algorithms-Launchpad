#include <bits/stdc++.h>
using namespace std;

int maxHappines(int a[], int b[], int c[], int task[], int n, int idx) {
	// Base Case
	if (idx == n) {
		//cout << 0 << endl;
		return 0;
	}

	int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

	if (idx - 1 >= 0) {
		// Task A
		if (task[idx - 1] != 1) {
			task[idx] = 1;
			op1 = maxHappines(a, b, c, task, n, idx + 1) + a[idx];
		}
		// Task B
		if (task[idx - 1] != 2) {
			task[idx] = 2;
			op2 = maxHappines(a, b, c, task, n, idx + 1) + b[idx];
		}
		// Task C
		if (task[idx - 1] != 3) {
			task[idx] = 3;
			op3 = maxHappines(a, b, c, task, n, idx + 1) + c[idx];
		}
	} else {

		// Task A
		task[idx] = 1;
		op1 = maxHappines(a, b, c, task, n, idx + 1) + a[idx];

		// Task B
		task[idx] = 2;
		op2 = maxHappines(a, b, c, task, n, idx + 1) + b[idx];

		// Task C
		task[idx] = 3;
		op3 = maxHappines(a, b, c, task, n, idx + 1) + c[idx];
	}
	//cout << max(op1, max(op2, op3)) << endl;
	return max(op1, max(op2, op3));

}

int maxHappinesOpt(int a[], int b[], int c[], int n, int idx, int prev, int dp[][4]) {
	// Base Case
	if (idx == n) {
		return 0;
	}

	// Lookup
	if (dp[idx][prev] != 0) {
		return dp[idx][prev];
	}

	int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

	// Task A
	if (prev != 1) {
		op1 = maxHappinesOpt(a, b, c, n, idx + 1, 1, dp) + a[idx];
	}
	// Task B
	if (prev != 2) {
		op2 = maxHappinesOpt(a, b, c, n, idx + 1, 2, dp) + b[idx];
	}
	// Task C
	if (prev != 3) {
		op3 = maxHappinesOpt(a, b, c, n, idx + 1, 3, dp) + c[idx];
	}

	return dp[idx][prev] = max(op1, max(op2, op3));


}

int main() {

	int n; cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int task[n] = {0};
	// cout << maxHappines(a, b, c, task, n, 0) << endl;
	int dp[n][4];
	memset(dp, 0, sizeof(dp));
	cout << maxHappinesOpt(a, b, c, n, 0, 0, dp) << endl;
}
