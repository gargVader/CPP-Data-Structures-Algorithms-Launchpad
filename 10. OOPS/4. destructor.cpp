/*
Destructor
	- Clears out memory occupied by the object
	- automatically invoked when the object goes out of scope
	- except for cases when you dynamically allocated memory

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

	// Destructor
	~Car() {
		cout << "Destroying car " << name << endl;
		if (name != NULL) {
			delete [] name;
		}
	}

};

int main() {

	Car a(75000, 2021, "BMW");
	Car b;

	b = a;

	//b.name = "AMW"; // Working like deep copy
	b.name[0] = 'A'; // Working like shallow copy

	b.setPrice(50000);

	Car *c = new Car(100000, 2021, "Ferrari"); // Remains in the memory
	c->print();
	delete c;


	// a.print();
	// b.print();

}