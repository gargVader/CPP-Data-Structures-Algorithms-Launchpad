/*
Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
*/
// Incomplete
#include <bits/stdc++.h>
using namespace std;

int minCost(int original, int start, bool visited[], int n, int **dist) {

	// Base Case
	int ans = dist[start][original];

	if (start == original) {
		ans = INT_MAX;
	}

	// Mark Current node as visited
	visited[start] = 1;

	// Visit all its nbrs
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int cost = dist[start][i] + minCost(original, i, visited, n, dist);
			cout << "Cost for going from " << start << " to " << i << " " << cost << endl;
			ans = min(ans, cost);
		}
	}

	visited[start] = 0;


	return ans;

}



void addEdge(int x, int y, int wt, int **dist) {
	dist[x][y] = wt;
	dist[y][x] = wt;
}

int main() {

	int n = 4;
	int **dist = new int*[n];

	for (int i = 0; i < n; i++) {
		dist[i] = new int[n] {0};
	}

	addEdge(0, 1, 20, dist);
	addEdge(1, 2, 30, dist);
	addEdge(2, 3, 10, dist);
	addEdge(3, 0, 25, dist);
	addEdge(0, 2, 42, dist);
	addEdge(1, 3, 34, dist);

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << dist[i][j] << " ";
	// 	} cout << endl;
	// }

	bool visited[n] = {0};

	cout << minCost(0, 0, visited, n,  dist) << endl;

}
