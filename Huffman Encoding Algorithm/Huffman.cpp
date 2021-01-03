/*
Huffman Encoding
================
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	int freq;
	Node* left = NULL;
	Node* right = NULL;

	Node(char data, int freq) {
		this->data = data;
		this->freq = freq;
	}
};

class NodeCompare {
public:
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};

void printCode(Node* root, string s = "") {

	// Base Case
	if (!root) {
		return;
	}

	if (root->data != '$') {
		cout << root->data << " : " << s << endl;
	}

	printCode(root->left, s + '1');
	printCode(root->right, s + '0');

}

void huffmanCode(string s) {

	unordered_map<char, int> freq;
	//for (auto x : s) freq[x]++;

	freq['a'] = 60;
	freq['b'] = 30;
	freq['c'] = 8;
	freq['d'] = 2;


	priority_queue<Node*, vector<Node*>, NodeCompare> minHeap;

	for (auto p : freq) {
		cout << p.first << " " << p.second << endl;
		minHeap.push(new Node(p.first, p.second));
	}

	// Iterate while size of heap doesnot become 1
	while (minHeap.size() != 1) {
		// Extract two items
		Node* left = minHeap.top();
		minHeap.pop();
		Node* right = minHeap.top();
		minHeap.pop();

		cout << left->data << " " << right->data << endl;

		// Combine nodes
		int newFreq = left->freq + right->freq;
		Node * newNode = new Node('$', newFreq);
		newNode->left = left;
		newNode->right = right;

		minHeap.push(newNode);
	}

	printCode(minHeap.top());

}

int main() {

	string s = "abccda";
	huffmanCode(s);

}
