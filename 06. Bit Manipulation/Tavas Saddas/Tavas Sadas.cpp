#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n; cin>>n;
	ll ans=0, p=1;
	int length=0;
	
	while(n>0){
		int digit = n%10;
		if(digit==4){
			ans+= 0*p;
		}
		else{
			ans+= 1*p;
		}
		p=p*2;
		n=n/10;
		length++;
	}
	ans++;
	
	ans += pow(2, length) - 2;
	
	cout<<ans;
	
}


