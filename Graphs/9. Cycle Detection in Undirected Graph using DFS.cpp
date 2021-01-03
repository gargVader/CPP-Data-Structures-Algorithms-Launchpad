/*
Given an undirected graph, find if a cycle is present : Using DFS
==================================================================

Run DFS. If during DFS, we come across a node that has not been visited yet,
then initiate a DFS call there. Otherwise, if we come across a node that has
already been visited then it means that the node contributes to a potential cycle.
Catch here is that the node we are checking should not be the parent of the src
(current) node.

*/

#include <iostream>
#include<map>
#include <queue>
#include<list>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	// If during dfs we come across a node that has already been visited then
	// it means that a round path to that node is possible
	bool cycleHelper(T src, map<T, bool> &isVisited, map<T, T> parentOf) {

		cout << src << " ";
		isVisited[src] = true;

		// Visit all nbrs of src
		for (auto nbr : l[src]) {

			if (!isVisited[nbr]) {
				parentOf[nbr] = src;
				bool cycleFound = cycleHelper(nbr, isVisited, parentOf);
				if (cycleFound) return 1;
			} else {
				if (parentOf[src] != nbr)
					return 1;
			}

		}

		return 0;

	}

	bool containsCycle() {
		map<T, bool> isVisited;
		map<T, T> parentOf;

		// Initialising all nodes as not visited
		for (auto p : l) {
			T node = p.first;
			isVisited[node] = false;
			parentOf[node] = node;
		}

		T src = 3;

		return cycleHelper(src, isVisited, parentOf);

	}
};

int main() {

	Graph<int> g;

	// g.addEdge(0, 1);
	// g.addEdge(0, 3);
	// g.addEdge(2, 1);
	// g.addEdge(2, 3);
	// g.addEdge(3, 4);
	// g.addEdge(4, 5);


	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	if (g.containsCycle()) {
		cout << "Cycle Present";
	} else {
		cout << "Cycle Not Present";
	}
	//g.containsCycle();

}
