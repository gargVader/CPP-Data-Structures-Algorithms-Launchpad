#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	char d;
	map<char, Node*> children;
	bool terminal = 0;

	Node(char d) {
		this->d = d;
	}
};

class Trie {

public:
	Node* root;

	Trie() {
		root = new Node('\0');
	}


	void insert(string s) {

		int n = s.size();
		Node* curr = root;

		// Iterate through each character
		for (int i = 0; i < n; i++) {
			char ch = s[i];
			// If charcter is not present, create node
			if (curr->children.count(ch) == 0) curr->children[ch] = new Node(ch);
			// Move curr to next node
			curr = curr->children[ch];
		}

		// Mark the last node as terminal node
		curr->terminal = 1;
	}

	bool isPresent(string s) {
		int n = s.size();
		Node* curr = root;
		// Interate though each character
		for (int i = 0; i < n; i++) {
			char ch = s[i];

			if (curr->children.count(ch) == 0) return 0;
			else curr = curr->children[ch];

		}

		// return true only if last node is terminal node
		return curr->terminal;
	}

	void print(Node* start, vector<string> &v, string s = "") {

		// Base Case
		// If start node is terminal node
		if (start->terminal) {
			v.push_back(s);
			//cout << s  << endl;
		}

		for (auto p : start->children) {

			print(p.second, v, s + p.first);

		}

	}

	bool search(string s) {
		int n = s.size();
		Node* curr = root;
		// Iterate through each character
		for (int i = 0; i < n; i++) {
			char ch = s[i];

			if (curr->children.count(ch) == 0) break;
			else curr = curr->children[ch];
		}
		vector<string> v;
		print(curr, v, s);

		for (auto x : v) {
			cout << x << endl;
		}

		return v.size();
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	Trie t;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		t.insert(s);
	}

	int q; cin >> q;

	for (int i = 0; i < q; i++) {
		string s; cin >> s;

		bool found = t.search(s);
		if (!found) {
			cout << "No suggestions" << endl;
			t.insert(s);
		}
	}

}

