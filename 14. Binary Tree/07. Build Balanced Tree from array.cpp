#include<iostream>
#include <queue>
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

class Pair {
public:
	int height = 0;
	bool balanced = 1;
};

node* buildTree() {
	int d; cin >> d;

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

void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node *f = q.front();
		if (f == NULL) {
			// prev level is complete. so print endl
			cout << endl;
			q.pop();
			// prev level has also pushed all its children. So push endl
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->data << " ";

			q.pop();

			if (f->left != NULL) {
				q.push(f->left);
			}
			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}

}

node* buildBalancedTree(int arr[], int s, int e) {

	if (s == e) {
		return NULL;
	}

	int mid = (s + e) / 2;

	node* root = new node(arr[mid]);
	root->left = buildBalancedTree(arr, s, mid);
	root->right = buildBalancedTree(arr, mid + 1, e);

	return root;
}



int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	node *root = buildBalancedTree(arr, 0, n);
	printPre(root); cout << endl;
	bfs(root);
}