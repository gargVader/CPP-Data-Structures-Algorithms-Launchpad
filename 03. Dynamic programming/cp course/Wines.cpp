// Wines problem

#include<iostream>
#define ll long long
using namespace std;

int profit(int i, int j, int p[], int dp[]){
	int year = 1;
	//Base Case
	if(i>j){
		return 0;
	}
		
	//Lookup
	if(dp[])
	
	
	else{
		int op1 = p[i]*year + profit(i+1, j, year+1);
		int op2 = p[j]*year + prfit(i, j-1, year+1);
		
		return dp[i]	
	}
}

int main(){
	int p[] = {2,3,5,1,4};
	int n = sizeof(p)/sizeof(p[0]);
	int i=0, j=n;
	int dp[100] = {0};
	f(i,j,p,dp);
	
}

