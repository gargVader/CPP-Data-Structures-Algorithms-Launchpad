// Activity Selection Problem
//1
//3
//10 20
//12 15
//20 30
#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
	return a.second<b.second;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		pair<int, int> arr[MAX];
		for(int i=0; i<n; i++){
			cin>>arr[i].first>>arr[i].second;
		}
		
		sort(arr, arr+n, compare);
		int count=1, chosen=0, curr=1;
		for(int curr=1; curr<n; curr++){
			cout<<arr[chosen].second<<"  "<<arr[curr].first<<endl;
			if(arr[chosen].second<=arr[curr].first){
				count++;
				chosen=curr;
			}
			
		} 
		cout<<count<<endl;
		
		
	}
}

