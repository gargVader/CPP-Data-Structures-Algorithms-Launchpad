//  Length of longest substring with non-repeating characters

#include <iostream>
using namespace std;

int main() {

	string s = " ";

	int i = 0, j = 0, ans = 0;

	int freq[200] = {0};

	for (; j < s.size(); ) {
		//cout << i << " " << j << endl;
		// s[j] is new character
		if (freq[s[j] - ' '] == 0) {
			freq[s[j] - ' ']++;
			j++;
			ans = max(ans, j - i);
		} else {
			// shrink i
			while (freq[s[j] - ' '] != 0) {
				freq[s[i] - ' ']--;
				i++;
			}
			freq[s[j] - ' ']++;
			j++;
		}
	} //cout << endl;

	cout << ans << endl;

}
