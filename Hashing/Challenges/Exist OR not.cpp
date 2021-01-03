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

	int n; cin >> n;
	int a[n];
	unordered_map<int, int> isPresent;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		isPresent[x] = 1;
	}

	int q; cin >> q;

	for (int i = 0; i < q; i++) {
		int x; cin >> x;
		if (isPresent[x]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}



}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}
}
