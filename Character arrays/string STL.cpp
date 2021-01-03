#include <bits/stdc++.h>
using namespace std;

int main() {

	string s1 = "Apple";
	string s2 = "Mango";

	cout << s1.compare(s2) << endl; // s1 - s2

	if (s2 > s1) cout << "Yes" << endl;

	string s = "I live in Kolkata";

	// Remove a word from a sentence
	string word = "live";
	int idx = s.find(word);
	cout << idx << endl;
	s.erase(idx, word.length() + 1);
	cout << s << endl;
}
