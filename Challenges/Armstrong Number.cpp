#include <bits/stdc++.h>
#define int long long
using namespace std;

int powr(int a, int b) {
	int res = 1;
	while (b) {

		if (b & 1) {
			res *= a;
		}

		a *= a;
		b = b >> 1;

	}
	return res;
}

signed main() {

	int n; cin >> n;
	int sz = to_string(n).size();
	int n_copy = n;
	int a[10] = {0};

	for (int i = 0; i <= 9; i++) a[i] = powr(i, sz);

	int sum = 0;

	while (n) {
		sum += a[n % 10];
		n /= 10;
	}

	if (sum == n_copy) {
		cout << "true";
	} else {
		cout << "false";
	}


}
