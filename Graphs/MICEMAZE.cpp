#include <bits/stdc++.h>
using namespace std;



int djikstra(map<int, vector<pair<int, int>>>  l, int n, int m, int src, int dest) {

	// First element of the set gives me the node with the shortest distance
	//		  wt, node
	set<pair<int, int>> s;
	// dist map
	int dist[n];
	// Initially all nodes are at inf distance from src node
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
	}
	// Dist of src node from src node = 0
	dist[src] = 0;

	s.insert({0, src});

	while (!s.empty()) {
		// Take the topmost node
		auto curr = *s.begin();
		s.erase(s.begin());

		int currNode = curr.second;
		int currNodeDist = curr.first;

		// Visit all its nbrs
		for (auto nbr : l[currNode]) {
			int nbrNode = nbr.first;
			int distInBetween = nbr.second;

			int newDist = currNodeDist + distInBetween;

			if (newDist < dist[nbrNode]) {

				// Update set and dist[] for nbr
				auto temp = s.find({dist[nbrNode], nbrNode});
				if (temp != s.end()) s.erase(temp);

				dist[nbrNode] = newDist;
				s.insert({newDist, nbrNode});
			}

		}
	}


	return dist[dest];


}


int main() {

	int n, e, time, m;
	cin >> n >> e >> time >> m;

	map<int, vector<pair<int, int>>> l;

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;

		l[x - 1].push_back({y - 1, wt});
	}

	int count = 0;

	for (int i = 0; i < n; i++) {

		int dist = djikstra(l, n, m, i, e - 1);
		if (dist <= time) count++;
		//cout << "Dist between " << i << " and " << e - 1 << " = " << dist << endl;
	}

	cout << count << endl;
}
