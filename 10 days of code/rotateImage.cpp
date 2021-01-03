#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int i, j, mat[1000][1000];
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(j=n-1; j>=0; j--){
		for(i=0; i<n; i++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

