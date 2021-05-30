/*
Problem Constraints: 1 < N <= 10000 , N is always even<br>
0 <= A<sub>i</sub> <= 1000000
Problem Description:
Piyush and Nimit are playing a coin game. They are given n coins with values x<sub>1</sub>, x<sub>2</sub> .... x<sub>n</sub> where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format: First line contains the number of coins 'n'. <br>Second line contains n space separated integers where ith index denotes the value of ith coin.
Sample Input: 4
1 2 3 4
Output Format: Print a single line with the maximum possible value that Piyush can win with.
Sample Output: 6

*/

#include<bits/stdc++.h>
#define int long long
#define MAX 100
using namespace std;

int n;
int a[MAX];

int dp[MAX][MAX];

int maxVal(int i, int j) {

	// Base Case
	if (i > j) return 0;

	// Lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int op1 = a[i] + min(maxVal(i + 1, j - 1), maxVal(i + 2, j));
	int op2 = a[j] + min(maxVal(i + 1, j - 1), maxVal(i, j - 2));

	return dp[i][j] = max(op1, op2);
}

signed main() {

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << maxVal(0, n - 1);



}