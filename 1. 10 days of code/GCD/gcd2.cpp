#include<stdio.h>

long int gcd(long int a, long int b){
	return b==0? a: gcd(b,a%b);
}
int main(){
	long int a,b, ans;
	scanf("%ld%ld", &a,&b);
	
	ans = (a>b)? gcd(a,b):gcd(b,a);
	
	printf("%ld", ans);
}
