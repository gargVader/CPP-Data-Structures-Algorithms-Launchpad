// Square root using binary search

#include<iostream>
using namespace std;

int sqrt(int n){
	
	int s=0, e=n, mid, ans;
	while(s<=e){
		mid=(s+e)/2;
		if(mid*mid==n){
			return mid;
		}
		if(mid*mid>n){
			e = mid-1;
		}
		if(mid*mid<n){
			ans=mid;
			s = mid+1;
		}
	}
	return ans;
}

int main(){
	int n; cin>>n;
	int ans = sqrt(n);
	cout<<ans;
}


