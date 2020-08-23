// max subarray sum
// Brute force
#include<climits>
#include<iostream>
#define ll long long
using namespace std;

int main(){
	int arr[]={-4,1,3,-2,6,2,-1,-4,-7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int max=INT_MIN;
	
	for(int i=0; i<n; i++){
		
		for(int j=i; j<n; j++){
			int sum=0;
			for(int k=i; k<j; k++){
				cout<<k<<" ";
				sum+=arr[k];
			}
			cout<<endl;
			if(max<sum){
				max = sum;
			}
		}
		
	}
	
	cout<<max;
	
}

