#include <iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main() {

	unordered_map<string, vector<string>> phonebook;

	phonebook["Rahul"].push_back("9883180");
	phonebook["Rahul"].push_back("98831889540");
	phonebook["Jagmohan"].push_back("87999210");
	phonebook["Raj"].push_back("98461156");
	phonebook["Kajol"].push_back("79846513");

	for (auto it : phonebook) {
		cout << it.first << " ";
		for (auto x : it.second) {
			cout << x << " ";
		} cout << endl;
	}
}
