/*
Cycle Detection in directed garph using DFS
============================================

Run DFS. If we come acrosss a node that has not been visited yet, 
then mark it as visited and add it to the path_stack. Then recursively call
the DFS fucntion on its nbrs. If the node has been visited then it contributes
to a potential cycle. Check if it is already present in the path_stack. If yes then that means
that a back-edge is present in the path and a cycle exists.


*/


#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	// void dfs_helper(T src, map<T, bool> &isVisited, map<T, bool> &path, bool* containsCycle) {

	// 	// I am at src node
	// 	cout << src << endl;
	// 	// Mark src node as visited
	// 	isVisited[src] = 1;
	// 	path[src] = 1;

	// 	// Visit nbrs of src
	// 	for (auto nbr : l[src]) {

	// 		if (!isVisited[nbr]) {
	// 			dfs_helper(nbr, isVisited, path, containsCycle);
	// 		} else {
	// 			// Check if nbr is already present in path
	// 			if (path[nbr] == 1) {
	// 				*containsCycle = true;
	// 			}

	// 			if (!containsCycle) {
	// 				path[nbr] = 1;
	// 			}
	// 		}

	// 	}

	// 	// Returing from src
	// 	path[src] = 0;
	// }

	bool cycle_helper(T src, map<T, bool> &isVisited, map<T, bool> &path) {

		// I am at src node
		cout << src << " ";
		// Mark src node as visited
		isVisited[src] = 1;
		path[src] = 1;


		// Check if src node leads to a cycle

		// Visit nbrs of src
		for (auto nbr : l[src]) {

			// nbr is already present in path
			if (path[nbr]) {
				// Back edge detected
				return true;
			}

			if (!isVisited[nbr]) {
				bool cycleFound =  cycle_helper(nbr, isVisited, path);
				// Return only if cycleFound
				if (cycleFound) {
					return 1;
				}
			}

		}

		// Returning from src node
		path[src] = 0;
		return 0;

	}

	// Checks for cycle in directed graph
	bool contains_cycle() {

		map<T, bool> isVisited;
		map<T, bool> path;

		// Initialising all nodes to be unvisited and path to be empty
		for (auto p : l) {
			T node = p.first;
			isVisited[node] = 0;
			path[node] = 0;
		}

		T src = 0;

		return cycle_helper(src, isVisited, path);

		// bool containsCycle = false;
		// // Instantiate dfs call from src
		// dfs_helper(src, isVisited, path, &containsCycle);
		// return containsCycle;

	}

};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	// g.addEdge(4, 2);
	g.addEdge(1, 5);

	cout << g.contains_cycle();

}