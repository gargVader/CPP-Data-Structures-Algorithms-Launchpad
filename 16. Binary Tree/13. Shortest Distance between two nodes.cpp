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

// Finding the level of a given node from the given root
int search(node* root, int key, int level) {
	// Base Case

	if (root == NULL) {
		return -1;
	}

	if (root->data == key) {
		return level;
	}

	int leftans = search(root->left, key, level + 1);
	if (leftans != -1) {
		return leftans;
	}
	int rightans = search(root->right, key, level + 1);
	return rightans;

}

// if for a particular node both a and b are present in different subtrees then thta node is the ans.
node* lca(node* root, int a, int b) {

	// Base Case
	if (root == NULL) {
		return NULL;
	}

	// if we have found any one of the nodes then return that node. It is preserved throughtout the tree
	if (root->data == a || root->data == b) {
		return root;
	}


	// continue searching in left and right
	node* leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);

	// that means leftans has something(which it must have got from children nodes) It must be a or b.
	// that means rightans has something(which it must have got from the children nodes). It must be a or b.
	// that means we have got both a and b in different subtrees.
	if (leftans != NULL && rightans != NULL) {
		return root;
	}

	// leftans has some address but rightans is NULL. This means that left has both a,b. eg: if leftans->data==a, then
	// since a occured first then b must be present below it. So leftans must be returned.
	if (leftans) {
		return leftans;
	}
	return rightans;
}

int findDistance(node* root, int a, int b) {
	node* lca_node = lca(root, a, b);
	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);
	return l1 + l2;
}


int main() {
	node* root = buildTree();
	cout << findDistance(root, 4, 7);

}