#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
	if (r > n) return 0;
	if (r * 2 > n) r = n - r;
	if (r == 0) return 1;
	int ans = n;
	for (int i = 2; i <= r; i++) {
		ans *= (n - i + 1);
		ans /= i;
	}
	return ans;
}

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << " "; // added this :
		for (int j = 0; j < (n - i); j++) {
			cout << " ";
		}

		for (int j = 0; j < i; j++) {
			cout << nCr(i - 1, j) << " ";
		}
		cout << endl;
	}
}
