#include <bits/stdc++.h>
using namespace std;

int main() {

	int a[] = {1, 2, 3};
	cout << a << endl;  // default

	char b[] = {'a' , 'b', 'c', 'd'};
	cout << b << endl; // overloaded for character array

	char s[10];
	cin >> s;
	cout << s << endl;

	char c[] = "hello"; // 6 bytes
	char d[] = {'h', 'e', 'l', 'l', 'o'}; // 5 bytes

	cout << c << " " << sizeof(c) << endl;
	cout << d << " " << sizeof(d) << endl;
}
