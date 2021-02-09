#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n; cin >> n;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}

	sort(a, a + (2 * n));

	cout << a[n - 1];




}
