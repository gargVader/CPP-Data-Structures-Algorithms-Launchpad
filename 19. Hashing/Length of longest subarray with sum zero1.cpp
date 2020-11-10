// Length of the longest subarray with sum zero

#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main() {

	int n; cin >> n;
	int a[n];

	// prefix_sum, first_occ indx
	map<int, vector<int>> mp;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	mp[a[0]].push_back(0);

	int ans = 0;

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];

		if (a[i] == 0) {
			ans = max(ans, i + 1);
		} else if (mp[a[i]].size() == 0) {
			mp[a[i]].push_back(i);
		} else {
			ans = max(ans, i - mp[a[i]].back());
		}

	}

	cout << ans << endl;

}
