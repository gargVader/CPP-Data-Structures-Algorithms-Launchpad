// express num as the sum of powers of 2 such that number ...
// of terms used is minimum

#include<stdio.h>


void minMoves(long int num);
int main(){
	long int n[10]; // stores test cases
	int t,i; // number of test cases
	
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%ld", n+i);
	}
	
	for(i=0; i<t; i++)
		minMoves(n[i]);
}


void minMoves(long int num){
	int sum=0, digit;
	while(num!=0){ 
		digit=num%2;
		sum += digit;
		num=num/2;
	}
	printf("%d\n", sum);
	
	
}

