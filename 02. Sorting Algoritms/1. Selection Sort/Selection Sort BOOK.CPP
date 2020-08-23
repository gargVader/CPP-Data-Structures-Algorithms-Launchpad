//sorting algos in c:
//	1. Bubble-sort
//	2. Selection-sort
//	3. Insertion-sort
//	4. Shell-sort
//	5. Quick-sort
//	
//Searching algos in c:
//	1. Linear search
//	2. Binary search
	
// SELECTION SORT 

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
	

	// ASCENDING ORDER	
//	for(i=0; i<size-1; i++){
//		for(j=i+1; j<size; j++){
//			if(arr[i]>arr[j]){
//				temp = arr[i];
//				arr[i]=arr[j];
//				arr[j] = temp;
//			}
//		}
//		
//	}

	// DESCENDING ORDER
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if(arr[i]<arr[j]){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j] = temp;
			}
		}
		
	}	
	
	
	//sorted array 
	printf("\narr[] = ");
	for(i=0; i<size; i++){
		printf("%d ", *(arr+i));
	}
	
	
}
