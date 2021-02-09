#include <bits/stdc++.h>
using namespace std;

int main() {
	double n = 786;
	double p = 0.71;

	while (p <= 1) {
		double ans = ceil(n * p);
		cout << ans << endl;
		p += 0.01;
	}

}
