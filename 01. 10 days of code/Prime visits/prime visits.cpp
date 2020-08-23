#include<stdio.h>
#define ll long

void primeSeive(int *p){
	
	//all even numbers starting from 3 may be prime
	for(int i=3; i<=1000000; i=i+2){
		p[i] =1;
	}
	
	// special cases
	p[2] = 1;
	
	for(ll i=3; i<=1000000; i+=2){
		// if number is prime
		if(p[i]==1){
			// set all multiples of this number as NON PRIME
			for(ll j=i*i; j<=1000000; j+=i){
				p[j] = 0;
			}
		}
	}
}

int main(){
	int n, ans[1000];
	scanf("%d", &n);
	int p[1000005]={0};
	primeSeive(p);
	
	for(int i=0; i<n; i++){
		int a,b;
		scanf("%d%d", &a,&b);
		
		int count =0;
		for(int i=a; i<=b; i++){
			if(p[i]==1){
				count++;
			}
		}
		ans[i] = count;
	}
	
	for(int i=0; i<n; i++){
		printf("%d\n", ans[i]);
	}		
}

