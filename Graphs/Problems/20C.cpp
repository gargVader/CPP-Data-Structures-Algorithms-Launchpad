#include <bits/stdc++.h>
using namespace std;

class Graph {
	map<int, list<pair<int, int>>> l;


public:
	vector<int> path;

	void addEdge(int x, int y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	void djikstraSSSP(int src, int dest) {

		map<int, int> dist;
		map<int, int> parentOf;

		// Initialising dist of all nodes to inf
		for (int i = src; i <= dest; i++) {
			dist[i] = INT_MAX;
			parentOf[i] = i;
		}

		// Distance of src node from itself = 0
		dist[src] = 0;
		// src node has no parent
		parentOf[src] = -1;

		// set created to get the min dist element at the beginning
		// 		dist, node
		set<pair<int, int>> s;
		s.insert({dist[src], src});

		while (!s.empty()) {

			pair<int, int> p = *s.begin();
			s.erase(s.begin());
			int currNode = p.second;
			int currNodeDist = p.first;

			// visit all nbrs of node
			for (auto nbr : l[currNode]) {
				int nbrNode = nbr.first;
				int distInBetween = nbr.second;
				int nbrNodeDist = dist[nbrNode];

				// Potential new distance = currNodeDist + distInBetween
				if (currNodeDist + distInBetween < nbrNodeDist) {

					// Update dist in both set and map
					// If node not present in set then add it
					auto pr = s.find({dist[nbrNode], nbrNode});
					if (pr != s.end()) {
						s.erase(pr);
					}
					dist[nbrNode] = currNodeDist + distInBetween;
					s.insert({dist[nbrNode], nbrNode});
					parentOf[nbrNode] = currNode;
				}

			}

		}

		// Printing distance
		// for (auto x : dist) {
		// 	cout << x.first << " is at distance of " << x.second << endl;
		// }

		// No path from 1 to n
		if (dist[dest] == INT_MAX || parentOf[dest] == dest) {
			cout << "-1" << endl;
		} else {
			// Path exists
			printPath(parentOf, src, dest);
		}



	}

	void printPath(map<int, int> parentOf, int src, int dest) {

		if (parentOf[dest] == dest) {
			return;
		}

		// Base Case
		if (dest == src) {
			cout << src << " ";
			path.push_back(src);
			return;
		}

		printPath(parentOf, src, parentOf[dest]);
		cout << dest << " ";
		path.push_back(dest);
	}

};



int main() {

	int n, m; cin >> n >> m;
	Graph g;
	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		g.addEdge(x, y, wt);
	}

	g.djikstraSSSP(1, n);
}
