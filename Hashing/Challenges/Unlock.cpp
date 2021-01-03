#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	unordered_map<int, int> indexOf;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		indexOf[a[i]] = i;
	}


	for (int num = n; num >= 1; num--) {
		if (k == 0) break;
		int bestPos = n - num;
		int currPos = indexOf[num];
		//cout << "IndexOf " << n << "=" << indexOf[n] << " n-num=" << n - num << endl;
		if (currPos != bestPos) {

			int num2 = a[bestPos];

			// update map
			indexOf[num] = bestPos;
			indexOf[num2] = currPos;

			// update array
			a[bestPos] = num;
			a[currPos] = num2;

			k--;
		}
	}

	// for (auto p : indexOf) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}

