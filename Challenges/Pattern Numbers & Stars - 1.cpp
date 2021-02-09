#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		for (int j = 1; j <= (n - i); j++) {
			cout << j << " ";
		}

		int stars = 2 * i - 1;
		for (int j = 0; j < stars; j++) cout << "* ";

		cout << endl;

	}

}
