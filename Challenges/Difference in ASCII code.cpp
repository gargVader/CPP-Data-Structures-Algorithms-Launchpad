#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	string s; cin >> s;
	cout << s[0];
	for (int i = 1; i < s.size(); i++) {

		cout << (s[i] - s[i - 1]);
		cout << s[i];
	}

}
