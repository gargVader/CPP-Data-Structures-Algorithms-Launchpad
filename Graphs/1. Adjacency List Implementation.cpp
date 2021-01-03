#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

template<class T, class U>
class Graph {

	int V; // Number of Vertices
	unordered_map<T, list<pair<T, U>>> l;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(T x, T y, U weight, bool bidirc = 0) {
		l[x].push_back(make_pair(y, weight));
		if (bidirc)
			l[y].push_back(make_pair(x, weight));
	}

	void printAdjList() {

		for (auto lst : l) {

			cout << lst.first << " => ";
			for (auto x : lst.second) {
				cout << "(" << x.first << "," << x.second << ") ";
			} cout << endl;

		}
	}
};


int main() {

	// Graph<int> g(4);
	// g.addEdge(0, 2);
	// g.addEdge(1, 2);
	// g.addEdge(0, 1);
	// g.addEdge(2, 3);

	// g.printAdjList();

	// Graph<string> g2(4);

	// g2.addEdge("A", "B");
	// g2.addEdge("A", "C");
	// g2.addEdge("B", "D");
	// g2.addEdge("D", "C");

	// g2.printAdjList();

	Graph<string, int> g3(4);

	g3.addEdge("A", "B", 20, 1);
	g3.addEdge("A", "D", 50);
	g3.addEdge("A", "C", 10, 1);
	g3.addEdge("C", "D", 40, 1);
	g3.addEdge("B", "D", 30, 1);

	g3.printAdjList();

}
