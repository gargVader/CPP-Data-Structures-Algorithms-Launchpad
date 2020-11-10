// Orientation of 3 ordered points a,b,c
// anti-clockwiae, clockwise, collinear

#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[2], b[2], c[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>c[0]>>c[1];
	
	float slope1 = (c[1]-a[1])/(c[0]-a[0]);
	float slope2 = (b[1]-a[1])/(b[0]-a[0]);
	
	if(slope1==slope2) cout<<"colliniear";
	if(slope1<slope2) cout<<"clockwise";
	else cout<<"anti-clockwise";
	
}


