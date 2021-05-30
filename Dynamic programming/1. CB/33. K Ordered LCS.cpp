/*
Problem Name: K-Ordered LCS
Problem Difficulty: None
Problem Constraints: 1 <= N, M <= 2000 <br>
1 <= k <= 5 <br>
1 <= element in any sequence <= 10<sup>9</sup>
Problem Description:
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter
**k** was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change **atmost**
k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

Input Format: The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
The second line contains
N integers denoting the elements of the first sequence.
The third line contains
M integers denoting the elements of the second sequence.
Sample Input: 5 5 1
1 2 3 4 5
5 3 1 4 2
Output Format: Print the answer in a new line.
Sample Output: 3
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 2005
using namespace std;

int n, m, k;
int a[MAX], b[MAX];

int dp[MAX][MAX][6];

// Returns length of lcs
int lcs(int i, int j, int k) {
	// Base Case
	if (i == n || j == m) {
		return 0;
	}

	// Lookup
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}


	if (a[i] == b[j]) {
		return dp[i][j][k] =  1 + lcs(i + 1, j + 1, k);
	} else {

		int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

		op1 = lcs(i + 1, j, k);
		op2 = lcs(i, j + 1, k);
		if (k >= 1)
			op3 = lcs(i + 1, j + 1, k - 1) + 1;

		return dp[i][j][k] = max({op1, op2, op3});
	}
}

signed main() {

	memset(dp, -1, sizeof(dp));

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	cout << lcs(0, 0, k) << endl;
}
