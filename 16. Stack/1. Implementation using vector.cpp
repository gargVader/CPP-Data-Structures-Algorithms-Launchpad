// Stack Implementation using vector
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack {
private:
	vector<T> v;
public:
	void push(T data) {
		v.push_back(data);
	}
	bool empty() {
		return v.empty();
	}
	void pop() {
		if (!v.empty()) {
			v.pop_back();
		}
	}
	T top() {
		return v.back();
	}
};


int main() {
	Stack<int> s;

	for (int i = 0; i < 5; i++) {
		s.push(i * 9);
	}

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	} cout << endl;

	Stack<char> s2;

	for (int i = 0; i < 5; i++) {
		s2.push('a' + i);
	}

	while (!s2.empty()) {
		cout << s2.top() << endl;
		s2.pop();
	}

}