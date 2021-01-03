#include<iostream>
using namespace std;

int lcs(string x, string y, int sx, int sy, int ex, int ey) {

	for (int i = sx; i < ex; i++) {
		for (int j = sy; j < ey; j++) {
			if (x[i] == y[j]) {
				return 1 + lcs(x, y, i + 1, j + 1, ex, ey);
			}
		}
	}

	return 0;

}

int main() {
	string x = "nematode", y = "empty";
	cout << lcs(x, y, 0, 0 , x.size(), y.size());
}