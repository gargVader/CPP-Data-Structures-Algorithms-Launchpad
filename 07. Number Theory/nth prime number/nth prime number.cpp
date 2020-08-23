#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 1000000
using namespace std;
vector<ll> primes;

void primesGen(){
	
	bitset<MAX> arr; arr.reset();
	arr[2]=1;
	// All odd numbers may be primes
	for(ll i=3; i<MAX; i+=2){
		arr[i]=1;
	}
	
	for(ll i=3; i<MAX; i+=2){
		// If number is prime
		if(arr[i]){
			// Mark all its multiples as non-prime
			for(ll j=i*i; j<MAX; j+=i){
				arr[j]=0;
			}
		}
	}
	
	primes.push_back(2);
	for(ll i=3; i<MAX; i+=2){
		if(arr[i]){
			primes.push_back(i);
		}
	}
}

int main(){
	primesGen();
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<primes[n-1]<<endl;
	}
}


