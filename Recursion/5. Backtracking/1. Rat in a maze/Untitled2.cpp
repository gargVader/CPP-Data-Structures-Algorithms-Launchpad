#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
#define ROW 100
#define COL 100
using namespace std;

int row=4, col=4, counter=0;
char maze[ROW][COL] = {
						"00X0",
						"00X0",
						"000X",
						"0X00"
};

bool solve(string s, int i=0, int j=0){
	//Base Case
	if(i==row-1 && j==col-1){ // We have managed to reach the end. So print the path and return true
		cout<<s<<endl;
		counter++;
		return true;
	}
	
	if(maze[i][j]=='X'){ // If we have hit a obstacle then return false as we cannot pass it
		return false;
	}
	else{
		// Rec Case
		if(i<row-1){ // If from current pos it is possible to go down, then go down
			solve(s+'D', i+1, j);
		}
		if(j<col-1){ // If from current pos it is possible to go right, then go right
			solve(s+'R', i, j+1);
		}
	}

}

int main(){
	//cin>>row>>col;
	string s;
	solve(s); 
	if(counter!=0){
		cout<<counter;
	}
	else{
		cout<<"-1";
	}
	
}


