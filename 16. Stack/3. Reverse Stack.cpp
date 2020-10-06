// Reverse stack using another stack

#include<iostream>
#include<stack>
using namespace std;

void reverseStackRecursive(stack<int> &s) {

	// Base Case
	if (s.size() == 1) {
		return;
	}

	int temp = s.top(); s.pop();
	//cout << temp << endl;
	stack<int> s2;
	// Empty s into s2
	while (!s.empty()) {
		int x = s.top(); s.pop();
		s2.push(x);
	}

	// Push temp in s
	s.push(temp);
	//cout << temp << endl;

	// Reverse s2
	reverseStackRecursive(s2);

	// Empty s2 into s
	while (!s2.empty()) {
		int x = s2.top(); s2.pop();
		//cout << x << endl;
		s.push(x);
	}

	//return s;
}

// Transfers n elements from s2 to s1
void transfer(stack<int> &s1, stack<int> &s2, int n) {

	for (int i = 0; i < n; i++) {
		int x = s1.top(); s1.pop();
		s2.push(x);
	}
}


void reverseStack(stack<int> &s) {
	// In final stack, the topmost element should be at the bottom
	int n = s.size();
	stack<int> s2;

	for (int i = 1; i <= n; i++) {
		// Store top element in temp
		int temp = s.top(); s.pop();

		// Transfer n-i elements from s to s2
		transfer(s, s2, n - i);

		// push temp back into s
		s.push(temp);

		// Transfer n-i elements back into s
		transfer(s2, s, n - i);
	}
}


int main() {
	stack<int> s1;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	} cout << endl;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

	//reverseStackRecursive(s1);
	reverseStack(s1);

	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}

}