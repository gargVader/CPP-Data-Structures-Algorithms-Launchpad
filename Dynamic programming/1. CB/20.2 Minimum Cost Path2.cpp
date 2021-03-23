/*
Grid Based DP
==============
Common variants -
1) Find the minimum/maximum cost path in a grid
2) Find the number of ways to reach a particular position from a given
starting position in 2d grid


Starting from 0,0 can only go down or right. Minimum cost to reach R, C
*/

#include<bits/stdc++.h>
#define int long long
#define MAX 1000
using namespace std;
int a[MAX][MAX];
int n;

int minCost(int R, int C) {

	// cost[i][j] = minimum cost to reach (i, j)
	// (i,j) can only be reached from (i-1, j) and (i, j-1)
	int cost[n][n] = {0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == 0 && j == 0) {
				cost[i][j] = a[i][j];
				continue;
			} else if (i == 0) {
				cost[i][j] = cost[i][j - 1] + a[i][j];
			} else if (j == 0) {
				cost[i][j] = cost[i - 1][j] + a[i][j];
			} else {
				cost[i][j] = min(cost[i][j - 1], cost[i - 1][j]) + a[i][j];
			}
		}
	}
	return cost[R][C];

}

signed main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	cout << minCost(x, y) << endl;

}