#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n; cin >> n;
	int a[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	reverse(a, a + n);

	int m; cin >> m;
	int b[m] = {0};
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	reverse(b, b + m);

	vector<int> v;
	int sz = max(n, m);

	int sum = 0;
	for (int i = 0; i < n || sum || i < m; i++) {
		if (i < n)
			sum += a[i];
		if (i < m)
			sum += b[i];

		v.pb(sum % 10);

		sum = sum / 10;
	}

	reverse(v.begin(), v.end());

	for (auto x : v) {
		cout << x << ", ";
	}

	cout << "END";


}


