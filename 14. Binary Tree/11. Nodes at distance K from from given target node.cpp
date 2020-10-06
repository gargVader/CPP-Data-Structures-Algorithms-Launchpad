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

void printKthLevel(node *root, int k) {

	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);

}


int printAtDistanceK(node *root, node *target, int k) {
	// Base Case
	if (root == NULL) {
		return -1;
	}

	if (root == target) {
		printKthLevel(root, k);
		return 0;
	}

	// we are now at some ancestor

	// call on left subtree of ancestor
	// distance of left-subtree root from the target node . It will give DL=0
	int DL = printAtDistanceK(root->left, target, k);

	if (DL != -1) {
		// Target node is present in left subtree

		// Two cases: 1. print the ancestor node itself(K-2-DL==-1) 2. Otherwise call on right
		if (k - 2 - DL == -1) {
			cout << root->data << " ";
		} else {
			printKthLevel(root->right, k - 2 - DL);
		}
		return DL + 1;
	}

	int DR = printAtDistanceK(root->right, target, k);

	if (DR != -1) {
		// Target node is present in right subtree

		// Two cases: 1. print the ancestor node itself(K-2-DR==-1) 2. Otherwise call on right
		if (k - 2 - DR == -1) {
			cout << root->data << " ";
		} else {
			printKthLevel(root->left, k - 2 - DR);
		}
		return DR + 1;
	}

	// node was not present in the left or right part
	return -1;
}




int main() {
	node *root = buildTree();
	printAtDistanceK(root, root->left->left, 3);
}

// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1