//selection sort alternative approach

#include<stdio.h>

void selectionSort(int a[], int n){
	for(int i=0; i<n; i++){
		int min=i;
		// Find minimum element in array from i to n
		for(int j=i; j<n; j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		// swap(a[min], a[i])
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

int main(){
	int arr[10]={5,4,9,123,58,37,324,444,699,347};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	//selection sort
	selectionSort(arr,n);
	//printing the sorted array
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

