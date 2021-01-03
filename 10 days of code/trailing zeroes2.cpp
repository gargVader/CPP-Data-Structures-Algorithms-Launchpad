#include<stdio.h>

int main(){
	int n, count=0,power, copy;
	scanf("%d", &n);
	
	while(n!=1){
		
		copy = n;
		while(copy%5==0){
			count++;
			copy=copy/5;
		}
		
		n--;
	}
	printf("%d", count);
}

