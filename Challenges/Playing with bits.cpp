#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int q; cin >> q;

	while (q--) {
		int a, b; cin >> a >> b;
		int sum = 0;

		for (int i = a; i <= b; i++) {
			sum += __builtin_popcount(i);
		}

		cout << sum << endl;

	}

}
