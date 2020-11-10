#include<iostream>
using namespace std;

class Queue {
	int *arr;
	int f, r, cs, ms;

public:
	Queue(int ds = 5) {
		arr = new int[ds];
		cs = 0;
		ms = ds;
		f = 0;
		r = ms - 1;
	}

	bool full() {
		return cs == ms;
	}

	bool empty() {
		return cs == 0;
	}

	void push(int data) {
		if (!full()) {
			r = (r + 1) % ms;
			arr[r] = data;
			cs++;
		} else {
			cout << "QUEUE OVERFLOW!" << endl;
		}
	}

	void pop() {
		if (!empty()) {
			f = (f + 1) % ms;
			cs--;
		} else {
			cout << "QUEUE UNDERFLOW" << endl;
		}
	}

	int front() {
		return arr[f];
	}

	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
	}
};

int main() {
	int n = 10;
	Queue q(n);

	for (int i = 0; i < n; i++) {
		q.push(i * 9);
	}

	for (int i = 0; i < n; i++) {
		int x = q.front();
		cout << x << " ";
		q.pop();
	} cout << endl;

	q.pop();
}