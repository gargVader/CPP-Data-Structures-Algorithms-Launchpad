// Submatrix sum query on a matrix


#include<iostream>
#define MAX 100
using namespace std;

int main(){
	int row, column, sum=0;
	cout<<"Enter number of rows: "; cin>>row;
	cout<<"Enter number of columns: "; cin>>column;
	cout<<"Enter matrix"<<endl;
	
	int arr[MAX][MAX];
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			cin>>arr[i][j];
		}
	}
//	cout<<endl;
//	for(int i=0; i<row; i++){
//		for(int j=0; j<column; j++){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=0; i<row; i++){
		for(int j=1; j<column; j++){
			arr[i][j]+=arr[i][j-1];
		}
	}	
	for(int j=0; j<column; j++){
		for(int i=1; i<row; i++){
			arr[i][j] += arr[i-1][j];
		}
	}
	
//	for(int i=0; i<row; i++){
//		for(int j=0; j<column; j++){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	cout<<"Enter number of queries: ";
	int q; cin>>q;
	
	while(q--){
		int a,b,c,d; cin>>a>>b>>c>>d;
		
		int ans = arr[c][d];
		
		if(a>0){
			ans -= arr[a-1][d];
		}
		if(b>0){
			ans-=arr[c][b-1];
		}
		if(a>0 && b>0){
			ans += arr[a-1][b-1];
		}
		cout<<ans;
	}
	
}

