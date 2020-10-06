#include<iostream>
#include<algorithm>
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

int it = 0; // For keeping track in pre[]
// s,e define the part of in[] that the function is being called
node* buildTreeFromPreIn(int pre[], int in[], int s, int e) {
	if (s >= e) {
		return NULL;
	}

	node* root = new node(pre[it]);

	// Search for pre[it] in in[]
	int i = s;
	for (i = e - 1; i >= s; i--) {
		if (pre[it] == in[i]) {
			break;
		}
	}

	root->left = buildTreeFromPreIn(pre, in, s, it);
	root->right = buildTreeFromPreIn(pre, in, it + 1, e);

	return root;
}

void printPre(node* root) {
	// Base Case
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}

node* minimum(node* root) {

	// Spl. case
	if (root == NULL) {
		return NULL;
	}

	if (root->left) {
		return minimum(root->left);
	} else {
		return root;
	}
}


node* deleteInBST(node* root, int key) {
	// Base Case
	if (root == NULL) {
		return NULL;
	}


	if (root->data == key) {
		// Case 1: No children
		if (!root->left && !root->right) {
			delete root;
			return NULL;
		}

		// Case 2: One child
		if (root->left && !root->right) {
			node* temp = root->left;
			delete root;
			return temp;
		}

		if (root->right && !root->left) {
			node* temp = root->right;
			delete root;
			return temp;
		} else {
			// Case 3: Two children - Replaced by minimum of right subtree or maximum of left substree
			node* min = minimum(root);
			root->data = min->data;
			root->right = deleteInBST(root->right, min->data);
			return root;
		}
	}

	else if (key < root->data) return deleteInBST(root->left, key);
	else  return deleteInBST(root->right, key);
}


void solve() {
	int n; cin >> n;
	int pre[n];
	int in[n];
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
		in[i] = pre[i];
	}
	sort(in, in + n);
	// First build BST from preOrder and inOrder
	node* root = buildTreeFromPreIn(pre, in, 0, n);

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		root = deleteInBST(root, x);
	}

	printPre(root);
}


int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}