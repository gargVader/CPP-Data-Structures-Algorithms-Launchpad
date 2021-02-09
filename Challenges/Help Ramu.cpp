#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
using namespace std;

/*
NOTES TO SELF:
	1. Edge Cases (n=1,0)
	2. Sort before applying binary search
	3. Check for -1 index accessing
*/

void solve() {

	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;

	int n, m; cin >> n >> m;
	int a[n], b[m];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int cost1 = 0;
	for (int i = 0; i < n; i++) {
		int temp = c1 * a[i];

		if (temp > c2) {
			cost1 += c2;
		} else {
			cost1 += temp;
		}
	}
	if (cost1 > c3) cost1 = c3;

	int cost2 = 0;
	for (int i = 0; i < m; i++) {
		int temp = c2 * b[i];

		if (temp > c2) {
			cost2 += c2;
		} else {
			cost2 += temp;
		}
	}
	if (cost2 > c3) cost2 = c3;

	if (cost1 + cost2 > c4) {
		cout << c4 << endl;
	} else {
		cout << cost1 + cost2 << endl;
	}

}

signed main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
