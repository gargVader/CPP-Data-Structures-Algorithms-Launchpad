// Inclusion exclusion principle

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

ll solve(ll n, int primes[], int size){

	ll ans=0;
	for(ll i=1; i<(1<<size); i++){
		
		ll subset=1, sign=-1;
		ll num = i, index=0;
		
		while(num>0){
			int last_bit = num&1; num=num>>1;
			int p = primes[index++];
			if(last_bit){
				subset*=p;
				sign*=-1;
			}
			
		}

		if(subset!=1){
			ans+= sign*(n/subset);
		} 
		
	}
	
	return ans;
	
}

int main(){
	int primes[]={2,3,5,7,11,13,17,19};
	int size = 8;
	
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		
		ll ans = solve(n, primes, size);
		cout<<ans<<endl;
	}
}


