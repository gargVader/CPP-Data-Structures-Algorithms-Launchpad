#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	string key;
	T value;
	Node<T>* next = NULL;
	Node(string key, T value) {
		this->key  = key;
		this->value = value;
	}
	~Node() {
		if (next != NULL) {
			delete next; //  recursive delete
		}
	}
};

template<typename T>
class Hashtable {

private:
	Node<T> ** table; // Pointer to an array of pointers
	int current_size; // Current number of elements in hashtable
	int table_size;

	int hashFn(string key) {
		int index = 0;
		int p = 1;
		for (int i = 0; i < key.length(); i++) {
			index += (key[i] * p) % table_size;
			index = index % table_size;
			p = (p * 27) % table_size;
		}
		return index;
	}

	void rehash() {
		Node<T> **oldTable = table;
		table_size *= 2;
		table = new Node<int>*[table_size];
		// Initialiazation
		for (int i = 0; i < table_size; i++) {
			table[i]  = NULL;
		}
		current_size = 0;

		// Shifting elements
		for (int i = 0; i < table_size / 2; i++) {
			Node<T> *temp = oldTable[i];
			// Iterating through temp ll
			while (temp) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			if (oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}
		delete[] oldTable;
		// new table was cretaed with the "table" variable
		// itself as it helps during insertion.

	}

	void printLL(Node<T> *head) {
		while (head) {
			cout << "(" << head->key << "," << head->value << ") ";
			head = head->next;
		}
	}

public:
	Hashtable(int ts = 7) {
		table_size = ts;
		table = new Node<T>*[table_size]; // table of pointers
		current_size = 0;
		// Initialisation
		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}

		// array of Students
		//Student *s = new Student[10];
		// array of student pointers
		//Student **s = new Student*[10]
	}

	void insert(string key, T value) {
		int index = hashFn(key);
		Node<T> *node = new Node<T>(key, value);
		// table[index] is a linked list
		// Insert at head of the ll
		node->next = table[index]; // node is now pointing to where table[index] is also pointing
		table[index] = node; // head is now pointing to node
		current_size++;

		//Rehashing
		float load_factor = current_size / (1.0 * table_size);
		if (load_factor >= 0.7) {
			rehash();
		}


	}

	T* search(string key) {
		int index = hashFn(key);
		Node<T>* temp = table[index];
		while (temp) {
			if (temp->key == key) {
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL; // T*
	}

	void erase(string key) {
		int index = hashFn(key);
		Node<T>* temp = table[index];

		// toBeDeleted is at head
		if (temp && temp->key == key) {
			table[index] = temp->next;
			temp->next = NULL;
			delete temp;
			return;
		}

		while (temp->next && temp->next->key != key) {
			temp = temp->next;
		}
		if (temp->next) {
			Node<T> *toBeDeleted = temp->next;
			temp->next = toBeDeleted->next;
			// toBeDeleted->next has to be set to NULL, otherwise the delete function will recursively
			// delete the entire linked list after that
			toBeDeleted->next = NULL;
			delete toBeDeleted;
		}
	}

	// void erase(string key) {
	// 	int index = hashFn(key);
	// 	Node<T>* temp = table[index];
	// 	Node<T>* prev = NULL;

	// 	while (temp != NULL) {
	// 		if (temp->key == key) {
	// 			if (prev) {
	// 				prev->next = temp->next;
	// 			}
	// 			else {
	// 				table[index] = temp->next;
	// 			}
	// 			temp->next = NULL;
	// 			delete temp;
	// 			return ;
	// 		}
	// 		prev = temp;
	// 		temp = temp->next;
	// 	}
	// }



	void print() {
		// printing table
		for (int i = 0; i < table_size; i++) {
			cout << i << " ";
			printLL(table[i]);
			cout << endl;
		}
	}

	T& operator[](string key) {
		T* f = search(key);
		if (f == NULL) {
			// Insert key,value in the hashmap
			T garbage;
			insert(key, garbage);
			f = search(key);
		}

		return *f;
	}
};

// int main() {

// 	Hashtable<int> menu;
// 	menu.insert("Burger", 100);
// 	menu.insert("Pizza", 250);
// 	menu.insert("Pepsi", 40);
// 	menu.insert("Coke", 150);
// 	menu.insert("Noodles", 100);
// 	menu.insert("BurgerPizza", 100);
// 	menu.print(); cout << endl;

// 	menu.erase("Coke");
// 	int *price_coke = menu.search("Coke");
// 	if (price_coke) {
// 		cout << *price_coke;
// 	} else {
// 		cout << "Not found";
// 	}
// 	cout << endl;

// 	menu.print(); cout << endl;


// }
