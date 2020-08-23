// Alternative selection sort

#include<stdio.h>
#define MAX 100

void selectionSort(int arr[], int n);
int main(){
	int arr[MAX], i, n;
	
	printf("Enter size of array: "), scanf("%d", &n);
	
	//taking input
	for(i=0; i<n; i++){
		printf("Enter number %d: ", i); scanf("%d", arr+i);
	}
	
	// display array
	printf("arr = [");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("]");
	
	selectionSort(arr, n);
	
	// display sorted array
	printf("\n");
	printf("Sorted arr = [");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("]");
		
}

void selectionSort(int arr[], int n){
	
	int i,j,min;
	
	for(j=0; j<n; j++){
		min = arr[j];
		for(i=j; i<n; i++)
			if(arr[i]<min){
				min = arr[i];
				arr[i]=arr[j];
				arr[j]=min;
			}
	}
}

