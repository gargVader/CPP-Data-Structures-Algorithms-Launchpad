#include<iostream>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100
using namespace std;

// is a configuration possible where every student reads less than mid pages
bool isPoss(int mid, int arr[], int n, int m){
	
	int i=0, sum=0;
	while(m!=0 && i<n){
		if(sum<=mid){
			sum+=arr[i]; i++;
		}
		else{
			m--;
			sum=0;
		}
	}
	if(m==0 && i==n-1){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		int arr[MAX];
		ll sum=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		
		int s=0, e=sum, mid, ans=INT_MAX;
		while(s<=e){
			mid=(s+e)/2;
			if(isPoss(mid, arr, n, m)){
				ans=mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}
		cout<<ans<<endl;
	}
}


