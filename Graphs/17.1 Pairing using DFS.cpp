#include <bits/stdc++.h>
using namespace std;

class Graph {

	int n;
	unordered_map<int, list<int>> l;

public:
	Graph(int n) {
		this->n = n;
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	int dfs_helper(int node, bool isVisited[]) {

		isVisited[node] = 1;

		int count = 1;
		// Visit all its nbrs
		for (auto nbr : l[node]) {
			if (!isVisited[nbr]) {
				count += dfs_helper(nbr, isVisited);
			}
		}

		// In base case count = 1
		return count;

	}

	void dfs() {
		// Stores the count of nodes in each connected component.
		vector<int> v;
		bool isVisited[n] = {0};

		for (auto p : l) {
			int node = p.first;
			if (!isVisited[node]) {
				int count = dfs_helper(node, isVisited);
				v.push_back(count);
			}
		}

		// If each element is a separate component
		int ans = (n * (n - 1)) / 2;

		// Two elements cannot be chosen from the same component
		for (auto x : v) {
			int num = (x * (x - 1)) / 2;
			ans -= num;
		}

		cout << ans << endl;

	}

};


int main() {

	int n, m; cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	g.dfs();



}
