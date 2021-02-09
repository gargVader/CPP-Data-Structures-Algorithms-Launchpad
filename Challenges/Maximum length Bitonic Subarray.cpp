#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int b[n] = {0};

	for (int i = 1; i < n; i++) {
		b[i] = a[i] - a[i - 1];
		//cout << b[i] << " ";
	}
	// cout << endl;

	vector<int> v;
	int pos = 0, neg = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] >= 0) {
			if (neg) {
				v.pb(neg * (-1));
				neg = 0;
			}
			pos++;
		} else {
			if (pos) {
				v.pb(pos);
				pos = 0;
			}
			neg++;
		}
	}

	if (pos) v.pb(pos);
	if (neg) v.pb(neg * (-1));

	// for (auto x : v) {
	// 	cout << x << " ";
	// } cout << endl;

	int ans = 1;
	for (int i = 0; i < v.size() - 1; i++) {

		if (v[i] > 0 && v[i + 1] < 0) {
			ans = max(ans, v[i] + abs(v[i + 1]));
		}
	}

	for (auto x : v) {
		ans = max(ans, abs(x));
	}

	cout << ans + 1 << endl;
}

signed main() {


	int t; cin >> t;
	while (t--) {
		solve();
	}



}
