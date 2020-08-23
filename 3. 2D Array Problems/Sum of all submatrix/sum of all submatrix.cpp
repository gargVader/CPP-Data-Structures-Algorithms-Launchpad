// sum of all submatrix of a given matrix

#include<iostream>
#define MAX 100
using namespace std;

int main(){
	int row, column, sum=0;
	cout<<"Enter number of rows: "; cin>>row;
	cout<<"Enter number of columns: "; cin>>column;
	int arr[MAX][MAX];
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			sum += arr[i][j]*(i-0+1)*(j-0+1)*(row-i)*(column-j);
		}
	}
	
	cout<<sum;
}

