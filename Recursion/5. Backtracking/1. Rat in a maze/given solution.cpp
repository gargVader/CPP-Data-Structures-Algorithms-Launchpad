#include<bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;

int row, col; char mat[15][15];

bool solve(int i, int j, bool ans[][15]) {

	// Base case
	if (i == row && j == col) {
		// Print the ans matrix
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << ans[i][j];
			} cout << endl;
		} cout << endl;

		return true;
	}

	// Rat should be inside the grid
	if (i > row || j > col) {
		return false;
	}
	if (mat[i][j] == 'X') {
		return false;
	}

	// Recurive Case
	// Assume solution exists through current cell
	ans[i][j] = 1;
	bool rightSuccess = solve(i, j + 1, ans);
	bool downSuccess = solve(i - 1, j, ans);

	// This code is run after returning back from function call
	// Backtracking
	ans[i][j] = 0;

	if (rightSuccess || downSuccess) {
		return true;
	}

	return false;
}

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> mat[i][j];
		}
	}


	bool ans[15][15] = {0};

	solve(0, 0, ans);

}

