#include <bits/stdc++.h>
#define pb push_back
using namespace std;


typedef struct point {
	int x, y;
} point;

// Gives orientation of a->b->c
int orientation(point a, point b, point c) {
	int s = (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);

	if (s == 0) return 0; // collinear
	if (s > 0) return 1; // clockwise
	else return -1; // anticlockwise
}

void printHull(vector<point> hull) {

	for (int i = 0; i < hull.size(); i++) {
		point p = hull[i];
		cout << "(" << p.x << "," << p.y << ")" << endl;
	}


}

void convexHull(point arr[], int n) {

	vector<point> hull;

	// There must be atleast 3 points
	if (n == 3) {
		for (int i = 0; i < n; i++) {
			hull.pb(arr[i]);
		}
		printHull(hull);
		return;
	}

	// Find the leftmost point
	int start = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i].x < arr[start].x) {
			start = i;
		}
	}
	hull.pb(arr[start]);
	int curr = start;
	//printPoint(arr[start]); cout << " test" << endl;


	while (1) {

		// I chose nextTarget as start+1 but there may be a point which is even better than this
		// So we will have to iterate through all the points
		int nextTarget = (curr + 1) % n;

		// We shall iterate through all the points
		// and search for a point which is anti-clockwise wrt start & nextTarget

		for (int i = 0; i < n; i++) {
			int o = orientation(arr[curr], arr[i], arr[nextTarget]);

			if (o == -1) {
				nextTarget = i;
			}
		}

		if (nextTarget == start) break;

		hull.pb(arr[nextTarget]);
		curr = nextTarget;
	}

	printHull(hull);
}

int main() {
	point arr[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
	int n = sizeof(arr) / sizeof(arr[0]);
	convexHull(arr, n);

}