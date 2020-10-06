#include<iostream>
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

node* buildTree(int a[], int s, int e) {
	//Base Case
	if (s >= e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = buildTree(a, s, mid);
	root->right = buildTree(a, mid + 1, e);

	return root;
}

void printPre(node* root) {
	// Base Case
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}
int sum = 0;
void sumRep(node* root) {

	if (root == NULL) {
		return;
	}

	// right
	sumRep(root->right);

	// root
	sum += root->data;
	root->data = sum;
	// left
	sumRep(root->left);
}

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// for (int j = n - 2; j >= 0; j--) {
	// 	a[j] += a[j + 1];
	// }
	node* root = buildTree(a, 0, n);
	sumRep(root);
	printPre(root);
}


