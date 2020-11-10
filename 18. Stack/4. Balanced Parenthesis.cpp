#include<iostream>
#include <stack>
using namespace std;

int main() {
	string str = "((a+b)+(c-d+f))";
	int n = str.size();
	stack<int> s;

	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			s.push(1);
		} else if (str[i] == ')') {
			if (!s.empty()) {
				s.pop();
			} else {
				cout << "Not balanced" << endl;
				return 0;
			}
		}
	}

	if (s.size()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

}