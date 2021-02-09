#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 0; i <= n; i++) {
		int num = n - i;

		for (int j = n; j >= num; j--) {
			cout << j << " ";
		}

		int space = 2 * (num - 1) + 1;

		for (int j = 0; j < space; j++) {
			cout << "  ";
		}

		if (i == n) num++;
		for (int j = num; j <= n; j++) {
			cout << j << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			cout << j << " ";
		}

		int space = 2 * i - 1;

		for (int j = 0; j < space; j++) {
			cout << "  ";
		}

		for (int j = i; j <= n; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
}
