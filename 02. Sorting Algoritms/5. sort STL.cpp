#include<iostream>
#include<algorithm>
using namespace std;

// Define a comparator function
bool compare(int a, int b){
	return a>b;
}


int main(){
	int a[]={2,34,45,1,44,9,3,12,332,95,91,78,45,87,3};
	int n = sizeof(a)/sizeof(a[0]);
	
	// sort() function is much more efficient
 	sort(a,a+n, compare);
	
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}

