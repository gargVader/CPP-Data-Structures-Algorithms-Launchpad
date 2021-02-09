#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve() {

	string a, b;
	cin >> a >> b;

	string res = "";
	int i;
	for (i = 0; i < a.size() && b.size(); i++) {
		if (a[i] != b[i]) res += '1';
		else res += '0';
	}

	for (; i < a.size(); i++) {
		res += '1';
	}

	for (; i < b.size(); i++) {
		res += '1';
	}

	cout << res << endl;



}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

}
