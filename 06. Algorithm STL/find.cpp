// algorithm STL
// find function

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=10;
	int *it = find(arr, arr+n, key);
	int index = it-arr;
	if(index<n){
		cout<<"Value found at "<<index;
	}
	else{
		cout<<"Not found";
		cout<<index;
	}
	
}

