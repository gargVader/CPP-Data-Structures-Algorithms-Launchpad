#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x]++;
	}

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (mp[x]) {
			v.push_back(x);
			mp[x]--;
		}
	}

	sort(v.begin(), v.end());

	cout << "[";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i < v.size() - 1)
			cout << ", ";
	}
	cout << "]";



}
