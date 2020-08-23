#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, int i, int j){
	
	int a=-1; a=a<<i; a=~a; // 0000000011
	int b=-1; b=b<<j+1; // 	   1110000000
	int mask = a|b;  	//	   1110000011
	
	// bits cleared
	n = n&mask;
	// set new bits
	m = m<<i; 
//	000 10101 00 biwise or with n;
	n = n|m;
	return n;
}

int main(){
	int n=15, m=2, i=1, j=3;
	
	int ans = solve(n,m,i,j);
	
	cout<<ans;
}


