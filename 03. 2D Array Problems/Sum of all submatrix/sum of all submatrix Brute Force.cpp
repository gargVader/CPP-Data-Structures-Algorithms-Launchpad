// sum of all submatrix of a given matrix

// Brute force

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
	
	// Getting Top Left coordn
	for(int Ti=0; Ti<row; Ti++){
		for(int Tj=0; Tj<column; Tj++){
			//Getting Bottom Right coordn
			for(int Bi=Ti; Bi<row; Bi++){
				for(int Bj=Tj; Bj<column; Bj++){
					// Summing all elements
					for(int tempi=Ti; tempi<Bi; tempi++){
						for(int tempj=Tj; tempj<Bj; tempj++){
							sum+=arr[tempi][tempj];
						}
					}
				}
			}
		}
	}
	
	cout<<sum;
}

