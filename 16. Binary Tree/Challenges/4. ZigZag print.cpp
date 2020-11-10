#include<iostream>
#include<stack>
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

bool leftToRight = 1;
void zigzagPrint(node* root) {

	stack<node*> curr, next;
	if (root) curr.push(root);

	while (!curr.empty()) {
		node* top = curr.top();
		curr.pop();
		cout << top->data << " ";

		// Push top's children
		if (leftToRight) {
			if (top->left) next.push(top->left);
			if (top->right) next.push(top->right);
		} else {
			if (top->right) next.push(top->right);
			if (top->left) next.push(top->left);
		}

		// Swap curr and next iff curr is empty
		if (curr.empty()) {
			leftToRight = !leftToRight;
			stack<node*> temp = curr;
			curr = next;
			next = temp;
		}
	}
}

int main() {
	node *root = buildTree();
	zigzagPrint(root);
}

// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1