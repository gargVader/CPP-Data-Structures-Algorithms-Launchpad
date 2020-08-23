#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
#define modulo 1000000007
using namespace std;

void clearRange(ll &num, ll i, ll j){
	ll a=-1; a=a<<i; a=~a;
	ll b=-1; b=b<<j+1;
	ll mask=a|b;
	num = num&mask;
}

void setRange(ll &num, ll i, ll j){
	clearRange(num, i, j);
	ll a=-1; a=a<<(j-i+1); a=~a; a=a<<i;
	num = num|a;
}

ll findnum(ll num, ll i, ll j){
	
	num = num>>i;
	ll mask=-1; mask = mask<<(j-i+1); mask=~mask;
	num = num&mask;
	
	ll ans=0, p=pow(2, j-i);
	
	while(num>0){
		ll last_bit = num&1;
		ans+= (last_bit*p)%modulo;
		p=p/2;
		num=num>>1;
	}
	
	return ans;
}

int main(){
	ll n, q; cin>>n>>q;
	
	ll num=0;
	
	while(q--){
		ll choice, l, r; cin>>choice>>l>>r;
		
		if(choice==0){
			clearRange(num, n-r-1, n-l-1);
//			cout<<"Updated num after clearing is"<<num<<endl;
		}
		else if(choice==1){
			setRange(num, n-r-1, n-l-1);
//			cout<<"Updated num after setting is"<<num<<endl;
		}
		else if(choice==2){
			cout<<findnum(num, n-r-1, n-l-1)<<endl;
		}
	}
	
//	cout<<findnum(15, 2, 2);
}


