// Maximum sum submatrix in row & colwise sorted matrix

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[][3]={
		{-5,-4,-1},
		{-3,2,4},
		{2,5,8},
	};
	int row=3, col=3;
	// suffix sum matrix
	for(int i=row-1; i>=0; i--){
		for(int j=col-2; j>=0; j--){
			arr[i][j] += arr[i][j+1];
		}
	}
	for(int j=col-1; j>=0; j--){
		for(int i=row-2; i>=0; i--){
			arr[i][j] += arr[i+1][j];
		}
	}
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int maximum=INT_MIN; 
	
	for(int i=0; i<row; i++){
		maximum = max(*max_element(arr[i], arr[i]+col), maximum);
	}
	
	cout<<maximum;
	
	
}

