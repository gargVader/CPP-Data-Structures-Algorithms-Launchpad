#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> a) {
	for (int x : a) {
		cout << x << " ";
	} cout << endl;
}

int main() {
	vector<int> a;
	vector<int> b(5, 10); // five int with value 10
	vector<int> c(b.begin(), b.end());
	vector<int> d{1, 2, 3, 4, 5};

	// pop_back : removes the last element
	d.pop_back();

	// insert elemnts in the middle of the vector: O(n)
	d.insert(d.begin() + 2, 200);
	print(d);

	d.insert(d.begin() + 2, 3, 200);
	print(d);

	// erase some elements from the middle of the vector
	d.erase(d.begin() + 1);
	d.erase(d.begin() + 1, d.begin() + 5);

	// we avoid shrink
	d.resize(18); // if the size is increasing then more memory is allocated
	cout << d.capacity() << endl;

	// Remove all elements of the vector
	// This doesnot delete the memory occupied by the array
	d.clear(); // size=0, capacity=18

	if (d.empty()) {
		cout << "This is an empty vector" << endl;
	}

	d.push_back(25);
	d.push_back(14);
	d.push_back(16);
	d.push_back(100);

	cout << d.front() << endl;
	cout << d.back() << endl;

	// Reserve
	vector<int> e;
	e.reserve(1000);
	for (int i = 0; i < 5; i++) {
		int num; cin >> num;
		e.push_back(num);
		cout << "Changing capacity " << e.capacity() << endl;
	}
	/*Doubling is an expensive operation. So pushing back in a case
	where we know that the user is going to input a minimum
	number of elements is slow, because doubling takes place many times */


	print(e);

}