#include<bits/stdc++.h>
using namespace std;

/*
Spanning Tree
=============
Spanning Tree is a susbet of edges such that all the vertices of the the tree are connected.
The tree forms a single connected component wihtout any cycle.


Minimum Spanning Tree (MST)
===========================
- Kruksal Algorithm (Greedy)
- Prim's Algorithm (Greedy)

Greedy -> By choosing a local minima at each step you
end up getting a global minimum

* Kruksal's Algorithm
----------------------
1. Sort all the edges according to their weights.
2. Take an edge, if it doesnot form a cycle


*/


class DSU {

	int *parentOf;
	int *rank;
	int n;

public:

	DSU(int n) {
		this->n = n;

		parentOf = new int[n];
		rank = new int[n];

		// Initially parentOf each element is -1
		// Initially rank of each element is 1
		for (int i = 0; i < n; i++) {
			parentOf[i] = -1;
			rank[i] = 1;
		}
	}

	// Returns leader of the set
	// find() by path compression
	int find(int a) {
		// Base Case
		if (parentOf[a] == -1) return a;
		return parentOf[a] = find(parentOf[a]);
	}

	// Union by rank
	void union_set(int a, int b) {
		int s1 = find(a);
		int s2 = find(b);

		if (s1 != s2) {
			int r1 = rank[s1];
			int r2 = rank[s2];

			if (r1 >= r2) {
				parentOf[s2] = s1;
				rank[s1] = r1 + r2;
			} else {
				parentOf[s1] = s2;
				rank[s2] = r1 + r2;
			}
		}

	}

	void print() {
		for (int i = 1; i < n; i++) {
			cout << "ParentOf " << i << " = " << parentOf[i] << endl;
		}

		for (int i = 1; i < n; i++) {
			cout << "Rankof " << i << " = " << rank[i] << endl;
		} cout << endl;
	}

};

class Graph {

	vector<vector<int>> edgeList;
	int n;

public:
	Graph(int n) {
		this->n = n;
	}

	void addEdge(int x, int y, int w) {
		edgeList.push_back({w, x, y});
	}


	void kruksal_mst() {

		// Sort all edges in edgeList based on weight
		sort(edgeList.begin(), edgeList.end());
		DSU dsu(n);
		int cost = 0;

		// Loop through all the edges
		for (auto edge : edgeList) {
			int wt = edge[0], a = edge[1], b = edge[2];


			// If both the verticies belong to different
			// sets then consider that edge in MST
			if (dsu.find(a) != dsu.find(b)) {
				cost += wt;
				//cout << a << " " << b << endl;
				dsu.union_set(a, b);
			}
			//dsu.print();

		}

		//cout << "Cost=" << cost << endl;
		cout << cost << endl;

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

	// Graph g(5);

	// g.addEdge(1, 2, 10);
	// g.addEdge(2, 3, 15);
	// g.addEdge(1, 3, 5);
	// g.addEdge(4, 2, 2);
	// g.addEdge(4, 3, 40);


	// Graph g(5);

	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 2);
	// g.addEdge(1, 4, 2);
	// g.addEdge(2, 3, 2);
	// g.addEdge(2, 4, 3);
	// g.addEdge(3, 4, 3);

	g.kruksal_mst();
}