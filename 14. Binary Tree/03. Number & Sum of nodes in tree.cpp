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

void bfs(node *root) {
	int num = 0, sum = 0;
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node *f = q.front();
		//cout << f->data << " ";
		if (f != NULL) {
			num++;
			sum += f->data;
		}

		q.pop();
		if (f->left) {
			q.push(f->left);
		}
		if (f->right) {
			q.push(f->right);
		}
	}

	cout << "BFS Traversal:  NumOfNodes=" << num << " SumOfNodes=" << sum << endl;

}

int numNodes(node *root) {

	// Base Case
	if (root == NULL) {
		return 0;
	}

	return numNodes(root->left) + numNodes(root->right) + 1;

}

int sumOfNodes(node *root) {
	// Base Case
	if (root == NULL) {
		return 0;
	}
	return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}


int main() {
	node *root = buildTree();

	bfs(root);

	cout << "Pre-Order Traversal:  NumOfNodes=" << numNodes(root) << " SumOfNodes=" << sumOfNodes(root) << endl;
}