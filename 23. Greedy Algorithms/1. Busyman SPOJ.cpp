#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

void solve() {

	int n; cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;

		v.push_back(make_pair(s, e));

	}

	sort(v.begin(), v.end(), compare);

	// for (int i = 0; i < v.size(); i++) {
	// 	cout << v[i].first << " " << v[i].second << endl;
	// }

	int count = 1, chosen = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].first >= arr[chosen].second) {
			count++;
			chosen = i;
		}
	}

	cout << count << endl;


}

int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		solve();
	}
}
