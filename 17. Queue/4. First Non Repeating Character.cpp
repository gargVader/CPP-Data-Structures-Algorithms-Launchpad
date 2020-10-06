#include<iostream>
#include <queue>
using namespace std;

int main() {
	char s;
	int freq[26] = {0};
	queue<char> q;
	/*
		while (cin >> s) {

			// Will handle any new element
			if (freq[s - 'a'] == 0) {
				q.push(s);
			}
			freq[s - 'a']++;

			if (!q.empty() && freq[q.front() - 'a'] == 1) {
				cout << q.front() << " ";
			} else {
				// Case 1: freq[q.front()-'a']>1
				while (!q.empty() && freq[q.front() - 'a'] > 1) {
					q.pop();
				}

				// Case 2: q is empty
				if (q.empty()) {
					cout << "-1" << " ";
				} else {
					cout << q.front() << " ";
				}
			}
		}
		*/

	while (cin >> s) {

		q.push(s);
		freq[s - 'a']++;

		while (!q.empty() && freq[q.front() - 'a'] > 1) {
			q.pop();
		}
		if (q.empty()) {
			cout << "-1" << " ";
		} else {
			cout << q.front() << " ";
		}
	}

}

/*
a a b c c b c d
a -1 b b b -1 -1 d
*/