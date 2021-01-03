// Unique Number - 2
#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int main() {
	int n; cin >> n;
	int arr[MAX], xor_ = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		xor_ = xor_ ^ arr[i];
	}

	int copy = xor_;

	int pos = 0;
	while (copy & 1 != 1) {
		pos++;
		copy = copy >> 1;
	}

	// first set-bit at xor is at pos
	int mask = 1 << pos;

	int a = 0;

	for (int j = 0; j < n; j++) {
		if (arr[j]&mask) {
			a = a ^ arr[j];
		}
	}

	int b = xor_ ^ a;

	cout << min(a, b) << " " << max(a, b);

}


