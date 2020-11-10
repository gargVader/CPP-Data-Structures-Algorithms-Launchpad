/*

1. Const data members
	- once initialised, they cannot change their value
2. Initialisation list
	- init const and other data memebers before allocating memory for the object
3. Const Parameters
	- which donot get updated inside that function
4. Const Functions
	- which donot update data members of the class
	- we declare a function to be constant when it doesnot require to
	  change its data members

*/

#include <bits/stdc++.h>
using namespace std;

// Class declared
class Car {

private:
	int price;

public:
	int model;
	const int msp; // No more assignment operations possible
	//string name;
	// char name[100];
	char *name;

	void start() {
		cout << "vrroooom.....vrroooom....." << endl;
	}

	void setPrice(const int p) {
		price = (p < 1000) ? 1000 : p; // Minimum price will be 1000
	}

	int getPrice() const { // cz it doesnot require to change the price
		return price;
	}

	// Constructor
	Car(): msp(1000) { // Before entering the block and allocating
		// the memory for object, we are
		// initialising msp.
		// Overriding the default constructor
		cout << "Making a car..." << endl;
	}
	// Constructor with parameters - Parameterised Constructor
	Car(int p, int mn, char *n, int minprice = 1000): price(p), msp(minprice) {
		cout << "Making a car..." << endl;
		price = p;
		model = mn;
		// First allocate memory
		name = new char[strlen(n) + 1];
		// Then copy into name the contents of n
		strcpy(name, n);
	}

	// copy costructor
	Car(const Car &x): msp(x.msp) {
		price = x.getPrice();
		model = x.model;
		//name = x.name; // default Shallow copy
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	void print() const {
		cout << model << endl << price << endl << name << endl;
	}

	// Copy assignment operator
	void operator=(const Car &x) {
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
	cout << a.msp << endl;

}