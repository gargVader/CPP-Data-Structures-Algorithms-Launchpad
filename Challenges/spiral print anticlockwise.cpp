#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	int n, m;
	cin >> n >> m;

	int a[20][20];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int sr = 0, er = n, sc = 0, ec = m;

	while (sr < er) {

		for (int i = sr; i < er; i++) {
			cout << a[i][sc] << ", ";
		} sc++;

		for (int j = sc; j < ec; j++) {
			cout << a[er - 1][j] << ", ";
		} er--;

		for (int i = er - 1; i >= sr; i--) {
			cout << a[i][ec - 1] << ", ";
		} ec--;

		for (int j = ec - 1; j >= sc; j--) {
			cout << a[sr][j] << ", ";
		} sr++;

	} cout << "END";

}
