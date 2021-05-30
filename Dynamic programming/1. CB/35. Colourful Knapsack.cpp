/*
Problem Name: Colorful Knapsack
Problem Difficulty: None
Problem Constraints: 1 ≤ M ≤ 100
M ≤ N ≤ 100
1 ≤ W[i] ≤ 100
1 ≤ C[i] ≤ M
1 ≤ X ≤ 10000
Problem Description:
You are given N stones, labeled from 1 to N. The i-th stone has the weight W[i]. There are M colors, labeled by integers from 1 to M. The i-th stone has the color C[i] (of course, an integer between 1 to M, inclusive).
You want to fill a Knapsack with these stones. The Knapsack can hold a total weight of X. You want to select exactly M stones; one of each color. The sum of the weights of the stones must not exceed X. Since you paid a premium for a Knapsack with capacity X (as opposed to a Knapsack with a lower capacity), you want to fill the Knapsack as much as possible.
Write a program that takes all the above values as input and calculates the best way to fill the Knapsack - that is, the way that minimizes the unused capacity. Output this unused capacity. See the explanation of the sample test cases for clarity.

Input Format: The first line contains three integers, N, M and X, separated by single space. The next line contains N integers, W[1], W[2], W[3] … W[N], separated by single space. The next line contains N integers C[1], C[2], C[3] … C[N], separated by single space.
Sample Input: 9 3 10
1 3 5 1 3 5 1 3 5
1 1 1 2 2 2 3 3 3
Output Format: An optimal way of filling the Knapsack minimizes unused capacity. There may be several optimal ways of filling the Knapsack. Output the unused capacity of the Knapsack (a single integer on a line by itself) for an optimal way. If there is no way to fill the Knapsack, output -1.

Sample Output: 1
*/
#include<bits/stdc++.h>
#define int long long
#define INF 1e18
#define pb 	push_back
#define MAX 105
using namespace std;

int n, m, x;
int wt[MAX];
vector<vector<int>> v(MAX);

int dp[MAX][10004];

// idx -> color
// cap -> curr capacity
int maxWt(int idx, int cap) {

	// Base Case
	if (idx > m || cap <= 0) {
		return 0;
	}

	// Lookup
	if (dp[idx][cap] != -1) {
		return dp[idx][cap];
	}

	// I have taken one stone of each color from
	// 0 ... idx-1
	int op = INT_MIN;
	for (int i = 0; i < v[idx].size(); i++) {
		// Take it and reject others from this group
		if (cap >= v[idx][i])
			op = max(op, maxWt(idx + 1, cap - v[idx][i]) + v[idx][i]);
	}

	return dp[idx][cap] = op;
}

signed main() {

	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> x;

	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		v[c].pb(wt[i]);
	}

	cout << (x - maxWt(1, x)) << endl;

	// for (int i = 1; i <= m; i++) {
	// 	for (int j = 0; j <= x; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }

}