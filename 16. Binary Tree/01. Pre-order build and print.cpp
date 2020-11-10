/*
******************************Binary Tree*************************************
1. Pre-order Build
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Height of Tree
6. Print Kth Level
7. Print all Levels (Level Order Traversal) O(n^2)
*******************************************************************************
*/

#include <iostream>
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

// In-order Traversal
void printIn(node *root) {

	if (root == NULL) {
		return;
	}

	// Call on left part
	printIn(root->left);

	// print root
	cout << root->data << " ";

	// Call on right part
	printIn(root->right);

}

// Post-order Traversal
void printPost(node *root) {

	if (root == NULL) {
		return;
	}

	// Call on left part
	printPost(root->left);

	// Call on right part
	printPost(root->right);

	// print root
	cout << root->data << " ";
}

int h = 0;
void heightOfTree(node *root, int depth) {

	// Base Case
	if (root == NULL) {
		h = max(h, depth);
		return;
	}

	// call on left
	heightOfTree(root->left, depth + 1);
	// call on right
	heightOfTree(root->right, depth + 1);
}

int height(node *root) {
	// Base Case
	if (root == NULL) {
		return 0;
	}

	// call on left
	int h1 = height(root->left);
	// call on right
	int h2 = height(root->right);

	return max(h1, h2) + 1;
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

int main() {

	node *root = buildTree();
	// printPre(root); cout << endl;
	// printIn(root); cout << endl;
	// printPost(root); cout << endl;

	// heightOfTree(root, 0);
	// cout << h << endl;
	// cout << height(root) << endl;

	//printKthLevel(root, 3); cout << endl;
	printAllLevels(root);

}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 -1 13 -1 -1