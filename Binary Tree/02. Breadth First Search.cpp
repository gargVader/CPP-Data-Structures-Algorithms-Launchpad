// bfs

#include<iostream>
#include<queue>
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

// Breadth First Traversal - Level Order in O(n)
// void bfs(node *root) {
// 	queue<node*> q;
// 	q.push(root);

// 	while (!q.empty()) {
// 		node *f = q.front();
// 		cout << f->data << " ";
// 		q.pop();
// 		if (f->left != NULL) {
// 			q.push(f->left);
// 		}
// 		if (f->right != NULL) {
// 			q.push(f->right);
// 		}
// 	}

// }

// bfs with newline character
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

int main() {
	node *root = buildTree();
	bfs(root); cout << endl;
}