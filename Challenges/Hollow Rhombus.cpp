#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int space = n - i;

		for (int j = 0; j < space; j++) cout << " ";

		if (i == 1 || i == n) {
			for (int j = 0; j < n; j++) cout << "*";
		} else {
			cout << "*";
			for (int j = 0; j < n - 2; j++) cout << " ";
			cout << "*";
		} cout << endl;
	}

}
