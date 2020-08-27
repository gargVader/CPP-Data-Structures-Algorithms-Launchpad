#include<iostream>
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


node *buildTree() {
	int d; cin >> d;

	if (d == -1) {
		return NULL;
	}

	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

int height(node *root) {
	// Base Case
	if (root == NULL) {
		return 0;
	}

	int l1 = height(root->left);
	int l2 = height(root->right);

	return max(l1, l2) + 1;
}

// int diameterOfTree(node *root) {

// 	// Base Case
// 	if (root == NULL) {
// 		return 0;
// 	}

// 	int h1 = height(root->left);
// 	int h2 = height(root->right);
// 	int diameter = h1 + h2;

// 	return max(diameter, max(diameterOfTree(root->left), diameterOfTree(root->right)));

// }

class Pair {
public:
	int height = 0;
	int diameter = 0;
};

// 	O(n)
Pair diameterOfTree(node *root) {

	// Base Case
	if (root == NULL) {
		Pair p;
		return p;
	}

	Pair p1 = diameterOfTree(root->left);
	Pair p2 = diameterOfTree(root->right);

	Pair p;
	p.height = max(p1.height, p2.height) + 1;
	p.diameter = max(p1.height + p2.height, max(p1.diameter, p2.diameter));

	return p;
}

int main() {
	node *root = buildTree();
	cout << diameterOfTree(root).diameter << endl;
}