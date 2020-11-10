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

node* buildTree(int a[], int s, int e) {
	// Base Case
	if (s >= e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = buildTree(a, s, mid);
	root->right = buildTree(a, mid + 1, e);
	return root;
}


void solve() {
	int n; cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	node* root = buildTree(a, 0, n);
	printPre(root);
	cout << endl;

}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}