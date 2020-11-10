// Length of the longest subarray with sum K

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {

	int n, k; cin >> n >> k;
	int a[n];

	// prefix_sum, first_occ indx
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	mp[a[0]] = 0;

	int ans = 0;

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];

		if (a[i] == k) {
			ans = max(ans, i + 1);
		}

		// if (mp.find(a[i] + k) != mp.end()) {
		// 	ans = max(ans, i - mp[a[i] + k]);
		// }

		if (mp.find(a[i] - k) != mp.end()) {
			ans = max(ans, i - mp[a[i] - k]);
		}

		// mp.find(a[i] + k) == mp.end() &&

		if ( mp.find(a[i] - k) == mp.end()) {
			// New element seen
			mp[a[i]] = i;
		}

	}

	cout << ans << endl;

}
