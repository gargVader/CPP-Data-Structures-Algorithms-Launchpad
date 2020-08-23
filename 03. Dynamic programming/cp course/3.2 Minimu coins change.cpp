#include<iostream>
#include<climits>
#define ll long long
using namespace std;
// Time: O(nt)

int minChange(int n, int t, int coins[], int dp[]){
	if(n==0)
		return 0;
	
	//Lookup	
	if(dp[n]!=0){
		return dp[n];
	}
	else{
		// there can many options depending on the size of coins[] matrix
		int ans = INT_MAX;
		for(int i=0; i<t; i++){
			if(n-coins[i]>=0){
				ans = min(ans, minChange(n-coins[i], t, coins, dp));
			}
		}
		// Once above loop is completed, i.e, all options have been seen
		return dp[n] = ans+1;
		
		
	}
	
}

int bottomUp(int n, int t, int coins[]){
	if(n==0){
		return 0;
	}
	int dp[100]={0};
	
	for(int i=1; i<=n; i++){
		int ans = INT_MAX;
		for(int j=0; j<t; j++){ // iterating through all coin values
			if(i-coins[j]>=0){
				ans = min(ans, dp[i-coins[j]]);
//				ans = min(ans, bottomUp(i-coins[j], t, coins));
//				Doing this will leave dp meaningless as we are again just doing recursion and nothing else
			}
		}
		dp[i] = ans+1;	
	}
	return dp[n];	
}

int main(){
	int coins[]={1,7,10};
	int t=sizeof(coins)/sizeof(coins[0]); // Number of coins
	
	int dp[100]={0};
	
	int n;
	cin>>n;
	
	int ans = minChange(n, t, coins, dp);
	cout<<ans<<endl;
	
	ans = bottomUp(n, t, coins);
	cout<<ans;
}
