// please edit: change int to ll

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#include<vector>
#define ll long long
#define MAX 1000000
using namespace std;
vector<int> primes;

void primeGenerator(){
	int p[MAX]={0};
	p[2]=1;
	
	// All odd numbers may be prime
	for(int i=3; i<MAX; i+=2){
		p[i]=1;
	}
	
	primes.push_back(2);
	
	for(int i=3; i<MAX; i+=2){
		
		//if number is prime
		if(p[i]){
			// mark all its multiples as not prime
			for(int j=i*i; j<MAX; j+=i){
				p[j]=0;
			}
		}
	}
	
	for(int i=3; i<MAX; i+=2){
		if(p[i]){
			primes.push_back(i);
		}
	}
	
}

int numOfFactors(int n, vector<int> primes){
	if(n==0) return -1;
	
	int ans=1, count=0;
	
	int i=0, p=primes[i]; 
	
	for(; p*p<=n; i++){
		p=primes[i];
		while(n%primes[i]==0){
			count++;
			n=n/primes[i];
		}
		ans *= count+1;
		count=0;
	}
	
	if(n!=1){
		ans*=2;
	}
	
	return ans;
	
}

int main(){
	
	primeGenerator();
	
	int n; cin>>n;
	
	int ans = numOfFactors(n, primes);
	if(ans==-1){
		cout<<"Infinite"; return 0;
	}
	cout<<ans;
	
}


