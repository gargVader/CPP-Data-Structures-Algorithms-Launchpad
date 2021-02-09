#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

signed main() {

	char c; cin >> c;

	int a = (int) c;

	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
		if (c == toupper(c)) {
			cout << "U";
		} else if (c == tolower(c)) {
			cout << "L";
		}
	} else {
		cout << "I";
	}
}
