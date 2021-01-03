/*
strtok() -> break a string into a list of tokens

char *strtok(char *s, char *delimeters)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	char s[100] = "Today is a rainy day";

	char *ptr = strtok(s, " ");

	while (ptr) {
		cout << ptr << endl;
		ptr = strtok(NULL, " ");
	}
	// strtok maintains the state of the string
}
