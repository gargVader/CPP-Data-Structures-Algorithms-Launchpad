#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x]++;
	}

	int freq = INT_MIN, ans = 0;

	for (auto p : mp) {
		if (p.second > freq) {
			freq = p.second;
			ans = p.first;
		}
	}

	cout << ans << endl;
}
