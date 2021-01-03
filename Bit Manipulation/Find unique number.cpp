// Given an array of numbers where every numbers occcurs twice except for one. Find the unique number

#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

int main(){
	int n; cin>>n;
	int ans = 0;
	
	while(n--){
		int curr; cin>>curr;
		ans^=curr;
	}
	cout<<ans;
	
}


