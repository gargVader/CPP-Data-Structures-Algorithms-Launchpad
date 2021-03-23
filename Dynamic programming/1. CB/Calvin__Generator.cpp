#include<bits/stdc++.h>
#define int long long
using namespace std;

int randomNumber(int a, int b) {
	return a + (rand() % b);
}

signed main() {

	srand(time(0));
	int n = randomNumber(1, 20);
	cout << n << " ";

	int k = randomNumber(1, n);
	cout << k << endl;

	for (int i = 0; i < n; i++) {
		cout << randomNumber(-100, 100) << " ";
	}
	cout << endl;


}