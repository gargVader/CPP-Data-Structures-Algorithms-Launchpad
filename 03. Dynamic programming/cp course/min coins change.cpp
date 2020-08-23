#include<iostream>
#include<climits>
#define ll long long
using namespace std;

// coins = [1,7,10]

int minChange(int n, int dp[]){
	if(n==0){
		return 0;
	}
	
	// Lookup
	if(dp[n]!=0){
		return dp[n];
	}
	
	else{
		int op1, op2, op3;
		op1=op2=op3=INT_MAX;
		
		if(n-1>=0) op1=minChange(n-1, dp);
		if(n-7>=0) op2=minChange(n-7, dp);
		if(n-10>=0) op3=minChange(n-10, dp);
		
		return dp[n] = min(min(op1,op2), op3)+1; 
	}
}

int bottomUp(int n){
	int dp[100]={0};
	
	for(int i=1; i<=n; i++){
		int op1, op2, op3;
		op1=op2=op3=INT_MAX;
		
		if(i-1>=0) op1=dp[i-1];
		if(i-7>=0) op2=dp[i-7];
		if(i-10>=0) op3=dp[i-10];
		
		dp[i] = min(min(op1,op2), op3)+1;
	}
	
	return dp[n];
}

int main(){
	int dp[100]={0};
	int n;
	cin>>n;
	
	int ans = minChange(n, dp);
	cout<<ans<<endl;
	
	ans = bottomUp(n);
	cout<<ans;
}

