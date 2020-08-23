// Inclusion exclusion principle

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

int main(){
	int arr[MAX]={0};
	int primes[]={2,3,5,7,11,13,17,19};
//	for(int i=0; i<8; i++){
//		arr[primes[i]]=1;
//	}
	
	for(int i=0; i<8; i++){
		int p=primes[i];
		// mark all multiples of p as 1;
		for(int i=p; i<=MAX/p; i++){
			arr[i]=1;
		}
	}
	
	// prefix sum
	for(int i=1; i<MAX; i++){
		arr[i]+= arr[i-1];
	}
	
	
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<arr[n]<<endl;
	}
}


