#include<stdio.h>

void gcd(long int dividend, long int divisor){
	long int rem;
	do{
		rem = dividend%divisor;
		dividend = divisor;
		divisor = rem;
	}while(rem!=0);
	printf("%ld", dividend);
}
int main(){
	long int a,b;
	scanf("%ld%ld", &a,&b);
	
	if(a>b)
		gcd(a,b);
	else
		gcd(b,a);
}

