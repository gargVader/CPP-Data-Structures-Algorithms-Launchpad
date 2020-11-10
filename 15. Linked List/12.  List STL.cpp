#include<iostream>
#include<list>
using namespace std;

/*

list - Doubly Linked List

.back()
.front()
.begin()
.end()
.erase(index)
.remove(value)
.clear()
.empty() - true if container size is 0
.size()
.insert(pos, val)
.insert(pos, size, value) fill
.pop_back()
.pop_front()
.push_back()
.push_front()
.sort()


*/


int main() {

	list<int> l;

	list<int> l1{1, 2 , 5 , 10, 20};
	list<string> l2{"India", "Japan", "China", "Brazil"};

	l2.push_back("Sweden");

	l2.sort();

	l2.reverse();

	cout << l2.front() << endl;;
	l2.pop_front();

	l2.push_front("Pakistan");


	l2.push_back("Mongolia");
	l2.remove("China");
	auto it = l2.begin();
	it ++;
	it++;
	// l2.erase(it);

	l2.insert(it, "Korea");

	for (auto s : l2) {
		cout << s << "->";
	} cout << endl;

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << (*it) << "->";
	} cout << endl;

}