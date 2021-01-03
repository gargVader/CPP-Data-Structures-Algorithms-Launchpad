/*
Depth First Search - Recursive

It says that if we are at a particular node then
we will go to its neighbouring node that has not been visited.
Then repeat the process
If all the neighbouring nodes have already been visited then
function call for that node is over

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

	// Recursive function that will traverse the graph
	void dfs_helper(T src, map<T, bool> &visited) {
		// I am src node
		cout << src << " ";
		visited[src] = true;

		// Visit all the nbrs of src
		for (auto nbr : l[src]) {
			// If nbr has not been visited
			if (!visited[nbr]) {
				// Instantiate a dfs call call at nbr
				dfs_helper(nbr, visited);
			}
		}

	}

	void dfs(T src) {
		map<T, bool> visited;
		// Mark all the nodes as not visited in the beginning
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		// Instantiate a dfs call at src
		dfs_helper(src, visited);
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

	g.dfs(0);

}
