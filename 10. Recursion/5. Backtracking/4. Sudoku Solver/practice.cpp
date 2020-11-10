#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][9], int i, int j, int n, int num) {

	// // Check row
	// for (int col = 0; col < n; col++) {
	// 	if (board[i][col] == num) return 0;
	// }

	// // Check col
	// for (int row = 0; row < n; row++) {
	// 	if (board[row][j] == num) return 0;
	// }

	// // Check sub-grid
	// int col = (j / 3) * 3;
	// int row = (i / 3) * 3;

	// for (int x = row; x < row; x++) {
	// 	for (int y = col; y < col; y++) {
	// 		if (board[x][y] == num) return 0;
	// 	}
	// }

	// return 1;

	// Check in row or col
	for (int x = 0; x < n; x++) {
		if (board[x][j] == num || board[i][x] == num) {
			return 0;
		}
	}

	// Check in subgrid
	int rn = sqrt(n);
	int sx = (i / rn) * rn, sy = (j / rn) * rn;

	for (int x = sx; x < sx + rn; x++) {
		for (int y = sy; y < sy + rn; y++) {
			if (board[x][y] == num) return 0;
		}
	}

	return 1;

}


bool solve(int board[][9], int i, int j, int n) {

	// Base Case
	if (i == n) {
		// Print board
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				cout << board[row][col] << " ";
			} cout << endl;
		} cout << endl;


		return 1;
	}

	if (j >= n) {
		solve(board, i + 1, 0, n);
	}

	if (board[i][j] != 0) {
		solve(board, i, j + 1, n);
	}



	for (int x = 1; x <= n; x++) {
		if (isSafe(board, i, j, n, x)) {
			// Assume
			board[i][j] = x;
			bool couldWeSolve = solve(board, i, j + 1, n); // were we able to solve the sudoku by placing x?
			if (couldWeSolve) {
				return true;
			}
			else board[i][j] = 0;  //Backtracking
		}
	}

	return false;
}


int main() {

	int n = 9;

	int board[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0 },
		{6, 0, 0, 1, 9, 5, 0, 0, 0 },
		{0, 9, 8, 0, 0, 0, 0, 6, 0 },
		{8, 0, 0, 0, 6, 0, 0, 0, 3 },
		{4, 0, 0, 8, 0, 3, 0, 0, 1 },
		{7, 0, 0, 0, 2, 0, 0, 0, 6 },
		{0, 6, 0, 0, 0, 0, 2, 8, 0 },
		{0, 0, 0, 4, 1, 9, 0, 0, 5 },
		{0, 0, 0, 0, 8, 0, 0, 7, 9 }
	};

	solve(board, 0, 0, n);

}