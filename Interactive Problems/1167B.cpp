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

void query(int i, int j) {
	cout << "? " << i << " " << j << endl;
}


void assign(int a[], int x, int y, int z) {
	a[1] = x;
	a[2] = y;
	a[3] = z;
}

void solve() {
	set<int> s {4, 8, 15, 16, 23, 42};
	int a[7] = {0};

	query(1, 2);
	int num1; cin >> num1;
	int temp1, temp2;
	for (auto x : s) {
		if (num1 % x == 0 && s.find(num1 / x) != s.end()) {
			temp1 = x;
			temp2 = num1 / x;
		}
	}

	query(2, 3);
	int num2; cin >> num2;
	int temp3, temp4;
	for (auto x : s) {
		if (num2 % x == 0 && s.find(num2 / x) != s.end()) {
			temp3 = x;
			temp4 = num2 / x;
		}
	}

	if (temp1 == temp3) {
		assign(a, temp2, temp1, temp4);
	} else if (temp1 == temp4) {
		assign(a, temp2, temp1, temp3);
	} else if (temp2 == temp3) {
		assign(a, temp1, temp2, temp4);
	} else {
		assign(a, temp1, temp2, temp3);
	}

	query(4, 4);
	cin >> num1;
	a[4] = sqrt(num1);

	query(5, 5);
	cin >> num2;
	a[5] = sqrt(num2);

	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		sum += a[i];
	}

	a[6] = 108 - sum;
	cout << "! ";
	for (int i = 1; i < 7; i++) {
		cout << a[i] << " ";
	} cout << endl;



}

signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
}
