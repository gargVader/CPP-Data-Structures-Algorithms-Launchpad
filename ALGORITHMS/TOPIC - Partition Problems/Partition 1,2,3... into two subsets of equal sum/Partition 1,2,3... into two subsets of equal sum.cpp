#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	bool a[n + 1] = {0};
	int tsum = (n * (n + 1)) / 2;
	if (tsum % 2 == 1) {
		cout << "Difference will be 1" << endl;
		return 0;
	}
	tsum /= 2;
	for (int i = n; i > 0; i--) {
		if (tsum >= i) {
			tsum -= i;
			a[i] = 1;
		}
		if (tsum == 0) {
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	} cout << endl;
}