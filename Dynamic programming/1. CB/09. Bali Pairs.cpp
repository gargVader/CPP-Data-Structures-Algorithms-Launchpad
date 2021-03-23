/*
Problem Name: Bali Pairs
Problem Difficulty: None
Problem Constraints: 1 ≤ N ≤ 10^5

1 ≤ Li,Ri ≤ 10^9

Li ≠ Ri
Problem Description:
College starts at eight in the morning! But Yash Jeswani is awake way before he is
supposed to be. It's a beautiful day for him until he realizes Yash Agarwal took his
shoes and had been away while Jeswani was sleeping. Jeswani is furious with such
irresponsible behaviour. Now, what to do then? So he decides to go to "the Bali"'s shop
to buy new shoes. Now Bali shows him a N pairs of shoes. But these shoes aren't some normal
shoes! These are "the Bali" shoes. The size of left shoe will be always not equal to the size
of the right shoe! Being such close friends Bali agrees to gift him a pair of shoes if he
answers his question. Bali asks what are the total number of ways to select one shoe from
each of the N pairs such that the summation of all the selected shoe sizes is odd? Then do
help Jeswani to get free shoes. Since the answer can be too large print it modulo 10^9+7.

Input Format: First line contains N number of pairs
N lines follows two space separated integer Li Ri representing shoe sizes
Sample Input: 2
1 2
3 4
Output Format: Print number of ways to select one shoe from each of the N pairs such
that the summation of the selected shoe sizes is odd.
Since the answer can be too large print it modulo 10^9+7.
Sample Output: 2
*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
using namespace std;

const int N = 1e+5;
int n;
int a[N][2];
int dp[N];

// Total number of ways to select one shoe from
// each of the N pairs such that the summation of all the selected shoe sizes is odd
// dp[i] = total number of ways for an array starting at i with initial sum = sum
int numWays(int idx, int sum) {
	// Base Case
	if (idx == n) {
		// cout << sum << endl;
		return sum % 2;
	}

	// Lookup
	if (dp[idx] != -1) {
		return dp[idx];
	}

	// Take first shoe
	int op1 = numWays(idx + 1, sum + a[idx][0]);
	// Take second shoe
	int op2 = numWays(idx + 1, sum + a[idx][1]);

	return dp[idx] = (op1 + op2) % mod;
}

// int powr(int a, int b) {
// 	int res = 1;
// 	while (b) {
// 		if (b & 1) {
// 			res *= a;
// 			res %= mod;
// 		}
// 		a *= a;
// 		a %= mod;
// 		b = b >> 1;
// 	}
// 	return res;
// }

signed main() {

	// int oo = 0, ee = 0, oe = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		// if (a[i][0] % 2 && a[i][1] % 2) oo++;
		// else if (a[i][0] % 2 == 0 && a[i][1] % 2 == 0) ee++;
		// else oe++;
	}


	// if (oe == 0) {
	// 	if (oo % 2 == 0) {
	// 		// this gives me even
	// 		cout << "0" << endl;
	// 	} else {
	// 		// this gives me odd
	// 		cout << powr(2, n) << endl;
	// 	}

	// 	// ee will always give me even no matter their
	// 	// freq

	// } else {

	// }


	cout << numWays(0, 0) << endl;
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	} cout << endl;
}
