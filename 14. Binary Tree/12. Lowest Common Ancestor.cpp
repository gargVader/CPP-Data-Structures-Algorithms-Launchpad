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



int main() {
	node *root = buildTree();
	cout << lca(root, 4, 11)->data << endl;
}

// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1