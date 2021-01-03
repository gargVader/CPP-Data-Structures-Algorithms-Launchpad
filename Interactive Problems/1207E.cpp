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

	cout << "? ";
	for (int i = 1; i <= 100; i++)
		cout << i << " ";
	cout << endl;

	int res1;
	cin >> res1;

	res1 = res1 & (~((1 << 7) - 1));

	cout << "? ";
	for (int i = 1; i <= 100; i++)
		cout << (i << 7) << " ";
	cout << endl;

	int res2;
	cin >> res2;
	res2 = res2 & ((1 << 7) - 1);


	int x = 0;
	x = x | res1;
	x = x | res2;
	cout << "! " << x << endl;

}

signed main() {

	solve();
}
