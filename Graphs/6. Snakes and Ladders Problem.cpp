/*
Snakes and ladders problem
============================
Find the minimum number of dice throws required to reach the destination 36
starting from the source. Find the shortest path as well.

*/
#include <iostream>
#include<map>
#include <list>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

template<typename T>
class Graph
{

	map<T, list<T>> l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	int bfs(T src, T dest) {
		queue<T> q;
		q.push(src);

		map<T, int> dist;
		map<T, T> parentOf;

		// All other nodes will have inf dist
		for (auto x : l) {
			dist[x.first] = INT_MAX;
		}
		// Dist of src from src = 0
		dist[src] = 0;
		parentOf[src] = src;

		while (!q.empty()) {
			T curr = q.front();
			q.pop();

			// Push all neighbours of curr
			for (auto nbr : l[curr]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[curr] + 1;
					parentOf[nbr] = curr;
				}
			}
		}

		// cout << dist[dest] << endl;
		// Print dist to evry node
		for (auto x : dist) {
			cout << x.first << " " << x.second << endl;
		}

		// Print shortest path
		T curr = dest;

		while (curr != src) {
			cout << curr << " ";
			curr = parentOf[curr];
		}
		cout << curr;
		cout << endl;

		return dist[dest];

	}

	void printAdjList() {

		for (auto lst : l) {

			cout << lst.first << " => ";
			for (auto x : lst.second) {
				cout << x << " ";
			} cout << endl;

		}
	}

};

int minThrows(int board[37]) {
	Graph<int> g;

	for (int i = 0; i < 36; i++) {
		if (board[i] != -1) continue;
		for (int dice = 1; dice <= 6; dice++) {
			if (i + dice > 36) continue;
			if (board[i + dice] == -1) {
				// There exists no ladder/snake at i+dice
				g.addEdge(i, i + dice);
			} else {
				g.addEdge(i, board[i + dice]);
			}
		}
	}

	g.addEdge(36, 36);

	g.printAdjList();

	return g.bfs(0, 36);
}

int main() {

	int n = 6;
	int board[37];
	memset(board, -1, sizeof(board));
	board[2] = 15;
	board[5] = 7;
	board[9] = 27;
	board[18] = 29;
	board[25] = 35;
	board[17] = 4;
	board[34] = 12;
	board[32] = 30;
	board[20] = 6;

	cout << minThrows(board) << endl;

}
