// Longest Consecutive Subsequence
// Method 3: Hashing
/*
When you insert a new element
- Left expansion
- New streak of length 1
- Right expansion
- Join left and right streaks
*/

// O(n)

#include <iostream>
#include<unordered_map>
using namespace std;

int main() {

	int a[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
	int n = sizeof(a) / sizeof(a[0]);

	// if we use map then, n*logn time required to indert all
	// elements
	unordered_map<int, int> m;

	for (int i = 0; i < n; i++) {
		int x = a[i];

		if (m.count(x - 1) == 0 && m.count(x + 1) == 0) {
			m[x] = 1;
		}
		else if (m.count(x - 1) && m.count(x - 1)) {
			int len1 = m[x - 1];
			int len2 = m[x + 1];

			int newLen = len1 + len2 + 1;

			m[x - len1] = newLen;
			m[x + len2] = newLen;
		} else if (m.count(x - 1) && !m.count(x + 1)) {
			int len = m[x - 1];

			int newLen = len + 1;
			m[x - len] = newLen;
			m[x] = newLen;
		} else {
			int len = m[x + 1];

			int newLen = len + 1;
			m[x + len] = newLen;
			m[x] = newLen;
		}

	}

	int ans = 0;

	for (auto it : m) {
		ans = max(ans, it.second);
	}

	cout << ans << endl;

}
