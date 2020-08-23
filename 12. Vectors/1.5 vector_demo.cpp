#include<iostream>
#include "vector.h"
using namespace std;

int main() {
	Vector<char> v;

	v.push_back(71);
	v.push_back(2);
	v.push_back(73);
	v.push_back(4);
	v.push_back(5);
	v.pop_back();
	v.push_back(6);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} cout << endl;

	cout << "Capacity = " << v.capacity() << endl;
}
