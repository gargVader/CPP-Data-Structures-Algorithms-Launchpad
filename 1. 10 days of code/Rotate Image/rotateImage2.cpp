#include<stdio.h>

void swap(int *a, int *b);
int main(){
	int n;
	scanf("%d", &n);
	int mat[1000][1000];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	// reversing each row
	for(int i=0; i<n; i++){
		int j=0,k=n-1;
		while(k>j){
			swap(&mat[i][j],&mat[i][k]);
			j++; k--;
		}
	}
	
	// transposing matrix
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j>i){
			    swap(&mat[i][j],&mat[j][i]);
			}
		}
	}
	
	// printing
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
		
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

