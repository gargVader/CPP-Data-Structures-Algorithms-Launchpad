// O(n)

#include<bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n){
	// Largest in the array
	int largest = *max_element(arr, arr+n);
	
	// create a freq array
	int freq[largest+1]={0};
	
	for(int i=0; i<n; i++){
		freq[arr[i]]++;
	}
	
	// put the elements back into arr by reading the freq array
	int j=0;
	for(int i=0; i<=largest; i++){
		while(freq[i]){
			arr[j] = i;
			j++; freq[i]--;
		}
	}
}


int main(){
	int arr[] = {88,97,10,12,15,1,5,6,12,5,8};
	int n =sizeof(arr)/sizeof(arr[0]);
	
	counting_sort(arr, n);
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
