#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

	map<T, list<T>> l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {

		map<T, bool> isVisited;

		queue<T> q;
		q.push(src);
		isVisited[src] = 1;

		while (!q.empty()) {
			T curr = q.front();
			q.pop();
			cout << curr << " ";

			// Push all nbrs of curr
			for (auto nbr : l[curr]) {
				if (!isVisited[nbr]) {
					q.push(nbr);
					isVisited[nbr] = 1;
				}
			}

		}
	}


	void dfs_helper(T src, map<T, bool> &isVisited) {

		cout << src << " ";
		isVisited[src] = 1;

		// Go to all its nbrs
		for (auto nbr : l[src]) {
			if (!isVisited[nbr]) {
				dfs_helper(nbr, isVisited);
			}
		}

		// Returning from src -> Can be used during Topological sort

	}

	void dfs() {
		map<T, bool> isVisited;

		// Iterate over all nodes
		for (auto p : l) {
			T node = p.first;
			if (!isVisited[node])
				// Instantiate a dfs call at node
				dfs_helper(node, isVisited);

		}
	}

	void topological_sort() {
		// Indegree
		map<T, int> indegree;
		// Initialising to 0
		for (auto p : l) {
			T node = p.first;
			indegree[node] = 0;
		}

		// Updating indegree
		for (auto p : l) {
			for (auto node : p.second) {
				indegree[node]++;
			}
		}

		// BFS
		queue<T> q;

		// Push all elements with indegree 0
		for (auto p : indegree) {
			if (p.second == 0) {
				q.push(p.first);
			}
		}

		while (!q.empty()) {
			T curr = q.front();
			q.pop();
			cout << curr << endl;

			// Reduce indegree of all its nbrs
			for (auto nbr : l[curr]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}

		}




	}

};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.dfs();

}
