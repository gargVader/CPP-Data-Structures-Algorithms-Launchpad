#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n; cin >> n;
	int a[n];
	int x = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		x ^= num;
	}

	cout << x << endl;



}
