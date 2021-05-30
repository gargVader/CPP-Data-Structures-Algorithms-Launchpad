#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int numPaths[100005] = {0};
bool isVisited[100005] = {0};
void dfs(int src, int len, vector<vector<int>> v) {

	// Mark current node as visited
	isVisited[src] = 1;

	// Loop through all the nbrs
	int ans = len;
	for (auto nbr : v[src]) {
		if (!isVisited[nbr]) {

		}
	}

}

int longestPath(vector<vector<int>> v, int n, int m) {

	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

}


signed main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 5);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
	}
}
