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

node* buildTree() {
	int d, n; cin >> d >> n;

	node* root = new node(d);

	if (n == 0) {
		return root;
	}
	if (n == 1) {
		root->left = buildTree();
		return root;
	} else {
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
}
int sum = 0;
void sumAtK(node* root, int k) {
	// Base Case
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		sum += root->data;
		return;
	}

	sumAtK(root->left, k - 1);
	sumAtK(root->right, k - 1);
}


void solve() {
	node* root = buildTree();
	int k; cin >> k;
	sumAtK(root, k);
	cout << sum << endl;
}

int main() {
	// int t; cin >> t;
	// while (t--) {
	solve();
	// }
}