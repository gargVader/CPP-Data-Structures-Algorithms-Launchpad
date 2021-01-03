#include <iostream>
#include <queue>
using namespace std;

class Person {
public:
	string name;
	int age;

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

};

class PersonCompare {

public:
	bool operator()(Person a, Person b) {
		return a.name < b.name;
	}
};

int main() {

	priority_queue<Person, vector<Person>, PersonCompare> pq;

	for (int i = 0; i < 3; i++) {
		string s; int a;
		cin >> s >> a;
		Person p(s, a);
		pq.push(p);
	}

	while (!pq.empty()) {
		Person p = pq.top();
		cout << p.name << " " << p.age << endl;
		pq.pop();
	}


}
