/*
Problem Constraints: 1<=|s1|,|s2|<=2000
s1 and s2 contains only lowercase English letters.
Problem Description:
You are given 2 strings *s1* and *s2*. You can perform the following operations on them:<ol>
<li>Insert a character at any position.
<li>Remove a character from any position.
<li>Replace a character with any other character.
</ol>
Find the minimum number of these operations required to convert *s1* to *s2*.

Input Format: First line contains string *s1*. Second line contains string *s2*.
Sample Input:
abcde
bcdae
Output Format: Print a single integer denoting the minimum number of operations required.
Sample Output: 2


*/

#include<bits/stdc++.h>
#define int long long
#define MAX 100
using namespace std;
string s1, s2;
int dp[MAX][MAX];

int minOps(int i, int j) {

	int n = s1.size();
	int m = s2.size();

	// Base Case
	if (i == n || j == m) {
		return (n + m - i - j);
	}

	// Lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s1[i] == s2[j]) {
		return minOps(i + 1, j + 1);
	}
	// op1: Insert at ith position
	// Insert s2[i] at the ith index
	int op1 = minOps(i, j + 1) + 1;
	// op2: replace at ith position
	int op2 = minOps(i + 1, j + 1) + 1;
	// op3: delete at ith position
	int op3 = minOps(i + 1, j) + 1;

	return dp[i][j] = min({op1, op2, op3});
}

signed main() {
	memset(dp, -1, sizeof(dp));
	cin >> s1 >> s2;

	cout << minOps(0, 0);

}