#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;
int k;
void solve() {

	int n; cin >> n;
	bool a[n + 1] = {0};
	int tsum = 0;
	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 0; j < k; j++) {
			num *= i;
		}
		tsum += num;
		//cout << num << endl;
	}

	// int tsum = (n * (n + 1)) / 2;


	// if (tsum % 2 == 1) {
	// 	cout << "1" << endl;
	// } else {
	// 	cout << "0" << endl;
	// }

	int target = tsum / 2;
	//cout << target << endl;
	int ans = 0;
	for (int i = n; i > 0; i--) {

		int num = 1;
		for (int j = 0; j < k; j++) {
			num *= i;
		}

		if (target >= num) {
			target -= num;
			a[i] = 1;
			ans += num;
		}
		if (target == 0) {
			break;
		}
	}

	ans = abs(tsum - 2 * ans);
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	} cout << endl;

}

signed main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	int t; cin >> t;
	while (t--) {
		solve();
	}
}

/*
NOTES TO SELF:
	1. Use ll
	2. Array Bounds
	3. Edge Cases (n=1,0)
	4. Sort before applying binary search
*/
