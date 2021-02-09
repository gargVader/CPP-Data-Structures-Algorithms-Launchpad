#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = i - 1;
		if (num == 0) num = 1;


		cout << num;

		for (int j = 1; j < i - 1; j++) {
			cout << 0;
		}
		if (i > 1) cout << num;
		cout << endl;
	}

}

