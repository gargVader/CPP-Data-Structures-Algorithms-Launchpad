#include<stdio.h>

int main(){
	int n, count=0, fact=1; 
	
	scanf("%d", &n);
	
	while(n!=0){
		fact=fact*n;
		n--;
	}
	
	while(fact%10==0){
		count++;
		fact=fact/10;
	}
	
	printf("%d", count);
}

