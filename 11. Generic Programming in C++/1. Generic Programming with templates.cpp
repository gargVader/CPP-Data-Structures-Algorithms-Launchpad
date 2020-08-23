#include <bits/stdc++.h>
using namespace std;


// Template
template<typename T> // Freedom from all data types
int search(T arr[], int n, T key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) return i;
	}

	return n;
}

// If in a function, we want to pass two different data-types
// Template + Iterators
template<class ForwardIterator, class T> // Freeedom from all containers
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) {

	while (start != end) {
		if (*start == key) {
			return start;
		}
		start++;
	}

	return end;
}



int main() {

	/*
	int a[] = {1, 4, 2, 6, 10, 9, 7, 8};
	int n = sizeof(a) / sizeof(a[0]);
	cout << search(a, n, 10) << endl;

	float b[] = {1.2, 7.8, 9.1};
	float k = 7.8;
	cout << search(b, 3, k) << endl;

	char c[] = {'a', 'b', 'c'};
	cout << search(c, 3, 'c') << endl;
	*/

	list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	// Writing this means, that start has a data-type of name ForwardIterator
	// which is equal to list<int>::iterator
	auto it = search(l.begin(), l.end(), 5);
	cout << *it;

	BookCompare cmp;



}