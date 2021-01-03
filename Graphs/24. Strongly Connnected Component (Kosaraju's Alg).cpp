/*
Kosaraju's Algorithm for strongly connected components
-------------------------------------------------------
A directed graph is strongly connected if there is a path between all pairs of vertices
*/

#include <bits/stdc++.h>
using namespace std;

void dfs_helper(vector<int> graph[], int src, bool visited[], vector<int> &stack) {

	// Mark the current node as visited
	visited[src] = 1;

	// Visit all its nbrs
	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			dfs_helper(graph, nbr, visited, stack);
		}
	}

	// Returing from call
	stack.push_back(src);

}

void dfs_helper2(vector<int> rev_graph[], int src, bool visited[], vector<int> &ssc) {

	// Mark the current node as visited
	visited[src] = 1;
	ssc.push_back(src);

	// Visit all its nbrs
	for (auto nbr : rev_graph[src]) {
		if (!visited[nbr]) {
			dfs_helper2(rev_graph, nbr, visited, ssc);
		}
	}

}

void solve(vector<int> graph[], vector<int> rev_graph[], int n) {

	bool visited[n] = {0};
	// Stores the ordering
	vector<int> stack;

	// Run a dfs and get ordering list
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			// Instantiate a dfs call
			dfs_helper(graph, i, visited, stack);
		}
	}

	// Print the ordering
	cout << "Ordering: " << endl;
	for (auto x : stack) {
		cout << x << " ";
	} cout << endl;

	// Re initialise visited[]
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	int count = 0;
	vector<int> ssc[n];

	// Run dfs
	for (int i = stack.size() - 1; i >= 0; i--) {
		if (!visited[stack[i]]) {
			dfs_helper2(rev_graph, stack[i], visited, ssc[count]);
			count++;
		}
	} cout << endl;

	cout << count << endl;

	cout << "Components are" << endl;
	for (auto v : ssc) {
		for (auto x : v) {
			cout << x << " ";
		} cout << endl;
	}

}

int main() {

	int n; cin >> n;

	vector<int> graph[n];
	vector<int> rev_graph[n];

	int m; cin >> m;

	while (m--) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);

	}

	solve(graph, rev_graph, n);

}

/*
7 8
0 2
2 1
1 0
0 3
3 4
3 5
5 6
6 3
*/