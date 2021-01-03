#include <bits/stdc++.h>
using namespace std;
/*
I need to store inside my function

1) Current state of the string: Use a dynamic array
2) How many tokens have been processed till now: Satic Variable

*/
char *mystrtok(char *str, char delim) {

	// input pointer to the start of current state of string
	static char *input = NULL;

	if (str != NULL) {
		// We are making the first call
		input = str;
	}// otherwise input is going to retain its state from the prev call

	// Base Case
	if (input == NULL) {
		return NULL; // After the final token ahs been extracted
	}

	// start extarcting tokens and store them in an array
	char *output = new char[strlen(input) + 1];
	int i = 0;
	for (; input[i] != '\0'; i++) {
		if (input[i] != delim) {
			output[i] = input[i];
		} else { // delim found
			output[i] = '\0'; // end output char
			input = (input + i) + 1; // jump to the next token
			return output; // return output char
		}
	}

	// Corner Case for last token, when no delim is present at the end
	output[i] = '\0';
	input = NULL; // For the base case, when we have reached the end of the string. So that in the
	// next function call we can return NULL


	return output;

}

int main() {

	char s[100] = "Today is a rainy day";

	char *ptr = mystrtok(s, ' ');

	while (ptr != NULL) {
		cout << ptr << endl;
		ptr = mystrtok(NULL, ' ');
	}

}
