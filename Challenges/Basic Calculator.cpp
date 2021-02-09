#include <bits/stdc++.h>
using namespace std;

int main() {

	char c;

	while (1) {
		cin >> c;
		if (c == '+' || c == '-' || c == '/' || c == '*') {
			int a, b; cin >> a >> b;

			if (c == '+') cout << a + b << endl;
			if (c == '-') cout << a - b << endl;
			if (c == '/') cout << a / b << endl;
			if (c == '*') cout << a*b << endl;

		} else if (c == 'X' || c == 'x') {
			return 0;
		} else {
			cout << "Invalid operation. Try again." << endl;
		}
	}

}
