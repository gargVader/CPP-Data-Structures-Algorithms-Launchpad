// Spiral print of 2d array2

#include<iostream>
#define ll long long
using namespace std;

int main(){
	int n=5, m=5;
	int arr[][5]={
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}	
	};
	
	int sr=0, sc=0, er=n-1, ec=m-1;
	
	while(sr<=er){
		for(int i=sc; i<=ec; i++){
			cout<<arr[sr][i]<<" ";
		}
		sr++;
		
		for(int i=sr; i<=er; i++){
			cout<<arr[i][ec]<<" ";
		}
		ec--;
		
		for(int i=ec; i>=sc; i--){
			cout<<arr[er][i]<<" ";
		}
		er--;
		
		for(int i=er; i>=sr; i--){
			cout<<arr[i][sc]<<" ";
		}
		sc++;
		
	}
}

