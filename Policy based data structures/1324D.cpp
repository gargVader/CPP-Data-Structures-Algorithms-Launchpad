#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
using namespace std;

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

/*
NOTES TO SELF:
	1. Edge Cases (n=1,0)
	2. Sort before applying binary search
	3. Check for -1 index accessing
*/

void solve() {

	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> v;

	for (int i = 0; i < n; i++) {
		v.pb(a[i] - b[i]);
	}

	sort(v.begin(), v.end());

	int i = 0, j = v.size() - 1;
	int count = 0;
	while (i < j) {
		if (v[i] + v[j] > 0) {
			count += (j - i);
			j--;
		} else {
			i++;
		}
	}

	cout << count << endl;






}

signed main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

}
