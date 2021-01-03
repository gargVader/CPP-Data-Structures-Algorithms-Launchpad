#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 40005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void solve() {

	ll w, h, n; cin >> w >> h >> n;

	vector<ll> v1(n + 2, 0), v2(n + 2, 0);

	for (ll i = 1; i <= n; i++) {
		cin >> v1[i] >> v2[i];
	}
	v1[n + 1] = w + 1, v2[n + 1] = h + 1;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ansx = INT_MIN, ansy = INT_MIN;
	for (ll i = 1; i < n + 2; i++) {
		cout << v1[i] - v1[i - 1] - 1 << endl;
		ansx = max(ansx, v1[i] - v1[i - 1] - 1);
	}

	for (ll i = 1; i < n + 2; i++) {
		ansy = max(ansy, v2[i] - v2[i - 1] - 1);
	}

	cout << ansx*ansy << endl;
}

int main() {

	int t; cin >> t;
	while (t--) {
		solve();
	}
}
