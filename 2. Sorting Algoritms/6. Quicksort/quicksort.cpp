// Quicksort 

#include<iostream>
using namespace std;

int partition(int a[], int s, int e){
	
	// Inplace(Cant take extra array)
	int i=s-1;
	int j=s;
	int pivot = e;
	
	for(j=s; j<=e-1; j++){
		if(a[j]<=a[pivot]){
			// merge the smaller elemet in the region-1
			i++;
			swap(a[i], a[j]);
		}
		// expand the larger region
	}
	
	//place the pivot elemet in the correct index
	swap(a[pivot], a[i+1]);
	
	return i+1; //return the index of pivot element
}

void quicksort(int a[], int s, int e){
	// Base case
	if(s>=e){
		return;
	}
	
	int p = partition(a, s, e);
	
	quicksort(a,s,p-1);
	quicksort(a, p+1, e);
}

int main(){
	int a[]={2,34,45,1,44,9,3,12,332,95,91,78,45,87,3};
	int n = sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, n-1);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	
}

