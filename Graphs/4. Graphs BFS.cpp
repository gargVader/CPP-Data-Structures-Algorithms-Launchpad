/*
Breadth First Search  - Iterative
If we are at a particular src node, then we will first move to
all the nodes that are at a distance 1 from the src node, then we
will move to all the nodes that are at a distance 2 from src node ...

Level Order Traversal

Distance between src and any other node when calcuated by bfs
is equal to the shortest distance between them. [Valid only for unweighted graph] 
[For weighted graph: Djikstra Algorithm]

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

	void bfs(T src) {
		queue<T> q;
		q.push(src);

		map<T, bool> isVisited;
		isVisited[src] = 1;

		while (!q.empty()) {
			T curr = q.front();
			cout << curr << " ";
			q.pop();

			// Push all neighbours of curr if they have not been visited yet
			for (auto nbr : l[curr]) {
				if (!isVisited[nbr]) {
					q.push(nbr);
					isVisited[nbr] = 1;
				}
			}
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

	g.bfs(0);

}
