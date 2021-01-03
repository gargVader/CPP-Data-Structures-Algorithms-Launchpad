#include <bits/stdc++.h>
#define int long long
using namespace std;
// Hashing takes O(n)
int polyHashString(string s) {
	int prime = 31, mod = 1e9 + 7;
	int n = s.size();
	int hash = 0;
	int p = 1;

	for (int i = 0; i < n; i++) {
		hash += (s[i] - 'a' + 1) * p;
		p *= prime;
		p %= mod;
		hash %= mod;
	}

	return hash;
}

signed main() {

	string s = "abaxyzab";

	cout << polyHashString(s) << endl;

}
