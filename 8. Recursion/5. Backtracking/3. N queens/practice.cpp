#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int counter = 0;

bool isSafe(int board[][MAX], int row, int col, int n) {

	// check col
	for (int i = 0; i < row; i++) {
		if (board[i][col]) return  0;
	}

	// int x, y;

	// // check left diagonal
	// for ( x = row, y = col; x >= 0, y >= 0; x--, y--) {
	// 	if (board[x][y]) return 0;
	// }

	// // check right diagonal
	// for ( x = row,  y = col; x >= 0, y < n ; x--, y++) {
	// 	if (board[x][y]) return 0;
	// }

	// Check for left diagonal
	int x = row;
	int y = col;

	while (x >= 0 && y >= 0) {
		if (board[x][y]) return 0;
		x--; y--;
	}

	// Check for right diagonal
	x = row;
	y = col;

	while (x >= 0 && y < n) {
		if (board[x][y]) return 0;
		x--; y++;
	}

	return 1;

}


bool solve(int board[][MAX], int row, int n) {

	// Base Case
	if (row == n ) {
		// Print the board
		counter++;

		return 0; // solvable
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(board, row, col, n)) { // If it is safe to keep the Queen at that position we can try to keep it there
			// But it is not guarenteed that a safe place will be the best place
			board[row][col] = 1;
			if (solve(board, row + 1, n)) return 1; // If a particular safe place is good (solvable) then return 1
			else board[row][col] = 0;
		}
	}


	return 0;

}

int main() {
	int n = 4;
	//cin >> n;

	int board[MAX][MAX] = {0};

	solve(board, 0, n);
	cout << counter ;
}