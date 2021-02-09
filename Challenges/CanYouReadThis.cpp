#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	string s; cin >> s;

	string res = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == toupper(s[i])) {
			if (res == "") {
				res += s[i];
			} else {
				cout << res << endl;
				res = s[i];
			}
		} else {
			res += s[i];
		}
	}

	if (res != "") {
		cout << res << endl;
	}

}
