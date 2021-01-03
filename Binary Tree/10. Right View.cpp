#include<iostream>
#include<queue>
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

// bfs with newline character
void bfs(node *root) {

	if (root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node *f = q.front();

		if (f == NULL) {
			cout << endl;
			q.pop();

			// If after popping NULL, queue is empty that means it has no more children and we have reached the end or leaf node
			if (!q.empty()) {
				q.push(NULL);
			}

		} else {
			cout << f->data << " ";

			q.pop();

			if (root->left) {
				q.push(root->left);
			}
			if (root->right) {
				q.push(root->right);
			}
		}
	}

}

int maxLevel = 0;
void rightView(node *root, int h = 1) {

	// Base Case
	if (root == NULL) { // crossed the leaf node
		return;
	}

	if (h > maxLevel) {
		// have discovered a new level
		cout << root->data << " ";
		maxLevel++;
	}

	// call on right
	if (root->right) {
		rightView(root->right, h + 1);
	}

	if (root->left) {
		rightView(root->left, h + 1);
	}

}

int main() {
	node *root = buildTree();
	rightView(root, 1);
}

// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1