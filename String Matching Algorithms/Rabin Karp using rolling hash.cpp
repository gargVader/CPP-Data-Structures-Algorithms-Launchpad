#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int p = 31;

int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1LL) {
			res *= a;
			res %= mod;
		}

		a *= a;
		a %= mod;
		b = b >> 1;
	}
	return res;
}

int inv(int a) {
	return powr(a, mod - 2);
}

int polyHashString(string s) {

	int hash = 0;
	int p_powr = 1;

	for (int i = 0; i < s.size(); i++) {
		hash += p_powr * (s[i] - 'a' + 1);
		p_powr *= p;
		p_powr %= mod;
		hash %= mod;
	}
	return hash;

}

signed main() {

	string text = "aaaaaaaaaa";
	string pat = "aaa";

	int pat_hash = polyHashString(pat);

	int n = text.size(), m = pat.size();

	int text_hash = polyHashString(text.substr(0, m));

	bool f = 0;
	if (text_hash == pat_hash) {
		cout << "Yes, found at " << 0 << endl;
		f = 1;
	}

	for (int i = 1; i + m <= n; i++) {

		int new_hash = text_hash;

		new_hash = (new_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

		new_hash *= inv(p);
		new_hash %= mod;


		new_hash = new_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1);
		new_hash %= mod;

		if (new_hash == pat_hash) {
			cout << "Yes, found at " << i << endl;
			f = 1;
		}
		text_hash = new_hash;
	}

	if (!f) {
		cout << "Not found" << endl;
	}

}
