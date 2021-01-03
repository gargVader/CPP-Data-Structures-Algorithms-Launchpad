#include <iostream>
#define int long long
using namespace std;

int powFast(int b, int n) {

	int p = b, ans = 1;
	while (n) {
		if (n & 1) {
			ans *= p;
		}
		p *= p;
		n = n >> 1;
	}

	return ans;

}


signed main() {

	int a[] = {100000, 500, 6, 0};
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++) {
		cout << powFast(a[i], 2) << " ";
	}


}
