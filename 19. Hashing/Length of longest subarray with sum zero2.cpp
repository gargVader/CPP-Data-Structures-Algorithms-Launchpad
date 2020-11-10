// Length of the longest subarray with sum zero

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {

	int n; cin >> n;
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

		if (a[i] == 0) {
			ans = max(ans, i + 1);
		} else if (mp.find(a[i]) == mp.end()) {
			mp[a[i]] = i;
		} else {
			ans = max(ans, i - mp[a[i]]);
		}

	}

	cout << ans << endl;

}
