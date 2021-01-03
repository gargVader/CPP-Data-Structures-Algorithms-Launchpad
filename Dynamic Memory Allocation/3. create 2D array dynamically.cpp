// Create 2D array dynamically

#include<iostream>
using namespace std;

int main() {
	int row, col; cin >> row >> col;

	int **arr = new int*[row];

	for (int i = 0; i < row; i++) {
		arr[i] = new int[col] {0};
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
	}

//	for(int* i=*arr; i<=(*arr+row)+col; i++){
//		cin>>*i;
//	}
//	for(int* i=*arr; i<=(*arr+row)+col; i++){
//		cout<<*i<<" ";
//	}
}

