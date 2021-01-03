#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

int main(){
	ll x,y,z; cin>>x;

	if(x<3){
		cout<<"-1"; return 0;
	}
	
	if(x%2==0){
		y=abs(pow(x/2,2) - 1);
		z=abs(pow(x/2,2) + 1);
	}
	else{
		y=(x*x-1)/2;
		z=(x*x+1)/2;
	}
	
	if(y>z){
		cout<<z<<" "<<y;
	}
	else{
		cout<<y<<" "<<z;
	}
}

