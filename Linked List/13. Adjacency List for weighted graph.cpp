// Adjacency List for weighted graph using list

#include<iostream>
using namespace std;

int main() {

	list<pair<int, int>> *l;

	int n, e; cin >> n >> e;

	l = new list<pair<int, int>>[n];

	for (int i = 0; i < e; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}

	for (int i = 0; i < n; i++) {
		// print every linked list
		cout << "Linked List " << i << "-> ";
		for (auto xp : l[i]) {
			cout << "(" << xp.first << "," << xp.second << ") ";
		} cout << endl;
	}

}

/*
3 3
0 1 4
0 2 3
1 2 4
*/
