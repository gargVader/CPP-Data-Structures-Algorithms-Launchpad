// Money splitwise algorithm

#include <bits/stdc++.h>
using namespace std;

template<class T, class U, class V>
class triplet {

public:
	T first;
	U second;
	V third;

	triplet(T first, U second, V third): first(first), second(second), third(third) {

	}

};

int main() {

	int numfriends, numTransactions;
	cin >> numfriends >> numTransactions;


	map<string, int> net;

	while (numTransactions--) {
		// x has to give y Rs. amount
		string x, y;
		int amount;
		cin >> x >> y >> amount;
		net[x] -= amount;
		net[y] += amount;
	}

	multiset<pair<int, string>> m;

	vector <triplet<string, string, int>> v;


	// Init a list and sort it => Multiset
	for (auto x : net) {
		if (x.second != 0) {
			m.insert({x.second, x.first});
			cout << x.second << " " << x.first << endl;
		}
	}



	// Person with the highest debt will give money to
	// the person with the highest credit

	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		auto debit = *low;
		auto credit = *high;

		m.erase(low);
		m.erase(high);

		int mn = min(credit.first, abs(debit.first));
		cout << mn << endl;
		debit.first += mn;
		credit.first -= mn;
		// One of them will be zero
		if (debit.first != 0) {
			m.insert(debit);
		}
		if (credit.first != 0) {
			m.insert(credit);
		}
		v.push_back({debit.second, credit.second, mn});
	}


	for (auto x : v) {
		cout << x.first << " pay " << x.third << " to " << x.second << endl;
	}


}

/*
3 3
Rahul Ajay 100
Ajay Neha 50
Neha Rahul 40
*/


