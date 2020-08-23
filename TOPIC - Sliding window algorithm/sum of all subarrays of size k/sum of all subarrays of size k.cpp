// sliding window
// Motivation problem
// sum of all subarrays of size k

#include<iostream>
#define ll long long
using namespace std;

int main(){
	int arr[]={1,3,9,1,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int k=3;
	int sum=0;
	for(int i=0; i<k; i++){
		sum+=arr[i];
	}
	cout<<sum<<endl;
	for(int i=k; i<n; i++){
		sum=sum+arr[i]-arr[i-k];
		cout<<sum<<endl;
	}
	
}

