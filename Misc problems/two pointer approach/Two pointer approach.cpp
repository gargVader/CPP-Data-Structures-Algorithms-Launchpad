//Given a sorted array, find the pair of elements that sum to K(Given)
// Two pointer approach
// NOTE: Only works for sorted array
#include<iostream>
#define ll long long
using namespace std;

int main(){
	int arr[]={1,3,5,7,10,11,12,13};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=16;
	
	int i=0, j=n-1;
	
	while(i<j){
		if(arr[i]+arr[j] == k){
			cout<<arr[i]<<" "<<arr[j]<<endl;
			i++;
			j--;
		}
		
		if(arr[i] + arr[j] <k){
			i++;
		}
		
		if(arr[i] + arr[j] >k){
			j--;
		}
	}
	
	
	
}

