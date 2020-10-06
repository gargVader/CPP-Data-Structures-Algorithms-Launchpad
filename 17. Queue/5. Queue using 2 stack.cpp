#include<iostream>
#include<stack>
using namespace std;

// Transfer from s1 to s2 but leave n elements in s1
void transfer(stack<int> &s1, stack<int> &s2, int n = 0) {
	while (s1.size() != n) {
		int x = s1.top();
		s1.pop();
		s2.push(x);
	}
}

class queue {
	stack<int> s1, s2;
public:
	void push(int d) {
		s1.push(d);
	}
	void pop() {
		// Transfer n-1 elements from s1 to s2
		transfer(s1, s2, 1);
		// Remove 1st element of queue
		s1.pop();
		// Restore s1 stack
		transfer(s2, s1);
	}
	int front() {
		// Transfer n elements from s1 to s2
		transfer(s1, s2);
		int f = s2.top();

		// Restore s1 stack
		transfer(s2, s1);

		return f;
	}
	bool empty() {
		return s1.empty();
	}
};


int main() {
	queue q;
	for (int i = 0; i < 10; i++) {
		q.push(i * 9);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	} cout << endl;
}