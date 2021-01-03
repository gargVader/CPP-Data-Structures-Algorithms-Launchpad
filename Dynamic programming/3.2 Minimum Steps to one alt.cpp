// Minimum steps to one: ALternative method
// n ==> 1 by using the following methods:
// n=> n/3 iff n%3==0
// n=> n/2 iff n%2==0
// n=> n-1

#include<iostream>
#include<climits>
#define MAX 200
using namespace std;

//Top Down
int minSteps(int n, int dp[]){
	// Base case
	if(n==1){
		return 0;
	}
	// Lookup 
	if(dp[n]!=0){
		return dp[n];
	}	
	//Rec case
	int op1, op2, op3;
	op1=op2=op3=INT_MAX;
	
	if(n%3==0){op1 = minSteps(n/3, dp);}
	if(n%2==0){op2 = minSteps(n/2, dp);}
	op3 = minSteps(n-1, dp);
	
	dp[n] = min(min(op1, op2), op3) + 1;
	return dp[n];
}

int BottomUp(int n){
	int dp[MAX]={0};
	//Base case
	dp[1] = 0;
	
//	if(dp[n]!=0){
//		return dp[n];
//	}
	
	for(int i=2; i<=n; i++){
		int op1, op2, op3;
		op1=op2=op3=INT_MAX;
		if(i%3==0){op1=BottomUp(i/3);}
		if(i%2==0){op2=BottomUp(i/2);}
		op3=BottomUp(i-1);
		
		dp[i] = min(min(op1, op2), op3) + 1;
	}
	
	return dp[n];
}


int main(){
	int dp[MAX]={0};
	int n;
	cout<<"Enter: ";
	cin>>n;
	
	int ans = minSteps(n, dp);
	cout<<"Top Down Approach: "<<ans<<endl;
	
	ans = BottomUp(n);
	cout<<"Bottom Up Approach: "<<ans;
}

