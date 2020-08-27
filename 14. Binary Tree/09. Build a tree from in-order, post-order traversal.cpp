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

int i = 8 - 1;
node* buildTreePostIn(int post[], int in[], int s, int e) {
	//Base Case
	if (s >= e) {
		return NULL;
	}


	node *root = new node(post[i]);

	// search in in[]
	int j;
	for (j = s; j < e; j++) {
		if (in[j] == post[i]) {
			break;
		}
	} i--;

	root->right = buildTreePostIn(post, in, j + 1, e);
	root->left = buildTreePostIn(post, in, s, j);

	return root;
}


int main() {

	int post[] = {3, 8, 4, 2, 7, 6, 5, 1};
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int n = sizeof(post) / sizeof(post[i]);

	node* root = buildTreePostIn(post, in, 0, n);
	bfs(root);
}