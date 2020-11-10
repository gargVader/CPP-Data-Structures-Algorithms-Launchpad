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

bool matches(unordered_map<int, int> curr_freq, unordered_map<int, int> pattern_freq) {
	for (auto x : pattern_freq) {
		int idx = x.first;
		int minfreq = x.second;
		if (curr_freq[idx] < minfreq) {
			return 0;
		}
	}
	return 1;
}

int main() {

	string s = "helllaoeeo world";
	string p = "eelo";
	int n = s.size();

	int ans = INT_MAX;

	unordered_map<int, int> pattern_freq;
	for (int i = 0; i < p.size();  i++) {
		pattern_freq[p[i] - 'a']++;
	}

	// for (auto x : pattern_freq) {
	// 	cout << x.first << " " << x.second << endl;
	// } cout << endl;

	unordered_map<int, int> curr_freq;
	bool state = 0;

	int start = 0, end = -1;

	while (end < n) {


		// cout << "Curr Freq" << endl;
		// for (auto x : curr_freq) {
		// 	cout << x.first << " " << x.second << endl;
		// }

		// check
		if (matches(curr_freq, pattern_freq)) {
			// cout << "Matches";
			int len = end - start + 1;
			//cout << len << endl;
			ans = min(ans, len);
			// Compression
			curr_freq[s[start] - 'a']--;
			start++;
		} else {
			// Expanding
			end++;
			curr_freq[s[end] - 'a']++;
		}


	}

	if (ans == INT_MAX) {
		cout << "None" << endl;
		return 0;
	}

	cout << ans << endl;

}
