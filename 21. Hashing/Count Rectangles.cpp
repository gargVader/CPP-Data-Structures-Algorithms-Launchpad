/*
Given N cartesian points, find the number of axis parallel
rectangles that can be formed by them
*/

#include <iostream>
#include<vector>
#include<set>
using namespace std;

class PointCompare {

public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first < b.first;
	}

};

void print(pair<int, int> p) {
	cout << p.first << " " << p.second << endl;
}

int count_rect(vector<pair<int, int>> v) {
	int n = v.size();

	set<pair<int, int>, PointCompare> s;

	for (auto pt : v) {
		s.insert(pt);
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<int, int> pt1 = make_pair(v[i].first, v[i].second);
			pair<int, int> pt2 = make_pair(v[j].first, v[j].second);

			print(pt1); print(pt2);

			if (pt1.first == pt2.first || pt1.second == pt2.second) {
				cout << "Lies on same axis" << endl;
				continue;
			}



			pair<int, int> pt3 = make_pair(v[i].first, v[j].second);
			pair<int, int> pt4 = make_pair(v[j].first, v[i].second);
			print(pt3); print(pt4);

			if (s.find(pt3) != s.end() && s.find(pt4) != s.end()) {
				count++;
				cout << "found. Count++" << endl;
			} else {
				cout << "Not found" << endl;
			}

		}
	}

	return count / 2;

}

int main() {

	vector<pair<int, int>> v{
		{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 1}, {2, 0}, {3, 1},
		{3, 0}
	};

	cout << count_rect(v);

}
