#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insert(node *&head, int d) {
	node *temp = new node(d); // New node created
	node *curr = head;

	temp->next = head;

	if (head != NULL) {
		// Bringing curr to last node
		while (curr->next != head) {
			curr = curr->next;
		}
		curr->next = temp;
	} else {
		temp->next = temp;
	}

	head = temp;
}

void print(node *head) {
	node *curr = head;
	while (curr->next != head) {
		cout << curr->data << "->";
		curr = curr->next;
	} cout << curr->data << "->";
	return;
}

int main() {

	node *a = NULL;

	insert(a, 1);
	insert(a, 2);
	insert(a, 3);
	insert(a, 4);

	print(a);

}