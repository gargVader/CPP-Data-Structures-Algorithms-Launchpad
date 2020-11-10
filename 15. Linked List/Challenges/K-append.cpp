#include <iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(node *&head, int val) {

	if (head == NULL) {
		head = new node(val);
		return;
	}

	node *temp = new node(val);
	//(*temp).next = head;
	temp->next = head;

	head = temp;
}

int length(node*head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}

	return count;

}

void insertAtTail(node *&head, int val) {
	if (head == NULL) {
		head = new node(val);
		return;
	}

	// Take curr to last node
	node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	node *temp = new node(val);
	curr->next = temp;
}

void insertAtMiddle(node *&head, int pos, int val) {

	if (head == NULL || pos == 0) {
		insertAtHead(head, val);
		return;
	} else if (pos > length(head)) {
		insertAtTail(head, val);
		return;
	}

	// take pos-1 jumps
	node *curr = head;
	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = new node(val);

	temp->next = curr->next;
	curr->next = temp;
}

void deleteHead(node *&head) {
	if (head == NULL) {
		return;
	}
	node *temp = head;
	head = head->next;
	delete temp;
}

void deleteTail(node *&head) {
	node *curr =  head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = NULL;
	delete temp;
}

void deleteMiddle(node *&head, int pos) {

	if (head == NULL) {
		return;
	} else if (pos > length(head)) {
		deleteTail(head);
		return;
	} else if (pos == 0) {
		deleteHead(head);
		return;
	}

	node *curr = head;

	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = temp->next; // or curr->next->next;
	delete temp;

}

void print(node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

node* take_input() {
	node* head = NULL;
	int x;
	while (cin >> x) {
		insertAtTail(head, x);
	}
	return head;
}

// Operator Overloading
ostream& operator<<(ostream &os, node *head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node*&head) {
	head = take_input();
	return is;
}

int main() {

	int n; cin >> n;
	node *head; cin >> head;
	int k; cin >> k;

	cout << head << endl;

	node *curr = head;
	for (int i = 0; i < n - k - 1; i++) {
		curr = curr->next;
	}

	node *tail = head;

	while (tail->next != NULL) {
		tail = tail->next;
	}

	node *temp = curr->next;
	curr->next = NULL;

	tail->next = head;
	head = temp;

	cout << head;

}