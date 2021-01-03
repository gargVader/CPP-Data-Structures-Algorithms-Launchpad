// Finding unique element while all others occur twice

#include<iostream>
#define ll long long
using namespace std;

int main(){
	
	int n; cin>>n;
	int ans=0, num;
	while(n--){
		cin>>num;
		ans = ans^num; 
	}
	
	cout<<ans;

}

