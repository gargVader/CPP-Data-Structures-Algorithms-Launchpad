// Meme Problem (CodeForces)
// Given a number K (K less than 1e16), find two numbers A and B such that AxB = K and A+B = K.

#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

int main(){
	int k; cin>>k;
	// x(k-x)
	int s=0, e=k/2, mid;
	
	while(s<=e){
		mid=(s+e)/2;
		int f = mid*(k-mid);
		if(f==k){
			cout<<mid<<" "<<(k-mid);
		}
		if(f<k){
			s=mid+1;
		}
		else{
			e=mid-1;
		}	
	}
	
	
}


