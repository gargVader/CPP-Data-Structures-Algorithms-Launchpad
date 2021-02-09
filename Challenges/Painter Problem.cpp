#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// find the minimum time taken to paint all
// the boards

// returns whether a configuration is possible such
// that the time taken to paint n boards = time
bool isPoss(int a[], int n, int k, int t, int time) {

	int sum = 0;
	int painterUsed = 1;

	for (int i = 0; i < n; i++) {

		if (sum + a[i]*t > time) {
			painterUsed++;
			sum = a[i] * t;

			if (painterUsed > k) return 0;

		} else {
			sum += a[i] * t;
		}

	}
	return 1;

}

signed main() {

	int n, k, t; cin >> n >> k >> t;

	int a[n];
	int sum = 0;
	// size of n boards
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i] * t;
	}



	int s = a[n - 1] * t, e = sum;
	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;
		//cout << mid << endl;
		if (isPoss(a, n, k, t, mid)) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	cout << ans << endl;

}
