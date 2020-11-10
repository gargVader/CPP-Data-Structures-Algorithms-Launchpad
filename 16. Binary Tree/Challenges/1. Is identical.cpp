#include<iostream>
using namespace std;

class node {
public:
	int data = 0;
	node* left = NULL;
	node* right = NULL;

	node(int d) {
		data = d;
	}
};

node* buildTree() {
	int d; cin >> d;

	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();


	return root;
}


bool isIdentical(node* root1, node* root2) {

	// Base Case
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}

	if (root1 != NULL && root2 != NULL) {
		bool leftans =  isIdentical(root1->left, root2->left);
		bool rightans =  isIdentical(root1->right, root2->right);
		return leftans and rightans;
	}
	return 0;
}

int main() {
	node* root1 = buildTree();
	node* root2 = buildTree();

	cout << isIdentical(root1, root2);
}