#include <bits/stdc++.h>
using namespace std;

int main() {

	string s; cin >> s;
	int d; cin >> d;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		count += ((s[i] - '0') == d) ;
	}

	cout << count << endl;

}

