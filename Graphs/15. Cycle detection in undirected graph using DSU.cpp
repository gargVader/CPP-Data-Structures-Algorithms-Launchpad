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
	// O(n)
	int find(int a, int parentOf[]) {
		return parentOf[a] == -1 ? a : find(parentOf[a], parentOf);
	}

	// union
	// O(n)
	void union_set(int a, int b, int parentOf[]) {
		int s1 = find(a, parentOf);
		int s2 = find(b, parentOf);

		if (s1 != s2) {
			parentOf[s2] = s1;
			cout<<"Set parent of "<<s2<<" as "<<s1<<endl;
		}
	}

	bool contains_cycle() {
		// DSU approach
		int parentOf[V];
		// int *parentOf = new int[V]

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
				cout << "Same parent of " << i << " and " << j << " = " << s1 << endl;
				return true;
			} else {
				//cout<<"Unioning "<<edge.first<<" "<<edge.second<<endl;
				union_set(edge.first, edge.second, parentOf);
			}
		}

		for(int i=0; i<V; i++){
			cout<<i<<" "<<parentOf[i]<<endl;
		}


		return false;

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
	//g.addEdge(2, 6);

	cout << g.contains_cycle() << endl;


}
