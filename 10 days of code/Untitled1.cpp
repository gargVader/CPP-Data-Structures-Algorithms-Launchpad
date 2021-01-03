// check if a given number is prime or not

#include<iostream>
#define ll long long
using namespace std;

bool primeCheck(int n){
	int p[1000000000]={0}; p[2]=1; // spl case
	
	//all odd numbers may be prime
	for(ll i=3; i<=n; i=i+2){
		p[i] = 1;
	}
	
	// traversing through all odd numbers
	for(ll i=2; i<=n; i++){
		if(p[i]==1){// if the number i has been marked prime
			// mark all multiples of i as non-prime
			for(ll j=i*i; j<=n; j+=i){
				p[j]=0;
			}
		}
	}
	
	return p[n];
}

int main(){
	int n; cin>>n;
	
	bool yesPrime=primeCheck(n);
	
	if(yesPrime){
		cout<<"Prime";
	}
	else{
		cout<<"Not Prime";
	}
	
}

