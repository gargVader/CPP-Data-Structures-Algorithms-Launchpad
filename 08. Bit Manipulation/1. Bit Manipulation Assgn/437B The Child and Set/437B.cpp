#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;
vector<int> a;

int low_bit(int num) {
	return num & (-num);
}

void solve(int sum, int limit) {

	for (int i = limit; i >= 1; i--) {
		int lb = low_bit(i);
		if (sum >= lb) {
			sum -= lb;
			a.pb(i);
		}
		if (sum == 0) break;
	}

	if (sum != 0) {
		cout << "-1" << endl;
		return;
	}

	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	} cout << endl;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum, limit; cin >> sum >> limit;
	solve(sum, limit);
}
