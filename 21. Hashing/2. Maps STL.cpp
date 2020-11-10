// Implemented using BST

#include <iostream>
#include<string>
#include<map>
using namespace std;

int main() {

	map<string, int> m;

	// Insert
	m.insert(make_pair("Pizza", 100));
	m["Pasta"] = 120;

	// Search
	// auto = map<String, int>::iterator
	auto it = m.find("Pizza"); // Returns iterator
	if (it != m.end()) {
		cout << m["Pizza"];
	} else {
		cout << "Not available";
	}

	// update
	m["Pizza"] = 150;

	// Alternative search
	// returns 1 if key present and 0 otherwise
	if (m.count("Pizza")) { // Returns
		cout << m["Pizza"];
	} else {
		cout << "Not available";
	}

	m["Zarfani Pulao"] = 170;
	m["Rajma"] = 80;
	m["Paneer"] = 100;

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	for (auto it : m) {
		cout << it.first << " " << it.second << endl;
	}

}
