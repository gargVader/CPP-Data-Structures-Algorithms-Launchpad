#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

int main(){
	ll n,m,x,y;
	cin>>n>>m>>x>>y;
	
	ll st=0;
	
	n-= m/x; st+= m/x;
	m = m%x;
	
	while(n>0){
		if(m<x){
			n--;
			m+=y;
		}
		else{
			st+= (m/x>=n)? n:m/x;
			n-= m/x; 
			
			m = m%x;
		}
	}
	cout<<st;
	
}


