// Sum of lengths of contiguous subarrays with distinct elements

// Sum of lengths of contiguous subarrays with distinct elements

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// For maintaining distinct elements.
	unordered_set<int> s;

	// Initialize ending point and result
	int j = 0, ans = 0;

	// Fix starting point
	for (int i = 0; i < n; i++)
	{
		// Find ending point for current subarray with
		// distinct elements.
		while (j < n && s.find(arr[j]) == s.end())
		{
			s.insert(arr[j]);
			j++;
		}

		// Calculating and adding all possible length
		// subarrays in arr[i..j]
		ans += ((j - i) * (j - i + 1)) / 2;

		// Remove arr[i] as we pick new stating point
		// from next
		s.erase(arr[i]);
	}

	cout << ans << endl;

}
