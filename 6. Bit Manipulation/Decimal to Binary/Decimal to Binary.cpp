#include<bits/stdc++.h>
using namespace std;

void DecToBinary(int n){
	int ans=0, pow=1;
	while(n>0){
		ans+= (n&1)*pow;
		n = n>>1;
		pow=pow*10;	
	}
	cout<<ans;
}
int main(){
	int n; cin>>n;
	DecToBinary(n);
}


