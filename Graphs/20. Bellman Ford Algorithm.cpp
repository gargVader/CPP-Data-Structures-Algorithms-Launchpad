/*
Bellman Ford Algorithm
------------------------

1) Init dist[vertices]=INT_MAX, dist[src] = 0;
2) Relax all edges V-1 times
3) Negative weight cycle detection

DP based problem

*/

#include <bits/stdc++.h>
using namespace std;

void relax(vector<int> edge, int dist[]) {
	int from = edge[0];
	int to = edge[1];
	int wt = edge[2];

	if (dist[from] != INT_MAX && dist[from] + wt < dist[to]) {
		dist[to] = dist[from] + wt;
	}

}

void bellman_ford(int n, int m, vector<vector<int>> l, int dist[], int src = 0) {

	// Initialise dist to inf
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
	}
	// Dist of src from itself is 0
	dist[src] = 0;

	for (int i = 0; i < n - 1; i++) {

		// Relax all edges
		for (auto edge : l) {
			relax(edge, dist);
		}
	}

	// Check for negative weight cycle
	int temp[n];
	for (int i = 0; i < n; i++) temp[i] = dist[i];

	// Relax all edges
	for (auto edge : l) {
		relax(edge, temp);
	}

	bool negCyclePresent = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] != temp[i]) {
			negCyclePresent = 1; break;
		}
	}

	if (negCyclePresent) {
		cout << "Negative Cycle is present" << endl;
		return;
	}


	for (int i = 0; i < n; i++) {
		cout << i << " is at distance " << dist[i] << endl;
	}
}

int main() {

	int n, m; cin >> n >> m;

	// Edge List
	vector<vector<int>> l;

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		l.push_back({x - 1, y - 1, wt});
	}

	// Distance Map
	int dist[n];

	bellman_ford(n, m, l, dist, 0);

}

/*

3 3
1 2 3
2 3 4
3 1 -10

3 3
1 2 3
2 3 4
1 3 -10



*/

