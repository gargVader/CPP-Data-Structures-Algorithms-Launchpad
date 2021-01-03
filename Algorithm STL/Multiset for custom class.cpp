#include<iostream>
#include<set>
using namespace std;

class person_compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second < p2.second;
	}
};


int main() {
	pair<string, int> p1 = make_pair("A", 10);
	pair<string, int> p2 = make_pair("B", 50);
	pair<string, int> p3 = make_pair("C", 20);
	pair<string, int> p4 = make_pair("D", 60);
	pair<string, int> p5 = make_pair("E", 60);

	multiset<pair<string, int>, person_compare> m;
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	m.insert(p4);
	m.insert(p5);

	for (auto p : m) {
		cout << p.first << "->" << p.second << endl;
	}

}