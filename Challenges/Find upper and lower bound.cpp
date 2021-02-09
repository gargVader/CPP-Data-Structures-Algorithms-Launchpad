#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q; cin >> q;

	while (q--) {
		int key; cin >> key;
		auto lb = lower_bound(a, a + n, key);
		if (lb != (a + n) && *lb == key) cout << (lb - a) << " ";
		else cout << "-1 ";

		auto up = upper_bound(a, a + n, key);
		up--;
		if (*up == key) cout << (up - a);
		else cout << "-1 ";

		cout << endl;
	}
}
