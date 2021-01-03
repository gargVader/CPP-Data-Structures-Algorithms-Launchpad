// ultra fast mathematicians

#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

int main(){
	int t; cin>>t;
	
	while(t--){
		char a[100], b[100];
		cin>>a>>b;
		int n = strlen(a);
		int i;
		for(i=0; i<n-1; i++){
			if(a[i]==b[i]){
				a[i]='0';
			}
			else{
				a[i]='1';
			}
		}
		
		cout<<a;
			
	}
}

