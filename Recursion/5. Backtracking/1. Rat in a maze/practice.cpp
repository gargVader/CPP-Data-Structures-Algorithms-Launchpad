#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
#define ROW 1005
#define COL 1005
using namespace std;

int row , col , counter = 0;
bool flag = 0;

bool solve(bool ans[][COL], char maze[][COL] , int i = 0, int j = 0) {

	if (flag) {
		return true;
	}

	//Base Case
	if (i == row - 1 && j == col - 1) { // We have managed to reach the end. So print the path and return true

		ans[i][j] = 1;

		// Print the solution matrix
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		} cout << endl;

		counter++;
		flag = 1;
		return true;
	}

	if (maze[i][j] == 'X') { // If we have hit a obstacle then return false as we cannot pass it
		return false;
	}
	else {
		// Rec Case
		if (i < row - 1) { // If from current pos it is possible to go down, then go down
			// But first mark our curr pos as true
			ans[i][j] = 1;
			solve(ans, maze, i + 1, j);
			ans[i][j] = 0;
		}
		if (j < col - 1) { // If from current pos it is possible to go right, then go right
			// But first mark our curr pos as true
			ans[i][j] = 1;
			solve(ans, maze, i, j + 1);
			ans[i][j] = 0;
		}
	}

	// Backtracking
	//ans[i][j] = 0;

	return true;

}

int main() {
	cin >> row >> col;

	char maze[ROW][COL] = {0};

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> maze[i][j];
		}
	}


	bool ans[ROW][COL] = {0};

	solve(ans, maze);

	if (counter == 0) {
		cout << "-1" << endl;
	}


}


