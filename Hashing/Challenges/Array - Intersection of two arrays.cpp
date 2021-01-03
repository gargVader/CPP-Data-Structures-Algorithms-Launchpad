#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	unordered_map<int, int> mp1, mp2;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp1[x]++;
	}

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp2[x]++;
	}

	for (auto p : mp1) {
		mp1[p.first] = min(p.second, mp2[p.first]);
	}

	for (auto p : mp1) {
		int num = p.first;
		int freq = p.second;
		for (int i = 0; i < freq; i++) {
			cout << num << " ";
		}

	}

}
