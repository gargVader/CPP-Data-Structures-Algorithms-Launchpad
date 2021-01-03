// Breadth First Search  - Iterative
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
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
		//cout << src << endl;
		visited[src] = 1;

		// Visit all its nbrs
		for (auto nbr : l[src]) {
			// If nbr has not been visited yet
			if (!visited[nbr]) {
				// Initiate a dfs call
				dfs_helper(nbr, visited, ordering);
			}
		}

		// Returning from src node
		ordering.push_front(src);
		return;
	}

	void dfs() {
		map<T, bool> visited;
		list<T> ordering;
		// Mark all the nodes as not visited in the beginning
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		// Iterate over all the nodes and initiate a
		// dfs call on whichever node that has not been visited yet
		for (auto p : l) {
			T node =  p.first;
			if (!visited[node]) {
				// Initiate dfs call
				dfs_helper(node, visited, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
		} cout << endl;

	}

};

int main() {

	Graph<string> g;

	g.addEdge("Python", "Data Preprocessing");
	g.addEdge("Python", "ML Basics");
	g.addEdge("Python", "Pytorch");
	g.addEdge("Data Preprocessing", "ML Basics");
	g.addEdge("Pytorch", "DL");
	g.addEdge("ML Basics", "DL");
	g.addEdge("DL", "Face Recognition");
	g.addEdge("Dataset", "Face Recognition");


	g.dfs();

}
