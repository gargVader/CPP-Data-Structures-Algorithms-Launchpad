// Implemented using Hashtable
// Insertion, erase, find in average O(1)
#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {

	unordered_map<string, int> um;
	// Insert
	um.insert(make_pair("Pizza", 100));
	um["Pasta"] = 120;

	// Search
	// auto = map<String, int>::iterator
	auto it = um.find("Pizza"); // Returns iterator
	if (it != um.end()) {
		cout << um["Pizza"];
	} else {
		cout << "Not available";
	}

	// update
	um["Pizza"] = 150;

	// Alternative search
	// returns 1 if key present and 0 otherwise
	if (um.count("Pizza")) { // Returns
		cout << um["Pizza"];
	} else {
		cout << "Not available";
	}

	um["Zarfani Pulao"] = 170;
	um["Rajma"] = 80;
	um["Paneer"] = 100;

	for (auto it = um.begin(); it != um.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	for (auto it : um) {
		cout << it.first << " " << it.second << endl;
	}

	// Custom class as key



}
