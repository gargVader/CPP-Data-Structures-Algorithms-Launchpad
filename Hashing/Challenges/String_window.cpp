/* Find the minimum length substring of string1 which contains all
the characters of string2

1) Brute Force -> O(n^3)
 - Generate all substrings of s1
 - Check if substring satisfies the condition
 - Choose the smallest among them

2) Efficient -> O(n)

 - Keep two pointers start and end
 - If current substring satisfies the condtion then move start pointer forward
   else move end pointer forward

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	// string s1, s2;
	// getline(cin, s1);
	// getline(cin, s2);

	string s1 = "abcdef";
	string s2 = "qas";

	int len1 = s1.size();
	int len2 = s2.size();


	if (len1 < len2) {
		cout << "No string" << endl;
		return 0;
	}

	if (len1 == 0 && len2 == 0) {
		cout << endl;
		return 0;
	}


	unordered_map<char, int> mp1; // for s1
	unordered_map<char, int> mp2; // for s2

	// Store freq of charaters in s2
	for (auto x : s2) mp2[x]++;

	int left = 0, right = 0, count = 0;
	int leftAns = 0, rightAns = 0, sizeAns = INT_MAX;

	// Iterate through s1
	for (right = 0; right < len1; right++) {
		//cout << left << " " << right << endl;
		char ch = s1[right];

		// Update freq
		mp1[ch]++;

		// Check if this character helps us?
		if (mp2[ch] && mp1[ch] <= mp2[ch]) {
			count++;
		}

		if (count == len2) {

			while (count == len2) {

				if (sizeAns > (right - left + 1)) {
					leftAns = left;
					rightAns = right;
					sizeAns = right - left + 1;
				}

				char leftChar = s1[left];
				left++;

				mp1[leftChar]--;

				if (mp2[leftChar] && mp1[leftChar] < mp2[leftChar]) {
					count--;
				}
			}

		}


	}

	string ans = s1.substr(leftAns, sizeAns);

	// final check
	unordered_map<char, int> mp3;

	for (auto x : ans) mp3[x]++;

	for (auto p : mp2) {
		if (p.second > mp3[p.first]) {
			cout << "No String" << endl;
			return 0;
		}
	}

	cout << ans << endl;
}