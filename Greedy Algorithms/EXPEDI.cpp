#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

bool compare(pair<ll, ll> a, pair<ll, ll> b ) {
	return a.first < b.first;
}

void solve() {

	ll n; cin >> n;

	vector<pair<ll , ll>> v;

	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.pb(make_pair(x, y));
	}

	ll l, p; cin >> l >> p;

	reverse(v.begin(), v.end());

	for (ll i = 0; i < n; i++) {
		v[i].first = l - v[i].first;
	}

	v.pb(make_pair(l, 0));

	for (ll i = n; i > 0; i--) {
		v[i].first = v[i].first - v[i - 1].first;
	}

	ll curr = p;
	for (ll i = 0; i <= n; i++) {
		curr -= v[i].first;
		if (curr >= 0) {
			curr += v[i].second;
		}

		if (curr < 0 && i != n) {
			cout << "-1" << endl;
			return;
		}
	}

	for (ll i = 0; i <= n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}



}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		solve();
	}
}
