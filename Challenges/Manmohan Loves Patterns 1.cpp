#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	bool allOne = 1;

	for (int i = 1; i <= n; i++) {

		if (allOne) {
			for (int j = 0; j < i; j++) {
				cout << 1;
			}
		} else {

			cout << 1;

			for (int j = 1; j < i - 1; j++) {
				cout << 0;
			}

			cout << 1;

		}

		allOne = !allOne;
		cout << endl;

	}

}
