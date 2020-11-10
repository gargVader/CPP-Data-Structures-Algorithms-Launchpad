#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#include<vector>
#define ll long long
#define MAX 1000000
using namespace std;
vector<ll> primes;

void primeGenerator(){
	bitset<MAX> p;
	p.reset();
	p[2]=1;
	
	// All odd numbers may be prime
	for(ll i=3; i<MAX; i+=2){
		p[i]=1;
	}
	
	primes.push_back(2);
	
	for(ll i=3; i<MAX; i+=2){
		
		//if number is prime
		if(p[i]){
			// mark all its multiples as not prime
			for(ll j=i*i; j<MAX; j+=i){
				p[j]=0;
			}
		}
	}
	
	for(ll i=3; i<MAX; i+=2){
		if(p[i]){
			primes.push_back(i);
		}
	}
	
}


bool isPrime(ll n){
	if(n<MAX){
		return binary_search(primes.begin(), primes.begin()+primes.size(), n);
	}
	for(ll i=0; primes[i]*primes[i]<=n; i++){
		if(n%primes[i]==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	
	primeGenerator();
	
	ll n; cin>>n;
	
	if(isPrime(n)) cout<<"Yes Prime";
	else cout<<"Not Prime";
}


