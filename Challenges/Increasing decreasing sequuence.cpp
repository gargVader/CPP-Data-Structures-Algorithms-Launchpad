#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "false";
		return 0;
	}

	int i = 0;
	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {

		} else {
			break;
		}
	}

	for (; i < n; i++) {
		if (a[i] > a[i - 1]) {

		} else {
			cout << "false";
			return 0;
		}
	}

	cout << "true";

}