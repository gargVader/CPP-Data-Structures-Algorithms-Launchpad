// Bubble sort

#include<stdio.h>
#define MAX 100

int main(){
	int arr[MAX], i,size, temp, j;
	
	// taking input
	printf("Enter size of array: "); scanf("%d", &size);
	for(i=0; i<size; i++){
		printf("Enter value for arr[%d]: ", i);
		scanf("%d", arr+i);
	}
	printf("\narr[] = ");
	for(i=0; i<size; i++){
		printf("%d ", *(arr+i));
	}
	
	for(i=0; i<size-1; i++){
		for(j=0; j=size-1-i; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
			
	//sorted array 
	printf("\nsorted arr[] = ");
	for(i=0; i<size; i++){
		printf("%d ", *(arr+i));
	}
	
	
}
