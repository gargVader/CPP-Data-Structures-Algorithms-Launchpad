#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void solve() {

	ll n; cin >> n;

	ll a[MAX];

	for (ll i = 1; i <= n; i++) {
		string s; cin >> s;
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += abs(i - a[i]);
	}

	cout << ans << endl;

}

int main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
