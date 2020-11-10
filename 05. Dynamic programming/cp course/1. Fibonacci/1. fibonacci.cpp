// Dynamic programming
// nth term of Fibonacci series
// 1. Using recursion: O(2^n)
// 2. using dynamic programming: O(n)

#include<iostream>
using namespace std;

// TOP DOWN APPROACH (Recursion+Memoisation) 
// Time:O(n), Space:O(n)
int fibTopDown(int n, int dp[]){
	//Base case
	if(n==0 or n==1)
		return n;
	
	//Recursive
	if(dp[n]!=0){ // Lookup
		return dp[n];
	}
	
	int ans;
	ans = fibTopDown(n-1, dp) + fibTopDown(n-2, dp);
	
	return dp[n] = ans;
}

// Bottom up approach
// Time:O(n), Space:O(n)
int fibBottomUp(int n){
	int dp[100]={0};
	dp[1]=1;
	
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	return dp[n];
}

// Space Optimized Bottom up approach
// Time:O(n), Space:O(1)
int fibSpaceOptimized(int n){
	int dp[3]={0};
	dp[1] = 1;
	
	int i=2;
	while(i<=n){
		dp[2] = dp[0] + dp[1];
		dp[0]=dp[1];
		dp[1]=dp[2];
		i++;
	}
	
	return dp[2];		
}

// Matrix Exponentiation approach: EXTRA(NOT DP)
// Time:O(Log n)

int main(){
	int n;
	cin>>n;
	int dp[100]={0};
	
	int ans = fibTopDown(n, dp);
	int ans2 = fibBottomUp(n);
	int ans3 = fibSpaceOptimized(n);
	
	cout<<"Top Down Approach: "<<ans<<endl;
	cout<<"Bottom Up Approach: "<<ans2<<endl;
	cout<<"Space Optimized Bottom Up Approach: "<<ans3<<endl;
}

