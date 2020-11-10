// Fast Modular Exponentiation

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastExp(ll a, ll b, ll m){
	ll ans=1;
	a=a%m;
	while(b>0){
		if(b&1){
			ans = (ans*a)%m;
		}
		a=(a*a)%m; 
		b=b>>1;	
	}
	return ans;
}

int main(){
	int a, b, m;
	cin>>a>>b>>m;
	
	cout<<fastExp(a,b,m);
}




