// Find number of set-bits
// N=13, 1101 . No. of set bits = 3


#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int sum=0;
	int loop_run=0;
// O(Logn+1)
//	while(n!=0){
//		sum+=n&1;
//		n = n>>1;
//		loop_run++;
//	}

//	while(n!=0){
//		sum+=n%2;
//		n=n/2;
//		loop_run++;
//	}

// Kadane's algo
//	while(n>0){
//		n=n&(n-1);	// Removes the last set-bit. So, the number of times it removes the set-bit, is the number of set-bits
//		sum++;
//	}
	sum = __builtin_popcount(n);

	cout<<sum<<endl;
	
	
	
}

