#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void sort(int a[], int n) {

	map<int, int> f;

	for (int i = 0; i < n; i++) f[a[i]]++;

	for (auto p : f) {
		int freq = p.second;
		int num = p.first;
		while (freq) {
			cout << num << " ";
			freq--;
		}
	}


}

signed main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, n);
}
