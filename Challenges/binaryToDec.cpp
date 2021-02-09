#include <bits/stdc++.h>
using namespace std;

int main() {

	string s; cin >> s;

	int p = 1;
	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			ans += p;
		}

		p *= 2;
	}

	cout << ans << endl;
}
