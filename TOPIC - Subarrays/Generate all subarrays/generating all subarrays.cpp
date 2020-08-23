#include<iostream>
#define ll long long
using namespace std;

int main(){ int count=0;
	int arr[]={1,2,3,4,5,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	
//	for(int i=0; i<n; i++){// starting index
//		for(int length=1; length<=n-i; length++){
//			for(int j=i; j<i+length; j++){
//				cout<<arr[j]<<" ";
//			}
//			cout<<endl; count++;
//		}
//	}
//	
//	cout<<"count is "<<count;
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			for(int k=i; k<=j; k++){
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
	}
	
}

