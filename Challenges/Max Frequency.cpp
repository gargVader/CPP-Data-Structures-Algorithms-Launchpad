#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	string s; cin >> s;

	map<char, int> mp;

	for (auto c : s) mp[c]++;

	int mx = 0;
	char c;

	for (auto p : mp) {
		if (p.second > mx) {
			mx = p.second;
			c =  p.first;
		}
	}

	cout << c << endl;

}
