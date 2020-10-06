#include <iostream>
#include<queue>
using namespace std;

//
void transfer(queue<int> &q1, queue<int> &q2, int n = 0) {

	while (q1.size() != n) {
		int x = q1.front();
		q1.pop();
		q2.push(x);
	}

}


class stack {
	queue<int> q1, q2;
public:
	void push(int d) {
		q1.push(d);
	}
	void pop() {
		// Transfer n-1 elements from q1 to q2
		transfer(q1, q2, 1);
		q1.pop();

		// Restore q1
		swap(q1, q2);
	}
	int top() {
		// Transfer n-1 elements from q1 to q2
		transfer(q1, q2, 1);
		int t = q1.front();
		q1.pop(); q2.push(t);

		// Restore q1
		swap(q1, q2);
		return t;
	}
};

int main() {
	stack s;
	int n = 10;
	for (int i = 0; i < n; i++) {
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << s.top() << " ";
		s.pop();
	} cout << endl;
}
