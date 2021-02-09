#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// Returns whether a configuration is possible
// where the minimum distance between the cows is
// mid

bool isPoss(int a[], int n, int c, int mid) {

	int last = 0;
	int placed = 1;
	for (int i = 1; i < n; i++) {

		if (a[i] - a[last] >= mid) {
			last = i;
			placed++;
		}
	}

	return placed >= c;


}

signed main() {

	int n, c; cin >> n >> c;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	// Min dist should be as large as possible
	int ans = 0;
	int s = 0, e = INT_MAX;

	while (s <= e) {

		int mid = (s + e) / 2;
		if (isPoss(a, n, c, mid)) {
			s = mid + 1;
			ans = max(ans, mid);
		} else {
			e = mid - 1;
		}

	}

	cout << ans << endl;



}
