/*
Pairing problem
================
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<pair<int, int>> l; // Edge List
	int *rank;
	int *parentOf;


public:
	Graph(int V) {
		this->V = V;

		rank = new int[V];
		parentOf = new int[V];

		// Initially rank of each element is 1
		for (int i = 0; i < V; i++) {
			rank[i] = 1;
		}

		// Initialising parent with -1 as each node is a set of its own
		for (int i = 0; i < V; i++) {
			parentOf[i] = -1;
		}

	}

	void addEdge(int a, int b) {
		l.push_back(make_pair(a, b));
	}

	// find(): O(1) Returns leader of the set that a is currently in
	int find(int a) {
		if (parentOf[a] == -1) {
			return a;
		} else {
			// Path compression
			return parentOf[a] = find(parentOf[a]);
		}
	}

	// union : O(1)
	void union_set(int a, int b) {
		int s1 = find(a);
		int s2 = find(b);

		if (s1 != s2) {
			int r1 = rank[s1];
			int r2 = rank[s2];

			if (r1 >= r2) {
				parentOf[s2] = s1;
				rank[s1] = r1 + r2;
				// rank[s1]+=rank[s2];
			} else {
				parentOf[s1] = s2;
				rank[s2] = r1 + r2;
				// rank[s2]
			}
		}
	}

	void pairingProb() {

		// Iterate over the edge list
		for (auto edge : l) {

			int i = edge.first;
			int j = edge.second;

			int s1 = find(i);
			int s2 = find(j);

			if (s1 != s2) {
				union_set(edge.first, edge.second);
			}
		}

		// for (int i = 0; i < V; i++) {
		// 	cout << i << " " << rank[i] << endl;
		// }

		int count = 0;

		for (int i = 0; i < V; i++) {
			int s1 = find(i);
			int rankOfParent = rank[s1];
			count += V - rankOfParent;

			//cout << "Parent of " << i << "=" << s1 << " rank[" << s1 << "]=" << rank[s1] << endl;

			//cout << count << endl;
		}

		cout << count / 2 << endl;


	}



};

int main() {

	int n, m; cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	g.pairingProb();


}
