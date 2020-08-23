#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

struct compare {
	bool operator()(const pair<int, int>& value, const int& key)
	{
		return (value.first < key);
	}
	bool operator()(const int& key, const pair<int, int>& value)
	{
		return (key < value.first);
	}
};

bool compare2(pair<ll, ll> a, pair<ll, ll> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

void solve() {

	int n; cin >> n;

	vector<pair<ll, ll>> v;

	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		v.pb(make_pair(x, y));
	}

	ll l, p; cin >> l >> p;

	for (int i = 0; i < n; i++) {
		v[i].first = l - v[i].first;
	}

	reverse(v.begin(), v.end());

	v.pb(make_pair(l, 0)); // v.size() = n+1


	for (int i = 0; i <= n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	int curr = -1, count = 0;

	while (curr < n) {
		int pos = upper_bound(v.begin() + curr + 1, v.end(), p, compare()) - v.begin() - 1;
		if (pos == n ) break;
		if (pos == curr) {
			cout << "-1" << endl;
			return;
		}
		cout << "pos=" << pos << " ";
		// I will only choose the max fuel st from curr -> pos. Then set curr to that position.
		sort(v.begin() + curr + 1, v.begin() + pos + 1, compare2);
		curr = pos; p += v[pos].second;

		cout << v[pos].first << " " << v[pos].second << " p=" << p << endl;

		count++;
	}

	cout << count << endl;


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
