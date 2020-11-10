#include <bits/stdc++.h>
using namespace std;

class Book {
public:
	string name;
	int price;

	Book() {

	}

	Book(string name, int price) {
		this->name = name;
		this->price = price;
	}

	void print() {
		cout << name << " " << price;
	}

};

bool compare(Book a, Book b) {
	if (a.name == b.name) {
		return a.price < b.price;
	}

	return a.name < b.name;
}

class BookCompare {
public:
	bool operator()(Book A, Book B) {

		if (A.name == B.name) {
			return true;
		}
		return false;


	}
};


// Template + Iterators + Comparators
template<class ForwardIterator, class T, class Compare> // Freeedom from all containers
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp) {

	while (start != end) {
		if (cmp(*start, key)) {
			return start;
		}
		start++;
	}

	return end;
}

int main() {

	Book b1("C++", 100);
	Book b2("Python", 120);
	Book b3("Java", 130);
	Book b4("C++", 110);

	vector<Book> l;

	l.push_back(b1);
	l.push_back(b2);
	l.push_back(b3);
	l.push_back(b4);

	BookCompare cmp;

	if (cmp(b1, b2)) {
		cout << "Same books" << endl;
	} else {
		cout << "Diff books" << endl;
	}


	auto it = search(l.begin(), l.end(), b4, cmp);

	if (it != l.end()) {
		cout << "Book found in the library" << endl;
	} else {
		cout << "Book not found" << endl;
	}


}