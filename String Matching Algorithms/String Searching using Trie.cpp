/*
Given a text and a pattern, tell whether this pattern occurs
as a substring in the text.

1) Brute Force: Check for all substrings of same length

Generate a substring -> O(n)
Generate all substrigs -> O(n*n)
operator()== -> O(n)

Time Complexity -> O(n*(n+n)) = O(n*n)


2) Using trie

Insert all suffixes

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	// map stores the children of data and link to their nodes
	unordered_map<char, Node*> children;
	bool terminal;
	int index = 0;

	Node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {

public:
	Node *root;
	int count = 0; // Number of wonds inserted in count


	Trie() {
		root = new Node('\0');
		count = 0;
	}

	// Inserts word w
	void insert(string w) {

		// Initially we are at the root node
		Node *curr = root;

		// Iterate through the word
		for (int i = 0; i < w.size(); i++) {

			char ch = w[i];

			// If ch is not present
			if (curr->children.count(ch) == 0) {
				// Make new node for ch
				curr->children[ch] = new Node(ch);
			}
			// Jump to the next node
			curr = curr->children[ch];
		}
		// Mark the last character to be the terminal node
		curr->terminal = 1;

	}

	bool find(string w) {

		// Initially we are at the root node
		Node* curr = root;

		// Iterate though the word
		for (int i = 0;  i < w.size(); i++) {
			char ch = w[i]; // This is the character to find

			// Since charcater is not present then word is also not present
			if (curr->children.count(ch) == 0) return 0;
			else curr = curr->children[ch]; // Jump to the next node
		}

		// Return true only if last character is terminal node
		// return curr->terminal;
		return 1;

	}
};

int main() {

	string text = "abaacdbacad";
	string pat = "cadm";
	int len = pat.size();
	int n = text.size();

	// Brute Force
	// bool f = 0;
	// for (int i = 0; i <= (n - len); i++) {
	// 	string s = text.substr(i, len);
	// 	if (s == pat) {
	// 		cout << "Yes" << endl;
	// 		f = 1;
	// 		break;
	// 	}
	// }

	// if (!f)
	// 	cout << "No" << endl;

	Trie t;

	for (int i = 0; i < n; i++) {
		t.insert(text.substr(i));
	}

	cout << t.find(pat) << endl;


}
