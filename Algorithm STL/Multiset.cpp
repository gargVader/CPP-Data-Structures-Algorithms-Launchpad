/*
Multiset
========
It can store multiple elements that have same value stored in a specific
sorted order according to the internal comparison object.

Values once stored cannot be modified
Associative Container : Elements are referred by their value and not by the index
Underlying implementation : BST
*/
#include<iostream>
#include<set>
using namespace std;

#define It multiset<int>::iterator

int main() {
	int a[] = {1, 19, 1, 2, 4, 12, 9, 45, 2, 56, 19, 19, 19};
	int n = sizeof(a) / sizeof(a[0]);

	multiset<int> m(a, a + n);

	// erase
	m.erase(1); // erases all occurences of 1

	// insert
	m.insert(80);

	// count of a particular value
	cout << "count of " << "2 = " << m.count(2) << endl;

	//Iterate
	for (auto x : m) {
		cout << x << " ";
	} cout << endl;

	// Find
	auto it = m.find(19); //gives iterator to the first element equal to 19
	// if the element is not present *it = n
	cout << *it << endl;

	// Get all elements equal to 19
	// equal_range() gives me a pair of iterators:
	//	- 1st iterator points to the first occurence of 19
	//	- 2nd iterator points to the loc after the last occurence of 19
	pair<It, It> p =  m.equal_range(19);

	for (auto it = p.first; it != p.second; it++) {
		cout << *it << " - ";
	} cout << endl;

	// Lower bound and upper bound
	for (auto it = m.lower_bound(10); it != m.upper_bound(50); it++) {
		cout << *it << " ";
	} cout << endl;


}