// EKO Spoj

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 1000005
using namespace std;

bool isPoss(ll h, ll arr[], ll n, ll m){
	ll up = upper_bound(arr, arr+n, h) - arr;
	ll wood=0;
	for(ll i=up; i<n; i++){
		wood+=arr[i]-h;
		if(wood>=m){
			return 1;
		}
	}
	
	if(wood>=m){
		return 1;
	}
	else{
		return 0;
	}
	
}

void solve(ll n, ll m, ll arr[]){
	
	ll s=0, e=INT_MAX, mid, ans;
	
	while(s<=e){
		mid = (s+e)/2;
		// cout<<"s="<<s<<" e="<<e<<" mid="<<mid<<endl;
		if(isPoss(mid, arr, n,m)){
			// cout<<mid<<"IS POSSIBLE"<<endl;
			ans = mid;
			s=mid+1;
		}
		else{
			// cout<<mid<<"IS NOT POSSIBLE"<<endl;
			e=mid-1;
		}
	}
	cout<<ans;
}

int main(){
	ll n, m; 
	// cin>>n>>m;
	scanf("%lld%lld", &n, &m);
	ll arr[MAX];
	for(ll i=0; i<n; i++){
		// cin>>arr[i];
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr+n);
	
	solve(n, m, arr);
}


