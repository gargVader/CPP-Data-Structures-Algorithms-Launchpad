#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

bool cmp(string a, string b) {

	if (a.size() < b.size()) {
		if (b.substr(0, a.size()) == a) {
			return false;
		}
	} else if (b.size() < a.size()) {
		if (a.substr(0, b.size()) == b) {
			return true;
		}
	}

	return a <= b;

}

signed main() {

	int n; cin >> n;
	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.pb(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}

}
