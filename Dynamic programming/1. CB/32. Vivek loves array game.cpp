/*
Problem Constraints: 1 <= T <= 10
1 <= N <= 17000
0 <= A[i] <= 10^9
Problem Description:
Vivek loves to play with array . One day Vivek just came up with a new array game which was introduced to him by his friend Ujjwal. The rules of the game are as follows:

    Initially, there is an array, A , containing 'N' integers.

    In each move, Vivek must divide the array into  two non-empty contiguous parts such that the sum of the elements in the left part is equal  to the sum of the elements in the right part. If Vivek can make such a move, he gets '1' point; otherwise, the game ends.

    After each successful move, Vivek have to discards either the left part or the right part and continues playing by using
the remaining partition as array 'A'.

Vivek loves this game and wants your help getting the best score possible. Given  'A', can you find and print the maximum number of points he can score?

Input Format: First line of input contains an integer T denoting number of test cases.
Each further Test case contains first line an integer 'N' , the size of array 'A'.
After that 'N' space separated integers denoting the elements of array.
Sample Input: 3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1
Output Format: For each test case, print Vivek's maximum possible score on a new line.
Sample Output: 0
2
3

*/

#include<bits/stdc++.h>
#define int long long
#define MAX 10000
using namespace std;

int dp[MAX][MAX];
int pre1[MAX] = {0};
int pre2[MAX] = {0};


// returns the number of points for a[s....e]
int solve(int a[], int n, int s, int e) {

	// Base Case
	if (s > e) return 0;

	// Lookup
	if (dp[s][e] != -1) {
		return dp[s][e];
	}

	for (int i = s; i < e; i++) {
		int s1 = pre1[i] - pre1[s - 1];
		int s2 = pre2[i + 1] - pre2[e + 1];

		if (s1 == s2) {
			// choose left
			int op1 = solve(a, n, s, i);
			int op2 = solve(a, n, i + 1, e);
			return dp[s][e] = max(op1, op2) + 1;
		}
	}

	return dp[s][e] = 0;


}

void soln() {
	memset(dp, -1, sizeof(dp));
	memset(pre1, 0, sizeof(pre1));
	memset(pre2, 0, sizeof(pre2));

	int n; cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		pre1[i] += pre1[i - 1] + a[i];
	}

	for (int i = n; i >= 1; i--) {
		pre2[i] += pre2[i + 1] + a[i];
	}

	cout << solve(a, n, 1, n) << endl;
}

signed main() {

	int t; cin >> t;
	while (t--) {
		soln();
	}


}