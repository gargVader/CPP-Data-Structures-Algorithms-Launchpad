/*
Problem
---------
Find the smallest window in a string
containing all charcaters of another string

string -> "hellloeeo world"
pattern -> "eelo"

*/


#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;


string find_window(string s, string p) {
	int slen = s.size();
	int plen = p.size();

	// Corner Case
	if (plen > slen) {
		return "None";
	}

	// Freq Maps
	int fs[256] = {0};
	int fp[256] = {0};

	for (int i = 0; i < plen; i++) {
		fp[p[i] - 'a']++;
	}

	int count = 0; // Count of matching characters
	// if count==plen, then we can update ans

	int start = 0;
	int min_len = INT_MAX;
	int start_idx = -1;

	// Sliding window (Expansion & Contraction +
	// Update the Min length Window)
	for (int i = 0; i < slen; i++) {
		int idx = s[i] - 'a';
		fs[idx]++;

		if (fp[idx] && fs[idx] <= fp[idx]) {
			count++;
		}

		// If all characters match
		if (count == plen) {
			// start shrinking the window

			int temp = s[start] - 'a';
			// loop to remove all unwanted characters
			// while temp is not present or it is present but its
			// freq is greater than the required frequency
			while (fp[temp] == 0 || fs[temp] > fp[temp]) {
				fs[temp]--;
				start++;
				temp = s[start] - 'a';
			}

			// Window size
			int window_len = i - start + 1;
			if (window_len < min_len) {
				min_len = window_len;
				start_idx = start;
			}

		}

	}

	if (start_idx == -1) {
		return "None";
	}

	return s.substr(start_idx, min_len);

}

int main() {

	string s = "hllloeaeo world";
	string p = "eelo";

	cout << find_window(s, p);

}
