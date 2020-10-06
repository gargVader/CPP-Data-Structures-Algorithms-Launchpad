#include<iostream>
using namespace std;

void countBST(int dp[], int n) {

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += dp[i - j] * dp[j - 1];
		}
		dp[i] = sum;
	}

	cout << dp[n] << endl;
}


int main() {
	int n; cin >> n;
	int dp[n + 1] = {0};
	countBST(dp, n);
}