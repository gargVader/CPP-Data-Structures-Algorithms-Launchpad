#include <iostream>
#include "Hashtable.h"
using namespace std;

int main() {

	Hashtable<int> menu;
	menu.insert("Burger", 100);
	menu.insert("Pizza", 250);
	menu.insert("Pepsi", 40);
	menu.insert("Coke", 150);
	menu.insert("Noodles", 100);
	menu.insert("BurgerPizza", 100);
	menu.print(); cout << endl;

	menu.erase("Coke");
	int *price_coke = menu.search("Coke");
	if (price_coke) {
		cout << *price_coke;
	} else {
		cout << "Not found";
	}
	cout << endl;

	menu.print(); cout << endl;

	// Operator Overloading
	// Insert
	menu["Coke"] = 20;
	// Update
	menu["Coke"] += 50;
	// Search
	cout << menu["Coke"] << endl;

	menu.print(); cout << endl;

}
