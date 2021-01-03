#include <iostream>
#include<map>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node *left = NULL;
	node *right = NULL;

	node(int d) {
		data = d;
	}
};

node* buildTree() {
	int d; cin >> d;

	//  Base Case
	if (d == -1) {
		return NULL;
	}

	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

// Pre-order traversal
void printPre(node *root) {

	if (root == NULL) {
		return;
	}

	// print root
	cout << root->data << " ";

	// Call on left part
	printPre(root->left);
	// Call on right part
	printPre(root->right);

}

int height(node *root) {
	if (root == NULL) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

void printKthLevel(node *root, int k) {

	//cout << "k=" << k << endl;

	if (root == NULL) {
		return;
	}

	// Base Case
	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
}

// Level Order Traversal - Recursive O(n^2)
void printAllLevels(node *root) {
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printKthLevel(root, i);
		cout << endl;
	}
}

map<int, vector<int>> mp;
void markNodes(node* root, int pos = 0) {

	if (root == NULL) {
		return;
	}

	mp[pos].push_back(root->data);
	markNodes(root->left, pos - 1);
	markNodes(root->right, pos + 1);
}

void verticalPrint(node* root) {
	markNodes(root, 0);

	for (auto it : mp) {
		cout << "Pos: " << it.first << " Nodes: ";
		for (auto x : it.second) {
			cout << x << " ";
		} cout << endl;
	}

}

int main() {

	node *root = buildTree();
	printAllLevels(root);

	verticalPrint(root);

}

/*
Sample Input:
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 -1 13 -1 -1

Sample Output:


*/