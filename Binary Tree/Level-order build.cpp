#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int d;
	node* left = NULL;
	node* right = NULL;

	node(int d) {
		this->d = d;
	}

}

void levelOrderBuild(node* &root) {

	int d; cin >> d;
	root = new node(d);

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node *f = q.front();
		q.pop();

		int c1, c2; cin >> c1 >> c2;

		if (c1 != -1) {
			f->left = new node(c1);
			q.push(f->left);
		}

		if (c2 != -1) {
			f->right = new node(c2);
			q.push(f->right);
		}
	}
}

void bfs(node *root) {

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* f = q.front();
		q.pop();
		cout << f->d << " ";

		if (f->left) q.push(f->left);
		if (f->right) q.push(f->right);
	}

}



int main() {

	node *root;

	level_order_build(root); // 8 10 3 1 6 -1 14 -1 -1 9 7 13 -1 -1 -1 -1 -1 -1 -1
	print_BFS(root);

}
