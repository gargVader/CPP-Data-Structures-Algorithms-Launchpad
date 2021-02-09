#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {

		cout << i << " ";

		for (int j = 1; j <= (i - 2); j++) {
			cout << 0 << " ";
		}

		if (i > 1) cout << i;
		cout << endl;

	}

}

