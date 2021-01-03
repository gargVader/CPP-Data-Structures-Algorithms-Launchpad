/*
Optimisations
=============
1. Path compression optimisation in DSU
2. Union by Rank
After Path compression optimisation only -> O(logn)
After using both optimisations -> O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Cycle detection in a undirected graph using DSU

class Graph {
	int V;
	list<pair<int, int>> l; // Edge List

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int a, int b) {
		l.push_back(make_pair(a, b));
	}

	// Returns leader of the set that a is currently in
	// O(1)
	int find(int a, int parentOf[]) {
		if (parentOf[a] == -1) {
			return a;
		} else {
			// Path compression
			return parentOf[a] = find(parentOf[a], parentOf);
		}
	}

	// union
	// O(1)
	void union_set(int a, int b, int parentOf[], int rank[]) {
		int s1 = find(a, parentOf);
		int s2 = find(b, parentOf);

		if (s1 != s2) {
			int r1 = rank[s1];
			int r2 = rank[s2];

			if(r1>=r2){
				parentOf[s2] = s1;
				rank[s1] = r1+r2;
				// rank[s1]+=rank[s2];
			}else{
				parentOf[s1] =s2;
				rank[s2] = r1+r2;
				// rank[s2]
			}
		}
	}

	bool contains_cycle() {
		// DSU approach
		int parentOf[V];
		// int *parentOf = new int[V]
		bool f = 0;


		int rank[V];
		for(int i=0; i<V; i++){
			rank[i] = 1;
		}

		// Initialising with -1;
		// Each node is a set of its own
		for (int i = 0; i < V; i++) {
			parentOf[i] = -1;
		}

		// Iterate over the edge list
		for (auto edge : l) {

			int i = edge.first;
			int j = edge.second;

			int s1 = find(i, parentOf);
			int s2 = find(j, parentOf);

			if (s1 == s2) {
				// cycle present
				//cout << "Same parent of " << i << " and " << j << " = " << s1 << endl;
				//return true;
				f = 1;
			} else {
				union_set(edge.first, edge.second, parentOf, rank);
			}
		}

		for (int i = 0; i < V; i++) {
			cout << i << " " << parentOf[i] << endl;
		}

		for(int i=0; i<V; i++){
			cout<<i<<" "<<parentOf[i]<<endl;
		}

		cout<<"Rank: "<<endl;
		for(int i=0; i<V; i++){
			cout<<i<<" "<<rank[i]<<endl;
		}

		return f;

	}



};

int main() {

	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(2, 5);
	g.addEdge(2, 6);

	cout << g.contains_cycle() << endl;


}
