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

void bfs(node *root) {
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node *f = q.front();
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

int i = 0;
node* buildTreePreIn(int pre[], int in[], int s, int e) {
	//Base Case
	if (s >= e) {
		return NULL;
	}


	node *root = new node(pre[i]);

	// search in in[]
	int j;
	for (j = s; j < e; j++) {
		if (in[j] == pre[i]) {
			break;
		}
	} i++;

	root->left = buildTreePreIn(pre, in, s, j);
	root->right = buildTreePreIn(pre, in, j + 1, e);

	return root;
}


int main() {

	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(pre) / sizeof(pre[i]);
	int in[n];
	for (int i = 0; i < n; i++) in[i] = pre[i];
	sort(in, in + n);

	node* root = buildTreePreIn(pre, in, 0, n);
	bfs(root);
}