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

};

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

void printBfs(node* root) {

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

void verticalPrint(node* root, int pos, map<int, vector<int>> &mp) {

	if (root == NULL) {
		return;
	}

	mp[pos].push_back(root->d);

	verticalPrint(root->left, pos - 1, mp);
	verticalPrint(root->right, pos + 1, mp);

}

int main() {

	node *root;
	int n; cin >> n; // Number of levels
	levelOrderBuild(root);
	// printBfs(root);
	map<int, vector<int>> mp;
	verticalPrint(root, 0, mp);

	for (auto p : mp) {
		vector<int> v = p.second;

		for (auto x : v) {
			cout << x << " ";
		} cout << endl;
	}
}
