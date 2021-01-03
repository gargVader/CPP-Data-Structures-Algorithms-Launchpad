#include <iostream>
#include<map>
#include <queue>
#include<list>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> l;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	void topological_sort() {

		// indegree
		map<T, int> indegree;
		// Initialising to 0
		for (auto p : l) {
			T node = p.first;
			indegree[node] = 0;
		}

		// Update indegree by traversing edges
		for (auto p : l) {
			for (auto node : p.second) {
				indegree[node]++;
			}
		}

		queue<T> q;
		// Push nodes with  0 indegree
		for (auto p : l) {
			T node = p.first;
			if (indegree[node] == 0) {
				q.push(node);
			}
		}

		while (!q.empty()) {
			T curr = q.front();
			q.pop();
			cout << curr << endl;

			// Reduce indegree of all its nbrs
			for (auto nbr : l[curr]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}

		}

	}
};

int main() {

	Graph<string> g(7);

	g.addEdge("Python", "Data Preprocessing");
	g.addEdge("Python", "ML Basics");
	g.addEdge("Python", "Pytorch");
	g.addEdge("Data Preprocessing", "ML Basics");
	g.addEdge("Pytorch", "DL");
	g.addEdge("ML Basics", "DL");
	g.addEdge("DL", "Face Recognition");
	g.addEdge("Dataset", "Face Recognition");


	g.topological_sort();

}
