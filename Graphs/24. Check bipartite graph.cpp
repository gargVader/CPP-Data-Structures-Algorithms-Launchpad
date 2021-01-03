/*
Bipartite Graph Check
----------------------
Problem:
Divide all vertcies of the graph in two sets such that
all the edges of the graph are from set1 to set2

Similar to 2 coloring problem

Algorithm:
1) If graph is a tree, then YES Bipartite.
2) If it is not a tree(=> cycle is present)
	Odd length cycle => NOT Bipartite
	Even length cycle => YES Bipartite

*/

#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[], int src, int visited[], int parentOf[], int color) {

	// Mark the current node
	visited[src] = color;

	// Visit all the nbrs of src
	for (int nbr : graph[src]) {
		if (!visited[nbr]) {
			parentOf[nbr] = src;
			bool oddLenCycleFound = dfs_helper(graph, nbr, visited, parentOf, 3 - color);
			if (oddLenCycleFound) return 0;
		} else {
			// nbr potentially contributes to a cycle
			if (parentOf[src] == nbr) {
				// Not a cycle
			} else {
				// Yes a cycle
				//nbrs of src should not have same color
				if (visited[nbr] == color) return 0;
			}

		}
	}

	return true;

}

bool dfs(vector<int> graph[], int n) {

	int visited[n] = {0};
	// 0 -> Not visited
	// 1,2 -> Visited and color is 1,2
	int parentOf[n];
	for (int i = 0; i < n; i++) {
		parentOf[i] = i; // Initially each node is a parent of itself
	}

	bool ans = dfs_helper(graph, 0, visited, parentOf, 1);

	for (int i = 0; i < n; i++) {
		cout << i << " color=" << visited[i] << endl;
	}

	return ans;
}


int main() {

	// n : Number of vertices
	// m : Number of edges
	int n, m;
	cin >> n >> m;

	// Ajacency List : graph[i] stores all the neighbours of i
	vector<int> graph[n];

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << dfs(graph, n);


}

/*
5 5
0 1
1 2
2 3
3 4
4 0

*/
