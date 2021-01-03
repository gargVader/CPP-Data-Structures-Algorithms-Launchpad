#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	vector<node*>tree;

	node(int d, int numOfChildren) {
		tree.resize(numOfChildren);
		data = d;
	}
};

node* buildTree() {

	int data, numOfChildren;
	cin >> data;
	if (data == 0) {
		return NULL;
	}
	cin >> numOfChildren;

	node* root = new node(data, numOfChildren);
	for (int i = 0; i < numOfChildren; i++) {
		root->tree[i] = buildTree();
	}

	return root;

}

int numLeaves(node* root) {
	int count = 0;

	if (root == NULL) return 0;
	if (root->tree.size() == 0) return 1;

	for (int i = 0; i < (root->tree.size()); i++) {
		count += numLeaves(root->tree[i]);
	}

	return count;

}



int main() {

	node *root = buildTree();
	cout << numLeaves(root) << endl;
	//cout << root->tree.size() << endl;

}
