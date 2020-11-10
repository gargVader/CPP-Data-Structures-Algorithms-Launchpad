/*
Given N ropes of different sizes, we have to join the ropes together.
The cost of joining two ropes A and B together is (A+B). Find the minimum cost to join all
the ropes together
*/


#include <iostream>
#include <queue>
using namespace std;

int joinRopes(int ropes[], int n) {

	priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);

	int cost = 0, len = pq.top();
	pq.pop();

	while (!pq.empty()) {
		int num = pq.top();
		cost += len + num;
		len += num;
		pq.pop();
	}

	return cost;

}

int main() {

	int ropes[] = {4, 3, 2, 6};
	int n = sizeof(ropes) / sizeof(int);

	cout << joinRopes(ropes, n) << endl;

}
