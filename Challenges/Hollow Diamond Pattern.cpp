#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	if (n == 1) {
		cout << "*";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		cout << "* ";
	} cout << endl;


	int num = n / 2 + 1;
	for (int i = 1; i < num; i++) {
		int stars = num - i;
		for (int j = 0; j < stars; j++) {
			cout << "* ";
		}

		int space = 2 * i - 1;
		for (int j = 0; j < space; j++) {
			cout << "  ";
		}

		for (int j = 0; j < stars; j++) {
			cout << "* ";
		}
		cout << endl;

	}

	for (int i = 2; i < num; i++) {

		for (int j = 0; j < i; j++) {
			cout << "* ";
		}

		int space = n - 2 * i;

		for (int j = 0; j < space; j++) {
			cout << "  ";
		}

		for (int j = 0; j < i; j++) {
			cout << "* ";
		}
		cout << endl;

	}




	for (int i = 0; i < n; i++) {
		cout << "* ";
	} cout << endl;



}
