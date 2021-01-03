#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
using namespace std;

/*
NOTES TO SELF:
	1. Edge Cases (n=1,0)
	2. Sort before applying binary search
	3. Check for -1 index accessing
*/

void solve() {

	int s = 1, e = 1e6;
	int ans;
	while (s <= e) {
		int mid = (s + e) / 2;
		cout << mid << endl;
		string r; cin >> r;

		if (r == "<") {
			e = mid - 1;
		} else {
			s = mid + 1;
			ans = mid;
		}
	}

	cout << "! " << ans << endl;

}

signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
}
