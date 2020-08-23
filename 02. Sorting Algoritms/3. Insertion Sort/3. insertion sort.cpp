// insertion sort

#include<stdio.h>

int main(){
	int arr[13]={5,4,9,123,58,37,324,444,699,347, -1,0,200};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	for(int i=1; i<n; i++){
		int j=i-1;
		int curr = arr[i];
		while(j>=0 and arr[j]>curr){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=curr;
 	}
 	
 	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

