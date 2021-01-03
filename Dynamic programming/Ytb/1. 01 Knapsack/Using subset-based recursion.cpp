#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int wt[] = {1, 2, 3, 4};
int price[] = {40, 20, 35, 100};
int n = sizeof(wt) / sizeof(wt[0]);
int w = 7;

int solve(int i, int j, int cwt = 0, int cp = 0) {

	// Base Case
	if (i >= n) {
		return cp;
	}
	cout << i << " " << j << " " << cp << endl;
	// Excluding ith element
	int op1 = solve(i + 1, j, cwt, cp);
	// Including ith element
	int op2 = 0;
	if (cwt + wt[i] <= w ) {
		op2 = solve(i + 1, j + 1, cwt + wt[i], cp + price[i]);
	}
	return max(op1, op2);

}


int main() {

	cout << solve(0, 0, 0, 0);

}
