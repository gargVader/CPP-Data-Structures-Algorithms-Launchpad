#include<iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n = 10;

	for (int i = 0; i < n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

}