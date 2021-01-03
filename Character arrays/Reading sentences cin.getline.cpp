#include <bits/stdc++.h>
using namespace std;

/*
cin.get() -> reads a single character at a time
Put a loop to read characters till you get a new line '\n'

*/

void readLine(char a[], int maxLen, char delim = '\n') {
	int i = 0;
	char ch = cin.get();
	while (ch != delim) {
		a[i] = ch;
		i++;
		if (i == maxLen - 1) {
			break;
		}
		ch = cin.get();
	}
	a[i] = '\0';
}

int main() {

	// we want the program to keep reading the input until we get a newline chatacter '\n'
	char b[100];
	//readLine(b, 100);
	cin.getline(b, 100);
	cout << b << endl;

}
