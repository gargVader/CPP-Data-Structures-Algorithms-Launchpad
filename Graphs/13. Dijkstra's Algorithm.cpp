/*
Djikstra Algorithm : O(ElogV)
=============================

Single Source Shortest Path Algorithm for weighted graph

*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {

	map<T, list<pair<T, int>>> l;

public:

	void addEdge(T x, T y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	void print() {
		for (auto p : l) {
			T node = p.first;
			cout << node << " => ";

			for (auto nbr : l[node]) {
				cout << "(" << nbr.first << "," << nbr.second << ") ";
			} cout << endl;

		}
	}

	void sssp(T src) {


		unordered_map<T, int> dist;

		// Initialising distance to inf
		for (auto p : l) {
			T node = p.first;
			dist[node] = INT_MAX;
		}
		// Dist of src from itself = 0
		dist[src] = 0;

		// Set to find out node with minimum distance
		// 		dist, node
		set<pair<int, T>> s;
		s.insert({0, src});

		while (!s.empty()) {
			// Find the pair at the front
			pair<int, T> p = *s.begin();
			T currNode = p.second;

			int currNodeDistance = p.first;
			// Remove finalised node
			s.erase(s.begin());

			// Visit nbrs of curr node
			for (auto nbr : l[currNode]) {

				T nbrNode = nbr.first;
				int nbrNodeDist = nbr.second;

				// Potential new distance = currNodeDistance + nbrNodeDist

				if (currNodeDistance + nbrNodeDist < dist[nbrNode]) {


					// Update set and map
					auto f = s.find({dist[nbrNode], nbrNode});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[nbrNode] = currNodeDistance + nbrNodeDist;
					s.insert({ dist[nbrNode], nbrNode});
				}
			}

		}

		for (auto x : dist) {
			cout << x.first << " is at distance " << x.second << endl;
		}



	}

};

int main() {

	Graph<string> g;

	g.addEdge("Amritsar", "Delhi", 1);
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Delhi", "Jaipur", 2);
	g.addEdge("Mumbai", "Jaipur", 8);
	g.addEdge("Bhopal", "Agra", 2);
	g.addEdge("Mumbai", "Bhopal", 3);
	g.addEdge("Agra", "Delhi", 1);

	g.print();
	cout << endl;
	g.sssp("Amritsar");

}
