// max subarray sum
// Kadane's Algorithm
// -4 1 3 -2 6 2 -1 -4 -7
#include<climits>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	int n; cin>>n;
	int arr[1000]={0};
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	// Kadane's algorithm
	int maximum = INT_MIN, curr=0;
	
	for(int i=0;i<n; i++){
		curr += arr[i];
		maximum = max(curr, maximum);
		
		if(curr<0){
			curr=0;
		}
		
	}

	cout<<maximum<<endl;
}

