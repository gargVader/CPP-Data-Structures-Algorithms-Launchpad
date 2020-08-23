#include<iostream>
using namespace std;

int main() {

	int a[1000];
	// Gives size of array as a is an array
	cout << sizeof(a) << endl; // 4000

	// Here, b is just a pointer to an array
	int *b = new int[1000]; // 4
	cout << sizeof(b);


}