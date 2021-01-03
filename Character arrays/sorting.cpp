/* Given a list of strings, sort them
For string class cin.getline() doesnot work
*/

#include <bits/stdc++.h>
using namespace std;


bool compare(string a, string b) {
	return a.length() > b.length();
}

int main() {

	int n; cin >> n; // number of strings
	cin.get();

	// array of strings
	string s[100];

	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}

	sort(s, s + n, compare);

	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}

}
