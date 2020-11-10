#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
	int value;
	int i;
	int j;

	Node(int value, int i, int j) {
		this->value = value;
		this->i = i;
		this->j = j;
	}

};


class NodeCompare {
public:
	bool operator()(Node a, Node b) {
		return a.value > b.value;
	}
};

int main() {

	vector<vector<int>> a{
		{2, 6, 12, 15},
		{1, 3, 14, 15},
		{3, 5, 8, 10}
	};

	int k = a.size();

	priority_queue<Node, vector<Node>, NodeCompare> pq; // minHeap

	for (int i = 0; i < k; i++) {
		Node node(a[i][0], i, 0);
		pq.push(node);
	}

	vector<Node> ans;

	while (pq.size()) {
		Node f = pq.top();
		pq.pop();
		// Store ans
		ans.push_back(f);
		cout << f.value << " ";

		// Push next element of same row
		int row = f.i;
		int col = f.j;

		if (col + 1 < a[row].size()) {
			Node new_node(a[row][col + 1], row, col + 1);
			pq.push(new_node);
		}
	}

}