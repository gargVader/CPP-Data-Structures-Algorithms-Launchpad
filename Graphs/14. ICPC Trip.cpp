/*
------------
ICPC Trip
------------
Between each city I have two options train fare and flight fare.
Minimize total fare. Atmost 1 flight in trip

*/

#include <bits/stdc++.h>
using namespace std;

template<class T, class U, class V>
class triplet {

public:
	T first;
	U second;
	V third;

	triplet(T first, U second, V third): first(first), second(second), third(third) {

	}
};

template<typename T>
class Graph {
	// 				node, train, flight
	map<T, list<triplet<T, int, int>>> l;

public:

	void addEdge(T x, T y, int train, int flight) {
		l[x].push_back({y, train, flight});
		l[y].push_back({x, train, flight});
	}

	void print() {
		for (auto p : l) {
			T node = p.first;
			cout << node << " => ";

			for (auto nbr : l[node]) {
				cout << "(" << nbr.first << "," << nbr.second << "," << nbr.third << ") ";
			} cout << endl;

		}
	}

	unordered_map<T, int> sssp(T src) {

		unordered_map<T, int> dist;

		// Initialising distance to inf
		for (auto p : l) {
			T node = p.first;
			dist[node] = INT_MAX;
		}

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


					// Update set
					auto f = s.find({dist[nbrNode], nbrNode});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[nbrNode] = currNodeDistance + nbrNodeDist;
					s.insert({ dist[nbrNode], nbrNode});
				}
			}

		}

		return dist;

		// for (auto x : dist) {
		// 	cout << x.first << " is at distance " << x.second << endl;
		// }

	}

	int icpcTrip(T src, T dest) {
		unordered_map<T, int> dist1 = sssp(src);
		unordered_map<T, int> dist2 = sssp(dest);

		int ans = dist1[dest]; // Taking no flight

		for (auto p1 : dist1) {
			for (auto p2 : dist2) {

				T node1 = p1.first;
				T node2 = p2.first;

				// ******************************************
				if (node1 != node2) {
					// Flight dist node1->node2
					int flightDist = -1;

					for (auto x : l[node1]) {
						T temp = x.first;
						if (temp == node2) {
							flightDist = x.third;
							break;
						}
					}

					if (flightDist != -1) {
						int currCost = dist1[node1] + dist2[node2] + flightDist;
						ans = min(ans, currCost);
					}
				}

				// *********************************************
			}
		}

		return ans;
	}



};

int main() {

	Graph<string> g;

	g.addEdge("Amritsar", "Delhi", 1, 5);
	g.addEdge("Amritsar", "Jaipur", 4, 10);
	g.addEdge("Delhi", "Jaipur", 2, 1);
	g.addEdge("Mumbai", "Jaipur", 8, 1);
	g.addEdge("Bhopal", "Agra", 2, 2);
	g.addEdge("Mumbai", "Bhopal", 3, 5);
	g.addEdge("Agra", "Delhi", 1, 2);

	g.print();



	cout << g.icpcTrip("Delhi", "Mumbai") << endl;


	// cout << endl;
	// g.sssp("Amritsar");

}
