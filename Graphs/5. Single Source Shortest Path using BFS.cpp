/*
Distance between src and any other node when calcuated by bfs
is equal to the shortest distance between them.[Valid only for unweighted graph] 
[For weighted graph: Djikstra Algorithm]

This is because in BFS when we are at a particular node, we will first 
visit all the nodes that are at its level. [Note: Remember that nodes at the same level are 
at same distance from the src node] But in DFS, we will visit the child of the node. Only when 
we are finished recurisively iterating through the children that we will do the same with other nodes in 
the same level.

*/
#include <iostream>
#include<map>
#include <list>
#include <queue>
#include <climits>
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

	void bfs(T src, T dest) {
		queue<T> q;
		q.push(src);

		map<T, int> dist;

		// All other nodes will have inf dist
		for (auto x : l) {
			dist[x.first] = INT_MAX;
		}
		// Dist of src from src = 0
		dist[src] = 0;

		while (!q.empty()) {
			T curr = q.front();
			q.pop();

			// Push all neighbours of curr
			for (auto nbr : l[curr]) {
				if (dist[nbr] == INT_MAX) { // nbr has not been visited yet
					q.push(nbr);
					dist[nbr] = dist[curr] + 1; // Update distance
				}
			}
		}

		cout << dist[dest] << endl;
		// Print dist to evry node
		for (auto x : dist) {
			cout << x.first << " " << x.second << endl;
		}

	}

};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(0, 2);

}
