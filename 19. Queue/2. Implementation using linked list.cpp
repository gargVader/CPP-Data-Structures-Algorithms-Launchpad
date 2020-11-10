#include <iostream>
#include<list>
using namespace std;

class Queue {
	int cs;
	list<int> l;

public:
	Queue() {
		cs = 0;
	}

	bool isEmpty() {
		return cs == 0;
	}

	void push(int data) {
		l.push_back(data);
		cs++;
	}

	void pop() {
		if (!isEmpty()) {
			cs--;
			l.pop_front();
		}
	}

	int front() {
		return l.front();
	}
};


int main() {
	Queue q;
	for (int i = 0; i < 10; ++i)
	{
		q.push(i);
	}

	while (!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	} cout << endl;
}