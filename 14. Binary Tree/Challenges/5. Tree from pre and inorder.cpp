#include<iostream>
#include<stack>
using namespace std;

class node {
public:
	int data;
	node *right = NULL;
	node*left = NULL;

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

int j = 0;
node* buildTree(int pre[], int in[], int s, int e) {

	// Base Case
	if (s >= e) {
		return NULL;
	}

	node* root = new node(pre[j]);

	// search for pre[j] in in[]
	int k = 0;
	for (k = s; k < e; k++) {
		if (in[k] == pre[j]) break;
	}
	j++;

	root->left = buildTree(pre, in, s, k);
	root->right = buildTree(pre, in, k + 1, e);
	return root;
}



void printPre(node* root) {
	// Base Case
	if (root == NULL) {
		return;
	}

	//Print root
	if (root->left) {
		cout << root->left->data << " => ";
	} else {
		cout << "END => ";
	}
	cout << root->data << " <= ";
	if (root->right) {
		cout << root->right->data << endl;
	} else {
		cout << "END" << endl;
	}


	// Print left subtree
	printPre(root->left);

	// Print right subtree
	printPre(root->right);

}

int main() {
	int n; cin >> n;
	int pre[n], in[n];

	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}

	node* root = buildTree(pre, in, 0, n);
	printPre(root);
}

//