#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 500
using namespace std;
 
// is it possible to cook p parathas in time time, given l, rank
bool isPoss(ll time, ll p, ll l, ll rank[]){
	ll arr[10000];
	for(ll i=0; i<10000; i++){
		arr[i] = i*(i+1)/2;
	}
	
//	for(ll i=0; i<20; i++){
//		cout<<arr[i]<<" ";
//	}cout<<endl;
	
	for(ll i=0; i<l; i++){
		ll temp = time/rank[i];
		// out of arr, i want the index of the number which is less than equal to temp
		ll lb;
		if(binary_search(arr, arr+10000, temp)){
			lb = lower_bound(arr, arr+10000, temp) - arr;
		}
		else{
			lb = lower_bound(arr, arr+10000, temp) - arr-1;
		}
//		cout<<"temp="<<temp<<" p="<<p<<" lb="<<lb<<endl;
		p = p-lb; 
		
		if(p<=0){
			return 1;
		}
	}
	
	return 0;
}
 
int main(){
	ll t; cin>>t;
	while(t--){
		ll p, l; cin>>p>>l;
		ll arr[MAX];
		for(ll i=0; i<l; i++){
			cin>>arr[i];
		}
		sort(arr, arr+l);
		ll s=0, e=8*p*(p+1)/2, mid;
		ll ans;
		while(s<=e){
			ll mid = (s+e)/2;
//			cout<<s<<" "<<e<<endl;
			if(isPoss(mid, p, l, arr)){
//				cout<<mid<<" is poss"<<endl;
				ans=mid;
				e=mid-1;
			}
			else{
//				cout<<mid<<" is not poss"<<endl;
				s=mid+1;
			}
		}
		
		cout<<ans<<endl;
	
	}
}
