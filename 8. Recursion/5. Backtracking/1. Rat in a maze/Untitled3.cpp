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

bool solve(bool ans[][COL], int i=0, int j=0){
	//Base Case
	if(i==row-1 && j==col-1){ // We have managed to reach the end. So print the path and return true
		
		ans[i][j] = 1;
		
		// Print the solution matrix
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}cout<<endl;
		
		counter++;
		return true;
	}
	
	if(maze[i][j]=='X'){ // If we have hit a obstacle then return false as we cannot pass it		
		return false;
	}
	else{
		// Rec Case
		if(i<row-1){ // If from current pos it is possible to go down, then go down
			// But first mark our curr pos as true
			ans[i][j] = 1;
			solve(ans, i+1, j);
		}
		if(j<col-1){ // If from current pos it is possible to go right, then go right
			// But first mark our curr pos as true
			ans[i][j] = 1;
			solve(ans, i, j+1);
		}
	}
	
	// Backtracking
	ans[i][j] = 0;

}

int main(){
	//cin>>row>>col;
	
	bool ans[ROW][COL]={0};
	
	solve(ans);
	
	if(counter==0){
		cout<<"Path doesnot exist!";
	}else{
		cout<<counter;
	}

	
}


