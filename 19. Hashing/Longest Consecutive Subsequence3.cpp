// Longest Consecutive Subsequence
// Method 4: Using unordered_set
/*
When you insert a new element
- Left expansion
- New streak of length 1
- Right expansion
- Join left and right streaks
*/

// O(n)

#include <iostream>
#include<unordered_set>
using namespace std;

int main() {

	int a[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
	int n = sizeof(a) / sizeof(a[0]);

	unordered_set<int> s;
	for (int i = 0; i < n; i++) s.insert(a[i]);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// Check if element just less than a[i] is present
		// or not. If not then a[i] is the starting of streak
		if (s.find(a[i] - 1) == s.end()) {
			//starting of streak
			int count = 1;
			int num = a[i];
			while (s.find(a[i] + 1) != s.end()) {
				a[i]++;
				count++;
			}
			ans = max(ans, count);
		}
	}

	cout << ans << endl;



}
