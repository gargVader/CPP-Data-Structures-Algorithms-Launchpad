#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}

		for (int j = 1; j <= (2 * (n - i)); j++) {
			cout << "  ";
		}

		if (i == n) {
			for (int j = i - 1; j >= 1; j--) {
				cout << j << " ";
			} cout << endl;
		} else {
			for (int j = i; j >= 1; j--) {
				cout << j << " ";
			} cout << endl;
		}



	}

}
