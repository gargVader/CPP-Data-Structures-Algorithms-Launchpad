#include <bits/stdc++.h>
using namespace std;

void print(int a, int b) {
	if (a < b) cout << a << " and " << b << endl;
	else cout << b << " and " << a << endl;
}

int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int target; cin >> target;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == target) print(a[i], a[j]);
		}
	}

}
