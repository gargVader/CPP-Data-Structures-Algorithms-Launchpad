#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#define ll long long
#define MAX 100000
using namespace std;
ll count=0;

typedef struct POINT{
	int x; int y;
}POINT;

// gives orientation of p->q->r
int orientation(POINT p, POINT q, POINT r){
	int m = (p.y-r.y)*(p.x-q.x) - (p.y-q.y)*(p.x-r.x);
	if(m>0) return 1;   // clockwise
	if(m<0) return -1;  // anti-clockwise
	else return 0;      // collinear
}


// Returns active points after forming hull
void formHull(POINT arr[], int n){
	if(n<3) return;
	
	vector<int> result;
	
	// find the leftmost point
	int start= 0;
	for(int i=0; i<n; i++){
		if(arr[start].x>arr[i].x){
			start = i;
		}
	}
	
	int curr = start;
	result.push_back(start); 
	
	while(1){
		int nextTarget = (curr+1)%n; 
		
		for(int i=0; i<n; i++){
			int o=orientation(arr[curr], arr[i], arr[nextTarget]);
			if(o==-1){
				nextTarget = i;
			} 
		}
		
		
		if(nextTarget==start) break;
		
		result.push_back(nextTarget);
		curr=nextTarget;
	}
	
	// result contains pos of all hull points
	for(int i=0; i<result.size(); i++){
		arr.erase(result[i]);
	}
		
}

void func(vector<POINT> activePoints, POINT candle){
	
	// we try to form convex hull by taking in candle point
	activePoints.push_back(candle);
	
	// if in the remaining points we have candle, count++;
	formHull(activePoints);
	
	if(binary_search(activePoints.begin(), activePoints.end(), candle)){
		count++;
		int pos = lower_bound(activePoints.begin(), activePoints.end(), candle) - activePoints.begin();
		activePoints.erase(pos);
		func(activePoints, candle);
	}
	else{
		return;
	}
	
	
}

void solve(){
	int n, q; cin>>n>>q;
	
	vector<POINT> activePoints;
	POINT candle;
	
	for(int i=0; i<n; i++){
		ll x,y; cin>>x>>y;
		activePoints.push_back({x,y});
	}
	
	while(q--){
		count=0;
		cin>>candle.x>>candle.y;
		
		func(activePoints, candle);
		cout<<count<<endl;
	}
	
	
}

int main(){
	ll t; cin>>t;
	while(t--){
		solve();
	}
}


