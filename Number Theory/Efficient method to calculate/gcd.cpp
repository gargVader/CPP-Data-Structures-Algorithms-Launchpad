#include <iostream>
#define int long long
using namespace std;

// O(Log min(a, b))
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}


signed main() {

	int a[] = {100000, 500, 6, 0};
	int n = sizeof(a) / sizeof(a[0]);
	int b = 2;
	for (int i = 0; i < n; i++) {
		ans = (a[i] > b) ? gcd(a[i], b) : gcd(b, a[i]);
		cout << ans << " ";
	}


}
