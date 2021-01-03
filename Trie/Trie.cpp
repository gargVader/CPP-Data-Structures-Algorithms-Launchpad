/*
Trie Data Structure
*/

#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
	char data;
	// map stores the children of data and link to their nodes
	unordered_map<char, Node*> children;
	bool terminal;

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
	// o(len)
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

	// O(len)
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
		return curr->terminal;

	}
};

int main() {

	Trie t;
	t.insert("no");
	t.insert("not");
	t.insert("new");
	t.insert("news");

	cout << t.find("no") << t.find("news") << t.find("note");
}
