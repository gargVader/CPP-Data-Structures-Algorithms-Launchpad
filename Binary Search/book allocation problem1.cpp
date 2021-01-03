#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

bool isPoss(int max, int arr[], int n, int m){
	int sum=0, i=0;
	
	while(i<n && m>0){
		
		sum+=arr[i];
		if(sum>max){
			sum=0;
			m--; i--;
		}
		i++;
	}
	if(i==n && m>0) return 1;
	else return 0;
	
	
//	for(int i=0; i<n; i++){
//		sum+=arr[i];
		
//		if(m>0){
//			if(sum<=max){
//				cout<<"sum="<<sum<<" is poss"<<endl;
//			}
//			else{
//				cout<<"sum="<<sum<<" is not poss"<<endl;
//				sum=0;
//				m--;
//			}
//		}
//		else{
//			return 0;
//		}
//	}
//	
//	return 1;
}

void solve(int arr[], int n, int m){
	
	int s=arr[0], e=INT_MAX, mid, ans;
	
	while(s<=e){
		mid = (s+e)/2;
		// check if there exists a configuration where the maximum number of pages that can be assigned to a student is less than equal to mid
		cout<<"s="<<s<<" e="<<e<<" mid="<<mid<<endl;
		if(isPoss(mid, arr, n, m)){
			// if yes, then I will have to challenge myself to minimise that maximum number
			cout<<mid<<" IS POSSIBLE"<<endl;
			ans = mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ll t; cin>>t;
	while(t--){
		int n, m, arr[MAX];
		cin>>n>>m;
//		cout<<"Inputting"<<endl;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
//		cout<<"Input taken"<<endl;
		solve(arr, n, m);
	}
}


