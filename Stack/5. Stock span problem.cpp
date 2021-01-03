/*
Stock Span Problem
===================
You are given the price of a stock for N consecutive days and are required to find the span
of stock's price on ith day. The span of a stoock's price on a given day i, is the maximum
consecutive days before the (i+1)th day, for which the stock's price is less than equal to that on
the ith day.

Application: Stack data structure

*/

#include<iostream>
#include<stack>
using namespace std;


int main() {

	int n; cin >> n;

	int price[n];
	int span[n];

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	stack<pair<int, int>> s;

	s.push({1, price[0]});

	span[0] = 1;

	for (int i = 1; i < n; i++) {

		int currSpan = 1;

		auto top = s.top();
		int topSpan = top.first;

		while (s.size() && top.second <= price[i]) {

			currSpan += topSpan;

			s.pop();

			if (s.size()) {
				top = s.top();
				topSpan = top.first;
			} else {
				break;
			}
		}

		span[i] = currSpan;
		s.push({currSpan, price[i]});
	}

	for (int i = 0; i < n; i++) {
		cout << span[i] << " ";
	} cout << endl;

}

/*
5
30 35 40 38 35
*/