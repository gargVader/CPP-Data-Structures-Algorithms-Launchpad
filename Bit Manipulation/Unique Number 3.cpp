// Unique Number 3

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int main(){	
	int n; cin>>n;
	int count[64]={0};
	
	for(int i=0; i<n; i++){
		int curr; cin>>curr;
		// Update the count array
		int j=0; 
		while(curr>0){
			int last_bit = curr&1;
			count[j]+= last_bit;
			curr = curr>>1;
			j++;
		}
	}
	
	int ans = 0, pow=1;
	for(int i=0; i<64; i++){
		count[i]%=3;
		ans += (count[i])*pow;
		pow = pow*2;
	}
	
	cout<<ans;
	
	
}


