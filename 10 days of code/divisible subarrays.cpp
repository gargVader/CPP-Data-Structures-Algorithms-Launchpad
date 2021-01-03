// sub-arrays

#include<stdio.h>

int subarrayCount(int arr[], int n);
int main(){
	int ans[10];

	int t; scanf("%d", &t); // Number of test cases
	
	for(int i=0; i<t; i++){
		int n; scanf("%d", &n); // size of array
		int arr[100000];
		
		for(int j=0; j<n; j++) // taking array input
			scanf("%d", &arr[j]);
			
		int count = subarrayCount(arr, n);
		ans[i] = count;	
	}
	
	for(int i=0; i<t; i++){
		printf("%d\n", ans[i]);
	}
	
}

int subarrayCount(int arr[], int n){

	int count=0;
	for(int j=0; j<n; j++){
		int sum=0;
		for(int i=j; i<n; i++){
			sum += arr[i];
//			printf("%d ", sum);
			if(sum%n==0)
				count++;
		}
//		printf("\n");
	}
	
	return count;
}

