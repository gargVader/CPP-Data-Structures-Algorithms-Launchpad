// set STL
// Values cannot be modified. They have to be removed completely and a new value be inserted
// Underlying implementation - Red Black Tree

#include<iostream>
#include<set>
#include<climits>
using namespace std;

int main() {
	int a[] = {1, 19, 1, 2, 4, 12, 9, 45, 2, 56};
	int n = sizeof(a) / sizeof(a[0]);

	set<int> s;

	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
	}

	s.erase(45);
	auto it = s.find(19);
	s.erase(it);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *(it) << " ";
	} cout << endl;

	set<pair<int, int>> s2;
	s2.insert(make_pair(1, 2));
	s2.insert(make_pair(2, 2));
	s2.insert(make_pair(43, 29));
	s2.insert(make_pair(7, 10));

	s2.erase(make_pair(2, 2));
	s2.insert(make_pair(10, 10));


	auto it2 = s2.lower_bound(make_pair(10, 10));
	cout << it2->first << " AND " << it2->second << endl;
	// if we want a pair where the first element is atleast 10
	it2 = s2.upper_bound(make_pair(10, INT_MAX));
	cout << it2->first << " AND " << it2->second << endl;


	for (auto p : s2) {
		cout << p.first << " " << p.second << endl;
	}
}