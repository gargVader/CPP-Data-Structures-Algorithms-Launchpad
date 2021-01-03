/*
Car b = a 	// Copy constructor invoked

Car b;
b = a	// Copy assignment operator invoked
Suffers from the same problem that if we have some pointers in our
class then it will create shallow copy
*/

#include <bits/stdc++.h>
using namespace std;

// Class declared
class Car {

private:
	int price;

public:
	int model;
	//string name;
	// char name[100];
	char *name;

	void start() {
		cout << "vrroooom.....vrroooom....." << endl;
	}

	void setPrice(int p) {
		price = (p < 1000) ? 1000 : p; // Minimum price will be 1000
	}

	int getPrice() {
		return price;
	}

	// Constructor
	Car() {
		// Overriding the default constructor
		cout << "Making a car..." << endl;
	}
	// Constructor with parameters - Parameterised Constructor
	Car(int p, int mn, char *n) {
		cout << "Making a car..." << endl;
		price = p;
		model = mn;
		// First allocate memory
		name = new char[strlen(n) + 1];
		// Then copy into name the contents of n
		strcpy(name, n);
	}

	// copy costructor
	Car(Car &x) {
		price = x.getPrice();
		model = x.model;
		//name = x.name; // default Shallow copy
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	void print() {
		cout << model << endl << price << endl << name << endl;
	}

	// Copy assignment operator
	void operator=(Car &x) {
		cout << "Inside copy assignment operator" << endl;
		price = x.getPrice();
		model = x.model;
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

};

int main() {

	Car a(75000, 2021, "BMW");
	Car b;

	b = a;

	//b.name = "AMW"; // Working like deep copy
	b.name[0] = 'A'; // Working like shallow copy
	b.setPrice(50000);

	a.print();
	b.print();

}