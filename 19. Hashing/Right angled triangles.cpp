/*
Given N points in a 2D cartesian plane, how many right angled triangles
are there such that the perpendicular or base is parallel to X or Y axis
*/

#include <iostream>
#include<unordered_map>
using namespace std;

int main() {

	int n; cin >> n;

	unordered_map<int, int> a, b;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[x]++, b[y]++;
	}

	int count = 0;
	if (a.size() <= b.size()) {
		for (auto pt : a) {
			int num1 = pt.second;
			int num2 = b[pt.first];
			if (num2 == 0) continue;
			count += (num1 - 1) * (num2 - 1);
		}
	} else {
		for (auto pt : b) {
			int num1 = pt.second;
			int num2 = a[pt.first];
			if (num2 == 0) continue;
			count += (num1 - 1) * (num2 - 1);
		}
	}

	cout << count << endl;

}
