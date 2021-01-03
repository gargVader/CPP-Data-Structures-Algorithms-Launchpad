// Breadth First Search  - Iterative
#include <iostream>
#include<map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph
{
	int n;
	map<T, list<T>> l;

public:

	Graph(int n) {
		this->n = n;
	}

	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		//cout << src << endl;
		visited[src] = 1;

		// Go to all its nbrs that have not been visited yet
		for (auto x : l[src]) {
			if (!visited[x]) {
				dfs_helper(x, visited);
			}
		}

	}

	int dfs() {
		map<T, bool> visited;
		// Mark all the nodes as not visited in the beginning
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}

		// for (auto p : l) {
		// 	T node = p.first;
		// 	visited[node] = false;
		// }

		int count = 0;

		// Iterate over all the nodes and in initiate a dfs call
		for (int i = 0; i < n; i++) {
			T node =  i;
			if (!visited[node]) {
				// Initiate dfs call
				dfs_helper(node, visited);
				count++;
			}
		}

		return count;
	}

};

int main() {

	int n, p; cin >> n >> p;

	Graph<int> g(n);

	for (int i = 0; i < p; i++) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << g.dfs();

}
