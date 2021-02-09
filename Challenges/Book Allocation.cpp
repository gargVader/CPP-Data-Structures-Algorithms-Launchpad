#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// Returns whether it is possible to have a situation where
// the maximum number of pages alloted to a student is less than equal to pages

bool isPoss(int a[], int n, int m, int pages) {

	int sum = 0;
	int studentsUsed = 1;

	for (int i = 0; i < n; i++) {

		if (sum + a[i] > pages) {
			studentsUsed++;
			sum = a[i];

			if (studentsUsed > m) return 0;

		} else {
			sum += a[i];
		}

	}
	return 1;

	// int sum = 0;
	// int i = 0;
	// while (i < n && m) {

	// 	sum += a[i];
	// 	if (sum > pages) {
	// 		sum = 0;
	// 		m--;
	// 		i--;
	// 	}

	// 	i++;

	// }

	// if (i == n && m > 0) return 1;
	// else return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	//cout << isPoss(a, n, m, 113);

	int s = a[n - 1], e = sum;
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPoss(a, n, m, mid)) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	cout << ans << endl;
}

signed main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}
}

/*
1
4 2
12 34 67 90
*/
