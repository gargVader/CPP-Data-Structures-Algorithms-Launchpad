// Activity selection problem

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

// we are comapring two pairs
bool compare(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		pair<int, int> arr[1000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr + n, compare);
		cout << endl;
		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i].first << " " << arr[i].second << endl;
		// }
		cout << endl;
		int count = 1, chosen = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i].first >= arr[chosen].second) {
				count++;
				chosen = i;
			}
		}

		cout << count << endl;

	}
}
