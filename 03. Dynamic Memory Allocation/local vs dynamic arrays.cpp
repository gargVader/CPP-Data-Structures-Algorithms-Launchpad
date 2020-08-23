// Local arrays vs dynamic arrays

#include<iostream>
using namespace std;

int* fun() {
	int *a = new int[5] {1, 2, 3, 4, 5};
	cout << a << endl;
	cout << a[2] << endl;
	return a;
}

// int* fun() {
// 	int a[] = {1, 2, 3, 4, 5};
// 	cout << a << endl;
// 	cout << a[0] << endl;
// 	return a;
// }

int main() {
	int *b = fun();
	cout << b << endl;
	cout << b[2] << endl;
	delete[] b;
}

