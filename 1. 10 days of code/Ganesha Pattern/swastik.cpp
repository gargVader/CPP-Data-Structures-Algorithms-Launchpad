//*  ****
//*  *
//*  *
//*******
//   *  *
//   *  *
//****  *

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,space,j, i;
	scanf("%d", &n);
	
	
		
		
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf(" ");
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf("*");
			printf("*\n");
		
		
		for(i=0; i<(n-3)/2; i++){
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf(" ");
			printf("*\n");
		}
		
		
			for(j=0; j<n; j++)
				printf("*");
			printf("\n");
		
				
		for(i=0; i<(n-3)/2; i++){
			printf(" ");
			for(space=0; space<(n-3)/2; space++)
				printf(" ");
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf(" ");
			printf("*\n");
		}
		
		
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf("*");
			printf("*");
			for(space=0; space<(n-3)/2; space++)
				printf(" ");
			printf("*\n");
				
	
}

