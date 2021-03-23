/*
Longest Increasing Subsequence (LIS)
-------------------------------------
eg:
8
1 5 2 3 4 9 6 10

ans -> lis = 6
1 2 3 4 6 10 OR 1 2 3 4 9 10
Time Complexity: O(n^2)
*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100000
using namespace std;

int n;
int a[MAX];
int dp[MAX] = {0};

// dp[i] = length of longest increasing subsequence ending at i
signed main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		int len = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i]) {
				len = max(len, dp[j]);
			}
		}
		dp[i] = 1 + len;
	}

	cout << *(max_element(dp, dp + n)) << endl;
}
