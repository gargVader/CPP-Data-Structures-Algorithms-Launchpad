/*
Floyd Warshall Algorithm O(N^3)
--------------------------------
All pair shortest path algorithm

Using BFS/Djikstra/Bellman Ford you can find the shortest path from single source
to all other nodes. So to find the shortest path between pair of nodes, I have to run
the algorithm for all the nodes. => V*(ElogV)

O(V^3) Time and O(V^2) Space

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m; cin >> n >> m;

	int dist[n][n];

	// Initialise dist with inf and diagonal elements with 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INT_MAX;
			if (i == j) dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		dist[x - 1][y - 1] = wt;
	}

	// Floyd Warshall
	// Phases, in kth phase we include vertices {1,2, ... k} as intermediate vertices
	for (int mid = 0; mid < n; mid++) {

		// Consider mid to be the intermediate element between i and j
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (i == mid || j == mid) continue;
				// i->mid->j
				// if vertex mid is included, can we minimize the dist?
				if (dist[i][mid] != INT_MAX && dist[mid][j] != INT_MAX && dist[i][j] > dist[i][mid] + dist[mid][j]) {
					dist[i][j] = dist[i][mid] + dist[mid][j];
				}

			}
		}

	}

	int temp[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = dist[i][j];
		}
	}

	// Check for negative weight cycle
	int mid = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == mid || j == mid) continue;

			if (temp[i][mid] != INT_MAX && temp[mid][j] != INT_MAX && temp[i][j] > temp[i][mid] + temp[mid][j]) {
				temp[i][j] = temp[i][mid] + temp[mid][j];
			}

		}
	}

	bool negCyclePresent = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] != temp[i][j]) negCyclePresent = 1;
		}
	}

	if (negCyclePresent) {
		cout << "Negative Weight Cycle present" << endl;
		return;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		} cout << endl;
	}


}

/*
4 5
1 3 -2
2 1 4
2 3 3
3 4 2
4 2 -1

*/
