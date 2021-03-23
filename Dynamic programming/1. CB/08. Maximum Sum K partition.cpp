/*
Problem Name: Max Sum K-Partition
Problem Difficulty: 2
Problem Constraints: 1 ≤ N ≤ 2∗10^6

1 ≤ K ≤ N

−10^9 ≤ Ai ≤ 10^9
Problem Description:
Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham
always comes to his rescue. This is time he has created another samasya
which is as follows. Read carefully! Shubham has an array of N integers
and an integer K. He wants to create a subsequence of this array with
some conditions applied. He builds ceil(N/K) blocks of this array with
size of each block as [i∗K+1,min((i+1)∗k,N)] for 0≤i≤N/K. For two
consecutive integers in this subsequence, he wants the integers to be of
two different blocks. (It is not a compulsion to have one integer from
each block). Also, lets say the indexes of any two integers of this
subsequence be i and j, then he wants |i−j| != K. Shubham takes the sum of
integers in the subsequence. He wonders what can be the maximum sum obtained?
Help shubham in this samasya.

Input Format: First line contains two space separated integers : N and K
Second line contains N space separated integers : A1, A2,…, AN
Sample Input: 6 5
5 4 3 2 1 -1
Output Format: print a single integer describing maximum sum that can be obtained.
Sample Output: 5
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e+5;
int n, k;
int a[N];
int dp[N];

// dp[i] = max sum considering that my array starts from i
int maxSum(int idx, int prev) {

	// Base Case
	if (idx >= n) {
		return 0;
	}

	// Lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	int op = 0;

	for (int i = idx; i < idx + k && i < n; i++) {
		if (prev + k == i) continue;
		// Take a[i] from this segment
		int temp = maxSum(idx + k, i) + a[i];
		op = max(op, temp);
	}
	cout << "dp[" << idx << "]=" << op << endl;
	return dp[idx] = op;
}

signed main() {

	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << maxSum(0, INT_MIN) << endl;



	//cout<<maxSum(5, 0)<<endl;

}
