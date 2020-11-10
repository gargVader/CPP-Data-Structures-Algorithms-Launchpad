// sliding window
// Buying plots
// Minimum length subarray whose sum is exactly K

#include<iostream>
#include<climits>
using namespace std;

int main(){
	int arr[]={2,3,1,2,4,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=7;
	int rsum=0, length, minLength=INT_MAX;
	
	int left=0, right=0;
	
	while(right<n){
		if(rsum>k){
			rsum-=arr[left];
			left++;	
		}
		if(rsum<k){
			rsum+=arr[right];
			right++;
		}
		if(rsum==k){
			rsum=0;
			length=right-left+1;
			minLength= min(length, minLength);
			left++;
		}
	}
	
	cout<<minLength;
	
	
}

