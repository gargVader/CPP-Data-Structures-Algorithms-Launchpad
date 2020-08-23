// Dynamic Memory Allocation in C++(new and delete)

#include<iostream>
using namespace std;

int main(){
	
	// Static Allocation
	int arr[5];
	cout<<"Size of static array of 5 elements: "<<sizeof(arr)<<endl;
	
	// Dynamic Allocation	
	int n; cout<<"Enter size of array: "; cin>>n;
	int *a = new int[n];
	cout<<"Size of pointer to dynamic array: "<<sizeof(a)<<endl;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	
	delete[] a;
	int *a = new int[n]{0};
}

