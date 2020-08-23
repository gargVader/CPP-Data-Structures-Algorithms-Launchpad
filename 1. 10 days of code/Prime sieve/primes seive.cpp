#include<stdio.h>
#define ll long long
// function to calculate prime numbers upto 1000000
void prime_sieve(int *p){
	
	// all odd numbers may be prime
	for(int i=3; i<=1000000; i+=2){
		p[i]=1; 
	}
		
	for(ll i=3; i<=1000000; i+=2){
		// if i is prime
		if(p[i]==1){
			// all multiples of i must be non prime
			for(ll j=i*i; j<=1000000; j+=i){
				p[j]= 0;
			}
		}
	}
		
	// special case
	p[0] = 0;
	p[1] = 0;
	p[2] = 1;

}

int main(){
	printf("yes");
	int n;
	scanf("%d", &n);
	
	int p[1000005] = {0}; // initialising all to NOT PRIME
	prime_sieve(p);
	
	// Printing the first n prime numbers
	for(int i=0; i<=n; i++){
		if(p[i]==1)
			printf("%d\n", i);
	}
}

