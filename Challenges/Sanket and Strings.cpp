#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// find the max length substring of equal characters
// when I can change max of K characters

signed main() {

	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;

	int a[n + 1] = {0}, b[n + 1] = {0};

	// prefix array
	for (int i = 1 ; i <= n; i++) {
		if (s[i - 1] == 'a') {
			a[i]++;
		} else {
			b[i]++;
		}

		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}

	int ans = 0;

	for (int i = 0; i <= n; i++) {

		// I can change at most K chars

		// Starting from i, try converting all to a
		int pos1 = upper_bound(b, b + n + 1, b[i] + k) - b;

		// Starting from i, try converting all to b
		int pos2 = upper_bound(a, a + n + 1, a[i] + k ) - a;

		ans = max(max(pos1 - i - 1, pos2 - i - 1), ans);
	}

	cout << ans << endl;




}
