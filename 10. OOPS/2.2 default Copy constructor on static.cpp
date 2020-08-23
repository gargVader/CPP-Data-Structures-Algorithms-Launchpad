// ***********Using default copy constructor on static variables***********
// Result: Deep copy

#include <iostream>
using namespace std;

// Class declared
class Car {

private:
	int price;

public:
	int model;
	string name; // *******If we have a static variable like this, then
	// the copy created shall always be deep*******

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

	void print() {
		cout << model << endl << price << endl << name << endl;
	}

};

int main() {

	Car a(75000, 2020, "BMW");
	Car b(a);

	b.name = "Honda";

	a.print();
	b.print();

}