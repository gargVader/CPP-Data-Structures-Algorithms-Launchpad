#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
using namespace std;

/*
NOTES TO SELF:
	1. Edge Cases (n=1,0)
	2. Sort before applying binary search
	3. Check for -1 index accessing
*/

void solve() {

	int a, b, c;
	cin >> a >> b >> c;

	int d = b * b - 4 * a * c;

	if (d < 0) {
		cout << "Imaginary";
	} else {
		d = sqrt(d);
		int x = (-1) * d - b;
		int y = d - b;
		x /= (2 * a);
		y /= (2 * a);

		if (x != y) {
			cout << "Real and Distinct" << endl;
		} else {
			cout << "Real and Equal" << endl;
		}

		if (x >= y) cout << y << " " << x << endl;
		else cout << x << " " << y << endl;

	}

}

signed main() {

	solve();
}
