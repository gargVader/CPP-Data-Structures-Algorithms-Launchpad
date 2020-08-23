#include<bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;

bool isSafe(int nextX, int nextY, bool visited[][8]){
	if(nextX>=0 && nextX<=7 && nextY>=0 && nextY<=7){
		if(visited[nextX][nextY]!=true){
			return 1;
		}
	}
	return 0;
}

void printSolution(int ans[][8]){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<ans[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void solve(int currX, int currY, bool visited[][8], int ans[][8], int count){
	
	// Base case
	if(count==63){
		//cout<<count<<endl;
		printSolution(ans);
		return;
	}
	
	// Option 1: UP LEFT
	if(isSafe(currX-1, currY+2, visited)){ //cout<<"option1"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX-1, currY+2, visited, ans, count+1);
		
		visited[currX][currY]=0;
		//ans[currX-1][currY+2] = 0;
	}
	
	// Option 2: UP RIGHT
	if(isSafe(currX+1, currY+2, visited)){ //cout<<"option2"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX+1, currY+2, visited, ans, count+1);
		
		visited[currX+1][currY+2]=0;
		//ans[currX+1][currY+2] = 0;
	}
	
	// Option 3: DOWN LEFT
	if(isSafe(currX-1, currY-2, visited)){ //cout<<"option3"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX-1, currY-2, visited, ans, count+1);
		
		visited[currX-1][currY-2]=0;
		//ans[currX-1][currY-2] = 0;
	}
	
	// Option 4: DOWN RIGHT
	if(isSafe(currX+1, currY-2, visited)){ //cout<<"option4"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX+1, currY-2, visited, ans, count+1);
		
		visited[currX+1][currY-2]=0;
		//ans[currX+1][currY-2] = count+1;
	}
	
	// Option 5: LEFT UP
	if(isSafe(currX-2, currY+1, visited)){ //cout<<"option5"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX-2, currY+1, visited, ans, count+1);
		visited[currX-2][currY+1]=0;
		//ans[currX-2][currY+1] = 0;
	}
	
	// Option 6: LEFT DOWN
	if(isSafe(currX-2, currY-1, visited)){ //cout<<"option6"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX-2, currY-1, visited, ans, count+1);
		visited[currX-2][currY-1]=0;
		//ans[currX-2][currY-1] = 0;
	}
	
	// Option 7: RIGHT UP
	if(isSafe(currX+2, currY+1, visited)){ //cout<<"option7"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX+2, currY+1, visited, ans, count+1);
		
		visited[currX+2][currY-1]=0;
		//ans[currX+2][currY-1] = 0;
	}
	
	// Option 8: RIGHT DOWN
	if(isSafe(currX+2, currY-1, visited)){ //cout<<"option8"<<endl;
		visited[currX][currY]=1;
		ans[currX][currY] = count;
		
		solve(currX+2, currY-1, visited, ans, count+1);
		
		visited[currX-2][currY-1]=0;
		//ans[currX-2][currY-1] = 0;
	}
	
	// Bac0ktracking
	visited[currX][currY]=0;
}

int main(){
	int count = 0;
	int ans[8][8]={0};
	
	bool visited[8][8] = {0};
	
	solve(0, 0, visited, ans, count);
}


