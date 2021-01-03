#include<iostream>
#include<algorithm>
using namespace std;

int maxSubarraySum(int arr[], int n) {
	int csum = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		csum += arr[i];
		ans = max(ans, csum);
		if (csum < 0) csum = 0;
	}

	if (ans == 0) {
		return *max_element(arr, arr + n);
	}

	return ans;
}


int main() {
	int arr[] = { -3, -2, -5, -1, -6, -3, -2, -7, -5, -2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSubarraySum(arr, n);
}