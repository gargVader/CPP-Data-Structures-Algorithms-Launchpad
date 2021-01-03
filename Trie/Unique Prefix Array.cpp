#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data; // data of node
	unordered_map<char, Node*> children; // map to store children data and link to their nodes
	bool terminal = 0;
	int count = 0; // This node is part of how many words

	Node(char d) {
		data = d;
	}
};

class Trie {

	Node* root;

public:

	// Constructor
	Trie() {
		root = new Node('\0');
	}

	void insert(string w) {

		// Initially I am at the root node
		Node* curr = root;

		// Loop through the word
		for (int i = 0; i < w.size(); i++) {

			char ch = w[i];

			// If ch is not present
			if (curr->children.count(ch) == 0) {
				// Make a new node for ch
				curr->children[ch] = new Node(ch);
			}
			// ch is now having a new word
			curr->children[ch]->count++;
			// Jump to the next node
			curr = curr->children[ch];

		}

		// Mark last node as terminal node
		curr->terminal = 1;
	}

	void printPrefix(Node* curr, string s = "") {
		// Base Case
		if (curr->count == 1) {
			cout << s << endl;
			return;
		}

		// Iterate through all the children of curr
		for (auto child : curr->children) {
			// Child is a pair
			char ch = child.first;
			Node* next = child.second;
			printPrefix(next, s + ch);
		}
	}

	Node* rootNode() {
		return root;
	}


};

int main() {

	string words[] = {"cobra", "coolie", "dog", "dove", "duck"};
	int n = sizeof(words) / sizeof(words[0]);

	Trie t;

	for (auto s : words) t.insert(s);

	t.printPrefix(t.rootNode());

}
