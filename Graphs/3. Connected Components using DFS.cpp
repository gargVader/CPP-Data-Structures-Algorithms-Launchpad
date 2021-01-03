/*
Number of connected components in a graph:
Iterate through all the nodes of garph. If node is unvisited then instantiate a DFS call at 
that particular node. Number of DFS calls made = Number of connected components
*/
#include <iostream>
#include<map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph
{

	map<T, list<T>> l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << endl;
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
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		int count = 0;

		// Iterate over all the nodes and if node is unvisited then initiate a dfs call
		for (auto p : l) {
			T node =  p.first;
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

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(10, 10);

	cout << g.dfs();

}
