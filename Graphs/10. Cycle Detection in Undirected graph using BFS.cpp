/*

Cycle detection in undirected graph using BFS
==============================================

Run BFS. If we come across a node that has not been visited yet,
push it into queue. Otherwise, the node is contributing to a potential 
cycle. Catch here is that the node (nbr) should not be parent of the 
current node. 

If cycle is not present then it is Tree
Check if we are visiting a node by more
than one path

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

	bool isTree() {

		map<T, bool> isVisited;
		map<T, T> parentOf;

		for (auto p : l) {
			T node = p.first;
			isVisited[node] = 0;
			parentOf[node] = node;
		}

		T src = 1;

		queue<T> q;
		q.push(src);
		isVisited[src] = 1;

		// BFS
		// Pop out one node and visit its nbrs
		while (!q.empty()) {
			T curr = q.front();
			q.pop();
			cout << curr << endl;

			// Push all nbrs of curr
			for (auto nbr : l[curr]) {
				if (!isVisited[nbr]) {
					q.push(nbr);
					isVisited[nbr] = 1;
					parentOf[nbr] = curr;
				} else if (isVisited[nbr] && parentOf[curr] != nbr) {
					return 0;
				}
			}

		}

		// for (auto p : parentOf) {
		// 	cout << p.first << " " << p.second << endl;
		// }

		return 1;

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

	cout << g.isTree() << endl;

}
