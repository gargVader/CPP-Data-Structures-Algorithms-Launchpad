#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n; cin >> n;
	string s = "";
	while (n) {
		s += to_string(n % 8);
		n /= 8;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}
