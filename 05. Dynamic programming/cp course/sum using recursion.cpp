// sum using recursion

#include<iostream>
using namespace std;

int sum(int arr[], int n){
	//Base case
	if(n==0){
		return arr[0];
	}
	
	return sum(arr, n-1)+arr[n];
}

int main(){
	int arr[]={1,2,3,4,44,99,73,6,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	// using recursion
	int ans = sum(arr, n);
	cout<<"sum is: "<<ans<<endl;
	
	//using tarditional method
	int ans2 = 0;
	for(int i=0; i<n; i++){
		ans2 +=arr[i];
	}
	cout<<"sum is: "<<ans2;
	
}

