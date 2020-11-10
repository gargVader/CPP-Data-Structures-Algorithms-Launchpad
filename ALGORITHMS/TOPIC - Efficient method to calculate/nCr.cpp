#include <iostream>
#define int long long
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

signed main() {

	int a[] = {100000, 500, 6, 2};
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++) {
		cout << nCr(a[i], 2) << " ";
	} cout << endl;

}
