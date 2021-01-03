#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node *left = NULL; // for 0
	Node* right = NULL; // for 1
};

class Trie {

	Node* root;
public:
	Trie() {
		root = new Node();
	}

	// Insert function
	// 5 = 00000101 [32]
	void insert(int n) {
		Node* curr = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;

			if (bit) {
				if (curr->right == NULL) {
					curr->right = new Node();
				}
				curr = curr->right;
			} else {
				if (curr->left == NULL) {
					curr->left = new Node();
				}
				curr = curr->left;
			}
		}
	}

	// Maximum xor that I can make by inserting num
	// considering the current state of the trie
	int maxXorHelper(int num) {

		// Initially I am at the root node
		Node* curr = root;

		int currAns = 0;

		for (int j = 31; j >= 0; j--) {
			int bit = (num >> j) & 1;
			if (bit) {
				// Then we want other bit to be 0
				if (curr->left != NULL) {
					curr = curr->left;
				} else {
					curr = curr->right;
					currAns += (1 << j);
				}
			} else {
				// Then we want other bit to be 1
				if (curr->right != NULL) {
					curr = curr->right;
					currAns += (1 << j);
				} else {
					curr = curr->left;
				}
			}

		}

		return currAns ^ num;

	}

	int maxXor(int a[], int n) {

		int ans = 0;

		for (int i = 0; i < n; i++) {
			insert(a[i]);
			int temp = maxXorHelper(a[i]);
			ans = max(ans, temp);
			cout << temp << endl;
		}
		return ans;
	}

};

int main() {

	int a[] = {3, 10, 5, 25, 2, 8};
	int n = sizeof(a) / sizeof(a[0]);

	Trie t;
	cout << t.maxXor(a, n);

}
