#include<iostream>
#define MAX 1000
using namespace std;


// int maxPriceBottomUp(int price[], int i, int j) {

// 	int n = sizeof(price) / sizeof(price[0]);
// 	int dp[n + 1] = {0};

// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= n; j++) {
// 			dp[i][j] =
// 		}
// 	}

// }


int maxPrice(int price[], int i, int j, int cost, int year, int dp[][MAX]) {

	cout << year << endl;

	// Base Case
	if (i == j) {
		//Include that element
		cost += price[i] * year;
		return dp[i][j] = cost;
	}

	// Lookup
	if (dp[i][j] != 0) {
		return dp[i][j];
	}

	// Take left
	int op1 = maxPrice(price, i + 1, j, cost + price[i] * year, year + 1, dp);

	// Take right
	int op2 = maxPrice(price, i, j - 1, cost + price[j] * year, year + 1, dp);

	return dp[i][j] = max(op1, op2);

}

int main() {

	int price[] = {2, 3, 5, 1, 4};
	int n = sizeof(price) / sizeof(price[0]);
	int dp[MAX][MAX] = {0};
	cout << maxPrice(price, 0, n - 1, 0, 1, dp);



}