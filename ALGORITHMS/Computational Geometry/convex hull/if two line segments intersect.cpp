// Given two line segments (p1, q1) and (p2, q2), find if the given line segments intersect with each other

#include<bits/stdc++.h>
using namespace std;

typedef struct POINT{
	int x;
	int y;
}POINT;


// orientation of a->w->b
int orientation(POINT a, POINT b, POINT w){
	int m = (b.y-a.y)*(b.x-w.x) - (b.y-w.y)*(b.x-a.x);
	if(m>0) return 1; // clockwise
	if(m<0) return -1; // anti-clockwise
	else return 0; // collinear
}

bool onSegment(POINT a, POINT b, POINT w){
	// We already know that a,b,w are collinear
	// if w.x lies between a.x and b.x && w.y lies between a.y and b.y then true
	if(w.x>=a.x && w.x<=b.x && w.y>=a.y && w.y<=b.y)
		return 1; 
	return 0;
}

bool isIntersecting(POINT p1, POINT p2, POINT p3, POINT p4){
	int o1 = orientation(p1, p2, p3);
	int o2 = orientation(p1, p2, p4);
	int o3 = orientation(p3, p4, p1);
	int o4 = orientation(p3, p4, p2);
	
	// General Case
	if(o1!=o2 && o3!=o4){
		return 1;
	}
	
	// Special case when all are collinear
	if(o1==0 && o2==0 && o3==0 && o4==0){
		// just check if either of p3 or p4 lies within p1 and p2
		if(onSegment(p1, p2, p3)) return 1;
		if(onSegment(p1, p2, p4)) return 1;
	}
	
	return 0;
	
}

int main(){
	POINT p1, p2, p3, p4;
	
	p1={1,1}, p2={10,1}, p3={1,2}, p4={10,2};
//	p1={10,0}, p2={0,10}, p3={0,0}, p4={10,10};
//	p1={-5,-5}, p2={0,0}, p3={1,1}, p4={10,10};
	
	if(isIntersecting(p1, p2, p3, p4)) cout<<"YES instersecting";
	else cout<<"NOT intersecting";
	
	
	
	
	
}


