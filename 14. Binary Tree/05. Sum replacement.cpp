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

// we return root->data + suml + sumr, and update root->data = suml+sumr

int sumReplacement(node *root) {

	if (root == NULL) {
		return 0;
	}
	// Leaf node is to returned as it is
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int sum = root->data, suml = 0, sumr = 0;

	if (root->left) {
		suml = sumReplacement(root->left);
	}

	if (root->right) {
		sumr = sumReplacement(root->right);
	}

	sum += suml + sumr;
	root->data = suml + sumr;

	return sum;
}

int main() {
	node *root = buildTree();
	sumReplacement(root);
	printPre(root); cout << endl;
}