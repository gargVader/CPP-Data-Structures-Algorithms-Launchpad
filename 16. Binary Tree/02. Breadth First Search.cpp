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

	if (root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node *f = q.front();

		if (f == NULL) {
			//cout << endl;
			q.pop();

			// If after popping NULL, queue is empty that means it has no more children and we have reached the end or leaf node
			if (!q.empty()) {
				q.push(NULL);
			}

		} else {
			if (q[1] == NULL) {
				cout << f->data << " ";
			}
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

int main() {
	node *root = buildTree();
	bfs(root); cout << endl;
}