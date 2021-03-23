/*
2, 1, 7, 3

Two players A and B play in turns. In each turn person
can pick elements from either end. What is the maximum margin
by which A can win?
A goes first.

8
7 3 1 6 2 8 10 11

*/

#include<bits/stdc++.h>
#define int long long
#define MAX 1000
using namespace std;

int dp[MAX][MAX];

// Returns the maximum score that player can have from s...e
int maxScore(int a[], int n, int s, int e) {
	// Base Case
	if (s > e) {
		return 0;
	}

	// Lookup
	if (dp[s][e] != -1) {
		return dp[s][e];
	}

	// Take leftmost
	int op1 = a[s] + min(maxScore(a, n, s + 2, e), maxScore(a, n, s + 1, e - 1));
	// Take rightmost
	int op2 = a[e] + min(maxScore(a, n, s + 1, e - 1), maxScore(a, n, s, e - 2));

	return dp[s][e] = max(op1, op2);
}

signed main() {

	int n; cin >> n;
	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << sum - maxScore(a, n, 0, n - 1) << endl;

}