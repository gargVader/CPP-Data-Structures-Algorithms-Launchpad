// selection sort

#include<stdio.h>

int main(){
	int arr[10]={5,4,9,123,58,37,324,444,699,347};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

