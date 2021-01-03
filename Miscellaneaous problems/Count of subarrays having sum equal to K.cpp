#include<bits/stdc++.h>
using namespace std;

int numSubarrays(int arr[], int n, int k) {

	int csum = 0;
	unordered_map<int, int> freq;
	int count = 0;
	for (int i = 0; i < n; i++) {
		csum += arr[i];

		if (csum == k) count++;

		if (freq.find(csum - k) != freq.end()) {
			count += freq[csum - k];
		}

		freq[csum]++;
	}

	return count;
}


int main() {
	int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
	int k = 7;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << numSubarrays(arr, n, k);
}