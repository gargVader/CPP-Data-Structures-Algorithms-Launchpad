#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Car {
public:
	string name;
	int x;
	int y;
	Car(string name, int x, int y) {
		this->name = name;
		this->x = x;
		this->y = y;
	}

	void print() {
		cout << name << " " << x << " " << y << endl;
	}
};

bool compare(Car a, Car b) {
	int d1 = a.x * a.x + a.y * a.y;
	int d2 = b.x * b.x + b.y * b.y;

	if (d1 == d2) {
		return a.name < b.name;
	}

	return d1 < d2;
}

int main() {

	int n; cin >> n;

	vector<Car> v;

	for (int i = 0; i < n; i++) {
		string name; int x, y;
		cin >> name >> x >> y;
		Car c(name, x, y);
		v.push_back(c);

	}

	sort(v.begin(), v.end(), compare);

	for (auto x : v) {
		x.print();
	}

}