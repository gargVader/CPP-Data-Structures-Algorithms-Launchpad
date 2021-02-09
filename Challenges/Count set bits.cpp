#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		cout << (__builtin_popcount(n)) << endl;
	}
}
