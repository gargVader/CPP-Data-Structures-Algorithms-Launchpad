// Aggresive Cows
// SPOJ AGGRCOW

#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
#define MAX 1000000
#define ll long long
using namespace std;

//bool isPoss(ll dist, ll arr[], ll n, ll c){
//	// cout<<"Dist to be checked"<<dist<<endl;
//	bool ans=true;
//    ll chosen=0; c--;
//	for(ll i=1; i<n; i++){
//
//        if(c){
//            while(arr[i]-arr[chosen]<dist){
//                // cout<<"Comaparing "<<arr[i]<<" and "<<arr[chosen]<<endl;
//                i++;
//                if(i>=n)
//                    break;
//            }
//            if(i<n){
//                // cout<<"chosen changed to "<<i<<endl;
//                chosen = i; c--;
//            }
//            else{
//                ans=false;
//                break;
//            }
//            
//        }
//    }
//	return ans;
//	
//}

bool isPoss(ll dist, ll arr[], ll n, ll c){
	ll i=1, chosen=0; c--;
	while(c!=0 && i<n){
        // cout<<"c="<<c<<" i="<<i<<endl;
        // cout<<"Comparing "<<arr[i]<<" and "<<arr[chosen]<<" for dist="<<dist<<endl;
		if(arr[i]-arr[chosen]>=dist){
			chosen=i; i++; c--;
		}
		else{
			i++;
		}
	}
	
	if(c==0){
		return 1;
	}
	else{
		return 0;
	}
}


ll maxMinDist(ll arr[], ll n, ll c){
	ll s=0, e=arr[n-1]-arr[0], mid, ans;
		
	while(s<=e){
		mid=(s+e)/2;
		if(isPoss(mid, arr, n, c)){
            ans=mid;
            // cout<<mid<<" is poss"<<endl;
			s=mid+1;
		}
		else{
            // cout<<mid<<" is not poss"<<endl;
			e=mid-1;
		}
	}
	return ans;
}

int main(){
	ll t; cin>>t;
	while(t--){
		ll n, c; cin>>n>>c;
		ll arr[MAX]={0};
		
		for(ll i=0; i<n; i++){
			cin>>arr[i];
		}
		
		sort(arr, arr+n);
        // cout<<"sorted array";
        // for(ll i=0; i<n; i++){
		// 	cout<<arr[i]<<" ";
		// }
        // cout<<endl;
		
		ll ans = maxMinDist(arr, n, c);
		
		cout<<ans<<endl;
		
	}
}


