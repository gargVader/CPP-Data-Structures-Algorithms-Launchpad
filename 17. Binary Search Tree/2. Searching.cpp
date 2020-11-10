#include<iostream>
#include<queue>
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

void printIn(node* root) {
	if (root == NULL) {
		return;
	}

	printIn(root->left);
	cout << root->data << " ";
	printIn(root->right);
}

void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {

			cout << f->data << " ";
			q.pop();

			if (f->left != NULL) q.push(f->left);
			if (f->right != NULL) q.push(f->right);
		}
	}

}

node* insertInBST(node* root, int d) {
	// Base Case
	if (root == NULL) {
		node* n = new node(d);
		return n;
	}

	if (d <= root->data) {
		root->left = insertInBST(root->left, d);
	} else {
		root->right = insertInBST(root->right, d);
	}

	return root;
}

node* buildTree() {

	int d; cin >> d;
	node* root = NULL;

	while (d != -1) {
		root = insertInBST(root, d);
		cin >> d;
	}

	return root;
}

bool search(node* root, int key) {

	if (root == NULL) {
		return 0;
	}

	if (root->data == key) {
		return 1;
	}

	if (key < root->data) {
		return search(root->left, key);
	} else {
		return search(root->right, key);
	}

}

int main() {
	node* root = buildTree();
	bfs(root); cout << endl;
	printIn(root); cout << endl;
	cout << search(root, 21) << endl;
	cout << search(root, 1);
}

// 5 9 3 32 4 2 1 6 -1