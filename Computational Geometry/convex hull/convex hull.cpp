// Convex Hull

#include<bits/stdc++.h>
using namespace std;

typedef struct POINT {
	int x; int y;
} POINT;

// gives orientation of p->q->r
int orientation(POINT p, POINT q, POINT r) {
	int m = (p.y - r.y) * (p.x - q.x) - (p.y - q.y) * (p.x - r.x);
	if (m > 0) return 1; // clockwise
	if (m < 0) return -1; // anti-clockwise
	else return 0;      // collinear
}

void printPoint(POINT a) {
	cout << a.x << " " << a.y;
}

bool isSame(POINT a, POINT b) {
	return (a.x == b.x && a.y == b.y) ? 1 : 0;
}

void convexHull(POINT arr[], int n) {
	if (n < 3) return;

	vector<POINT> result;

	// find the leftmost point
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (arr[start].x > arr[i].x) {
			start = i;
		}
	}

	//printPoint(arr[start]); cout << " test" << endl;

	int curr = start;
	result.push_back(arr[start]);
//	printPoint(result[0]); cout<<" test2"<<endl;

	while (1) {
		int nextTarget = (curr + 1) % n; //(curr+1)%n;

		for (int i = 0; i < n; i++) {
			int o = orientation(arr[curr], arr[i], arr[nextTarget]);
			if (o == -1) {
				nextTarget = i;
			}
		}


		if (nextTarget == start) break;

		result.push_back(arr[nextTarget]);
		curr = nextTarget;
//		printPoint(arr[nextTarget]); cout<<endl;
	}


	for (int i = 0; i < result.size(); i++) {
		printPoint(result[i]);
		cout << endl;
	}

//	do{
//		hull.push_back(arr[prev]);
//		for(int i=0; i<n; i++){
//			r=i;
//			if(orientation(arr[prev], arr[r], arr[curr])==1 || orientation(arr[prev], arr[r], arr[curr])==0){
//				curr=r;
//			}
//		}
//		if(curr==leftMost) break;
//		prev = curr;
//	}while(curr!=leftMost);

//	while(1){
//		POINT nextTarget = arr[1];
//
//		for(int i=0; i<n; i++){
//			int o=orientation(curr, arr[i], nextTarget);
//			if(o==1 || o==0){
//				curr=nextTarget;
//			}
//		}
//
//		if(isSame(curr, start)) break;
//
//		result.push_back(curr);
//
//
//	}

}


int main() {
	POINT arr[100] = {{0, 3}, {2, 2}, {0, 1}, {0, 2}, {0, 0}, { -1, 0}};
	int n = sizeof(arr) / sizeof(arr[0]);
	convexHull(arr, n);


}


