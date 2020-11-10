// Longest Consecutive Subsequence
// Method 1: Sorting O(nlogn)
// Method 2: Storing freq and iterating through min to max'
// O(max - min)

#include <iostream>
#include<unordered_map>
using namespace std;

int main() {

	int a[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
	int n = sizeof(a) / sizeof(a[0]);

	int freq[200] = {0};

	for (int i = 0; i < n; i++) {
		freq[a[i]] = 1;
	}

	int count = 0, ans = 0;

	for (int i = 0; i < 100; i++) {
		if (freq[i]) {
			count++;
			ans  = max(ans, count);
		} else {
			ans  = max(ans, count);
			count = 0;
		}
	}
	cout << ans << endl;



}
