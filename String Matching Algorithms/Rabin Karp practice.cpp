#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int p = 31;

int powr(int a, int b) {

	int ans = 1;

	while (b) {

		if (b & 1LL) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		b = b >> 1;
		a %= mod;
	}

	return ans % mod;
}

// return a^-1

int inv(int a) {

	return powr(a, mod - 2) % mod;
}

int polyHashString(string s) {
	int hash = 0;
	int coef = 1;
	for (int i = 0; i < s.size(); i++) {
		hash += (s[i] - 'a' + 1) * coef;
		coef *= p;
		coef %= mod;
		hash %= mod;
	}
	return hash % mod;
}

signed main() {

	string s = "aaabaaabancsd";
	string pat = "ncs";
	int n = s.size(), m = pat.size();

	int patHash = polyHashString(pat);
	int currHash = polyHashString(s.substr(0, m));

	if (currHash == patHash) {
		cout << 0 << endl;
	}

	// coef for next char
	int coef = powr(p, m - 1);

	for (int i = 1; i <= (n - m); i++) {
		int newHash = currHash;

		// Subtract prev char
		newHash -= s[i - 1] - 'a' + 1;
		newHash += mod; newHash %= mod;

		// divide by prime
		newHash *= inv(p);
		newHash %= mod;

		// Add next char
		newHash += (s[i + m - 1] - 'a' + 1) * coef;
		newHash %= mod;
		if (newHash == patHash) {
			cout << i << endl;
		}

		currHash = newHash;
	}
}
