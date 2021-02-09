#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second > b.second;

}

signed main() {

	int x; cin >> x;

	int n; cin >> n;

	vector<pair<string, int>> v;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int n; cin >> n;
		if (n >= x)
			v.pb({s, n});
	}

	sort(v.begin(), v.end(), cmp);

	for (auto p : v) {
		cout << p.first << " " << p.second << endl;
	}



}
