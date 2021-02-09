#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n; cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.pb({x, i});
	}

	int key; cin >> key;

	sort(v.begin(), v.end());

	int s = 0, e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (key == v[mid].first) {
			cout << v[mid].second;
			return 0;
		} else if (v[mid].first > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}

	}

	cout << "-1";
}
