#include <bits/stdc++.h>
using namespace std;

// Class declared
class Car {

private:
	int price;

public:
	int model;
	string name;

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
	Car(int p, int mn, string n) {
		cout << "Making a car..." << endl;
		price = p;
		model = mn;
		name = n;
	}
	// Copy Constructor
	Car(Car &x) {
		cout << "Making a copy of car..." << endl;
		name = x.name;
		price = x.getPrice();
		model = x.model;
	}

	void print() {
		cout << model << endl << price << endl << name << endl;
	}

};

int main() {

	Car c; // Object: Instance of class
	//Car d[100]; Array of objects

	cout << sizeof(c) << endl;
	cout << sizeof(Car) << endl;

	// Setting values
	c.name = "BMW";
	c.model = 245;
	// c.price = 75000
	c.start();

	// This is wrong
	// char s[100];
	// s = "hey"

	// Getters and setters

	c.setPrice(5000);
	cout << c.getPrice() << endl;

	// In earlier method we were directly dealing with the variable.
	// But now we are dealing with two functions. These two functions will
	// implement any constraints.

	Car d; // Invoking normal constructor
	Car e(100, 2001, "Audi"); // Invoking parameterised constructor
	e.print();


	// Copy Constructor - Creates a copy of the given object of
	// the same type

	Car f(e); // Object f will be same as object e
	//Car f = e;
	f.setPrice(90000);
	f.name = "TATA";
	f.print();

}