#include <bits/stdc++.h>
using namespace std;

int a = 0, b = 1;

int genNum() {
	int sum = a + b;
	a = b;
	b = sum;
	return b;
}

int main() {

	int n; cin >> n;

	if (n >= 1) cout << 0 << endl;
	if (n >= 2) cout << "1 1" << endl;

	genNum();

	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cout << genNum() << " ";
		} cout << endl;
	}

}
