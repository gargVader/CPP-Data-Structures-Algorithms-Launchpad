#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;

int row, col, counter=0;

void solve(string s, int i=0, int j=0){
	//Base Case
	if(i==row-1 && j==col-1){
		cout<<s<<endl;
		counter++;
		return;
	}
	
	// Rec Case
	if(i<row-1){
		solve(s+'D', i+1, j);
	}
	if(j<col-1){
		solve(s+'R', i, j+1);
	}
	
	
}

int main(){
	cin>>row>>col;
	string s;
	solve(s); cout<<counter;
}


