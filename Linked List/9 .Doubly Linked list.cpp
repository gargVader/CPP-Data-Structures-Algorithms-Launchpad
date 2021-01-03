#include<iostream>
using namespace std;

class node {
public:
	node *prev = NULL;
	int data = 0;
	node *next = NULL;

	node(int d) {
		data = d;
	}
};

void insertAtHead(node *&head, int d) {

	node *temp = new node(d);

	if (head == NULL) {
		head = temp;
		return;
	}

	temp->next = head;
	head->prev = temp;
	head = temp;
}

int length(node *head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

void insertAtTail(node *&head, int d) {
	node *temp = new node(d);
	if (head == NULL) {
		head = temp;
		return;
	}

	node *curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = temp;
	temp->prev = curr;

}


void insertAtMiddle(node *&head, int pos, int d) {

	if (head == NULL || pos == 0) {
		insertAtHead(head, d);
		return;
	}

	if (pos >= length(head)) {
		insertAtTail(head, d);
		return;
	}
	node *temp = new node(d);
	node *curr = head;

	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	temp->next = curr->next;
	curr->next->prev = temp;

	curr->next = temp;
	temp->prev = curr;

}

void take_input(node *&head) {
	int x;
	while (cin >> x) {
		insertAtTail(head, x);
	}
}


void print(node *head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
}

ostream& operator<<(ostream &os, node *head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node *&head) {
	take_input(head);
	return is;
}

void deleteAtHead(node *&head) {
	if (head == NULL) {
		return;
	}

	node *temp = head;

	head = head->next;
	delete temp;
}

void deleteAtTail(node *&head) {
	if (head == NULL || head->next == NULL) {
		deleteAtHead(head);
		return;
	}

	node *curr = head;

	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = NULL;
	delete temp;
}

void deleteAtMiddle(node *&head, int pos) {
	if (head == NULL || pos == 0) {
		deleteAtHead(head);
		return;
	}

	if (pos >= length(head)) {
		deleteAtTail(head);
		return;
	}

	node *curr = head;

	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = curr->next;

	curr->next = temp->next;
	temp->next->prev = curr;

	delete temp;
}

bool search(node *head, int key) {
	while (head != NULL) {
		if (head->data == key) {
			return 1;
		}

		head = head->next;
	}
	return 0;
}

bool searchRecursive(node *head, int key) {
	// Base Case
	if (head == NULL) {
		return 0;
	}

	if (head->data == key) {
		return 1;
	}

	return searchRecursive(head->next, key);
}


int main() {

	node *a = NULL;
	insertAtHead(a, 1);
	insertAtHead(a, 2);
	insertAtHead(a, 3);
	insertAtHead(a, 4);

	insertAtTail(a, 200);

	deleteAtHead(a);
	deleteAtTail(a);
	deleteAtMiddle(a, 1);

	cout << search(a, 1) << endl;
	cout << search(a, 5) << endl;


	print(a);
}