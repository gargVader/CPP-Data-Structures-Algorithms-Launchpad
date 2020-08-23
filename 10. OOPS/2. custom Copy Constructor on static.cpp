// ***********Using custom copy constructor on static variables***********
// Result: Deep copy

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
	// *****This code is always creating deep copy**********
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


	// Copy Constructor - Creates a copy of the given object of the same type
	Car a(75000, 2020, "BMW");
	a.print();

	Car b(a);
	b.name = "Honda";
	b.setPrice(50000);
	a.print();
	b.print();

}