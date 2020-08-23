// ***********Using default copy constructor on dynamic variables***********

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

};

int main() {

	Car a(75000, 2021, "BMW");
	Car b(a);

	//b.name = "AMW"; // Working like deep copy
	b.name[0] = 'A'; // Working like shallow copy
	b.setPrice(50000);

	a.print();
	b.print();

}