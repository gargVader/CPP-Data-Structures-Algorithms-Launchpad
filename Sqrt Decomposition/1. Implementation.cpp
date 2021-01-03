#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

int main() {

	vector<int> a{1, 2, 3, 4, 8, 7, 3, 7, 2, 9, 11};
	int n = a.size();

	// Pre-processing
	int len = ceil(sqrt(n + .0));
	cout << len << endl;
	vector<int> b(len);
	for (int i = 0; i < n; i++) {
		b[i / len] += a[i];
	}

	for (int i = 0; i < len; i++) {
		cout << b[i] << " ";
	} cout << endl;

	int l = 1, r = 9;
	int sum = 0;
	for (int i = l; i <= r; ) {
		cout << "i=" << i << endl;
		if (i % len == 0 && i + len - 1 <= r) {
			sum += b[i / len];
			i += len;
		} else {
			sum += a[i++];
		}
	}

	cout << sum << endl;

}
