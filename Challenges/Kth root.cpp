#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// Greatest integer x, such that x^k <=n

int root(int n, int k) {

	int start = 0;
	int end = n;

	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;

		if ((pow(mid, k) <= n)) {
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}

	}

	return ans;

}

void solve() {
	int n, k; cin >> n >> k;

	cout << root(n, k) << endl;

}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}

}
