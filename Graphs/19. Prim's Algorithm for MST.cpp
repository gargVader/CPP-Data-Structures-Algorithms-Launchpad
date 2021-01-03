/*
Prim's Algorithm
=================

MST Set[] -> Vertices that have been added in MST till now
Active Edge -> Edge from vertex in MST[] to vertex in V[]
MST edge -> Edge from vertex in MST[] to vertex on MST[]

Algorithm O(ElogV)
1. Start from any given src vertex
2. Mark all the edges as active edge(if possible)
3. Loop through all the active nodes
4. Choose the shortest among all the active edges

*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int n;
	map<int, list<pair<int, int>>> l; // Adj List

public:

	Graph(int n) {
		this->n = n;
	}

	void addEdge(int x, int y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	void prim_mst() {
		//					wt, node
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		// Returns whether i is a part of MST or not
		bool visited[n] = {0};
		int ans = 0;

		pq.push({0, 0});

		while (!pq.empty()) {
			/// Pick the edge with the min wt
			auto best = pq.top();
			pq.pop();

			int to = best.second;
			int weight = best.first;

			if (visited[to]) {
				// discard the edge from active edges
				continue;
			}

			// Otherwise take the current edge
			ans += weight;
			// Mark it as visited
			visited[to] = 1;
			// Push all active edges connected to best inside the pq
			for (auto edge : l[to]) {
				int node = edge.first;
				int wt = edge.second;
				if (!visited[node]) {
					pq.push({wt, node});
				}

			}


		}

		cout << ans << endl;


	}

};


int main() {

	int n, m; cin >> n >> m;

	Graph g(n);

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		g.addEdge(x - 1, y - 1, wt);
	}

	// Graph g(4);

	// g.addEdge(0, 1, 1);
	// g.addEdge(0, 3, 2);
	// g.addEdge(0, 2, 2);
	// g.addEdge(1, 2, 2);
	// g.addEdge(1, 3, 3);
	// g.addEdge(3, 2, 3);

	g.prim_mst();

}
