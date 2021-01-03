/*
Subarray with maximum xor
=========================
1) O(n^3) generate all subarray
2) O(n^2) cumulative xor and then find xor of each subarray
3)

*/

#include <bits/stdc++.h>
using namespace std;

class Node {

public:
	Node* left = NULL;
	Node* right = NULL;
};

class Trie {
	Node *root;

public:
	Trie() {
		root = new Node();
	}

	void insert(int n) {
		Node* curr = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;

			if (bit) {
				// If curr has no right child
				if (curr->right == NULL) curr->right = new Node();
				curr = curr->right;
			} else {
				// If curr has no left child
				if (curr->left == NULL) curr->left = new Node();
				curr = curr->left;
			}
		}
	}

	// Returns the max xor pair that I can make by
	// inserting num, consdering the present state of the trie
	int maxXorHelper(int num) {

		Node* curr = root;
		int currAns = 0;

		for (int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;

			if (bit) {
				// I want to have 0
				if (curr->left != NULL) {
					curr = curr->left;
					currAns |= (1 << i);
				} else {
					curr = curr->right;
				}
			} else {
				// I want to have 1
				if (curr->right != NULL) {
					curr = curr->right;
					currAns |= (1 << i);
				} else {
					curr = curr->left;
				}
			}
		}

		return currAns;
	}

	int maxSubXor(int a[], int n) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			a[i] = temp ^ a[i];
			temp = a[i];
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			insert(a[i]);
			int temp = maxXorHelper(a[i]);
			ans = max(ans, temp);
			//cout << temp << endl;
		}

		return ans;

	}

};



int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	Trie t;
	cout << t.maxSubXor(a, n);

}
