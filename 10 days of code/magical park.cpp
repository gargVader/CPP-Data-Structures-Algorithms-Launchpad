//N, M, K, S

#include<iostream>
using namespace std;

void magicalpark(char park[][100], int n, int m, int k, int s);

int main(){
	int n,m,k,s;
	cin >> n >> m >> k >> s;
	
	char park[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> park[i][j];
		}
	}
	
	magicalpark(park, n,m,k,s);
}

void magicalpark(char park[][100], int n, int m, int k, int s){
	int i,j;
	bool success = true;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			
			if(s<k){success = false; break;}
			
			if(park[i][j]=='.'){s=s-2;}
			if(park[i][j]=='*'){s=s+5;}
			if(park[i][j]=='#'){break;}
			if(j!=m-1){ s--; }
		
		}
	}
	
	if(success){
		printf("Yes\n%d", s);
	}
	else{
		printf("No");
	}
}

