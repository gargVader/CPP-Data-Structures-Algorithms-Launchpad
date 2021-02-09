#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int num = (n / 2) + 1;

	int space1 = n - 1;
	for (int i = 1; i < (num + 1); i++) {
		for (int j = 1; j <= space1; j++) cout << "  ";
		for (int j = i; j >= 1; j--) cout << j << " ";

		int space2 = 2 * (i - 1) - 1;
		for (int j = 1; j <= space2; j++) cout << "  ";
		if (i != 1)
			for (int j = 1; j <= i; j++) cout << j << " ";


		space1 -= 2;
		cout << endl;
	}


	space1 = 2;

	for (int i = num - 1; i >= 1; i--) {
		for (int j = 1; j <= space1; j++) cout << "  ";
		for (int j = i; j >= 1; j--) cout << j << " ";

		int space2 = 2 * (i - 1) - 1;
		for (int j = 1; j <= space2; j++) cout << "  ";
		if (i != 1)
			for (int j = 1; j <= i; j++) cout << j << " ";


		space1 += 2;
		cout << endl;
	}

}
