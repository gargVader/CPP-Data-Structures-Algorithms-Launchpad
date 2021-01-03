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
	return hash % mod;

}

signed main() {


	string text = "aaaaaaaaaaa";
	string pat = "aaa";

	int pat_hash = polyHashString(pat);
	int n = text.size(), m = pat.size();

	int pref[n] = {0};

	for (int i = 0; i < n; i++) {
		pref[i] = (text[i] - 'a' + 1) * powr(p, i);
		pref[i] %= mod;
	}

	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
		pref[i] %= mod;
	}


	for (int i = 0; i <= (n - m); i++) {
		// substring from s[l.......r]
		// r = i+m - 1
		int l = i;
		int r = i + m - 1;

		int new_hash = pref[r];

		if (i - 1 >= 0) {
			new_hash -= pref[l - 1];
		}

		new_hash += mod; new_hash %= mod;

		if (new_hash == (pat_hash * powr(p, l)) % mod) {
			cout << i << endl;
		}

	}

}
