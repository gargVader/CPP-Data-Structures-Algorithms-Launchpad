#include<stdio.h>
#include<math.h>

int main(){
	int n, count=0,i=1;
	scanf("%d", &n);
	
	while(n/pow(5,i)!=0){
		count += n/pow(5,i);
		i++;
	}
	printf("%d", count);
}

