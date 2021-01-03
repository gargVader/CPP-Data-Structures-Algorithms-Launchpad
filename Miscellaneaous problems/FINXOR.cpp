#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void query(int n) {
	cout << "1 " << n << endl;
}

void solve() {

	//int n; cin>>n;
	int a[] = {1, 1, 1};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v;

	for (int i = 0; i < 20; i++) {
		int num = 1 << i;

		int temp = 0;
		for (int j = 0; j < n; j++) {
			temp += a[j] xor num;
		}
		v.pb(temp);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << __builtin_popcount(v[i]) << endl;
	}

	int xors = 0;
	for (int i = 0; i < n; i++) {
		xors ^= a[i];
	}
	cout << xors << " set bits in ans = " << __builtin_popcount(xors) << endl;

}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		solve();
	}
}

/*
NOTES TO SELF:
	1. Use ll
	2. Array Bounds
	3. Edge Cases (n=1,0)
	4. Sort before applying binary search
*/
