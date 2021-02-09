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

	if (n == 0) {
		cout << "0" << endl;
		return 0;
	}

	vector<int> mx1(n, 0), mx2(n, 0);
	mx1[0] = a[0];
	mx2[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		mx1[i] = max(mx1[i - 1], a[i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		mx2[i] = max(mx2[i + 1], a[i]);
	}

	int ans = 0;

	for (int i = 1; i < n - 1; i++) {
		// int leftMax = mx1[i - 1];
		// int rightMax = mx2[i + 1];
		// ans += max(min(leftMax, rightMax) - a[i], 0LL);

		int leftMax = mx1[i];
		int rightMax = mx2[i];
		ans += min(leftMax, rightMax) - a[i];
	}

	cout << ans << endl;

}
