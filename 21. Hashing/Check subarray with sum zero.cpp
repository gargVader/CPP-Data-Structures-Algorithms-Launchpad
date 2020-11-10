#include <iostream>
#include<set>
using namespace std;
// O(n)
// Subarray will have zero sum if any two values in the prefix sum is zero
// or anyone value is same

int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	unordered_set<int> s;
	s.insert(a[0]);

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];

		if (a[i] == 0 || s.find(a[i]) != s.end()) {
			cout << "Yes" << endl;
			return 0;
		}

		s.insert(a[i]);

	}
	cout << "No" << endl;


}
