/*
Problem Name: Box Stacking Problem
Problem Difficulty:
Problem Constraints: 1 <= T <= 100
1 <= N <= 100
1 <= l,w,h <= 1000000
Problem Description:
Given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. Create a stack of boxes which is as tall as possible. However, you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to write a program to find the maximum Height by any possible arrangements of the boxes.

Input Format: The first line contains an integer T denoting the no of test cases.

For every test case:
First line contains an integer N denoting the total no of boxes available. Second line contains 3*N space separated values denoting the height, width and length of the N boxes.
Sample Input: 2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1
Output Format: For every test case, print the maximum height possible with the given boxes.
Sample Output: 60
15
*/



#include<bits/stdc++.h>
#define int long long
#define INF 1e18
#define pb 	push_back
using namespace std;

int n;
vector<tuple<int, int, int>> v;

int maxHeight(int idx) {

	// Base Case
	if (idx == n) {

	}

}

void solve() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int h, w, l;
		cin >> h >> w >> l;
		v.pb({h, w, l});
	}
}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

}