#include<iostream>
#include<stack>
using namespace std;


int main() {
	int price[] = {100, 80, 60, 70, 60, 75, 85};
	//int n = sizeof(price) / sizeof(price[0]);
	int n; cin >> n;
	int span[n] = {0};
	stack<pair<int, int>> s;

	s.push(make_pair(0, price[0]));
	span[0] = 1;

	for (int i = 1; i < n; i++) {
		pair<int, int> p = s.top();
		if (price[i] < p.second) {
			s.push(make_pair(i, price[i]));
			span[i] = 1;
		} else {
			while (!s.empty() && s.top().second < price[i]) {
				s.pop();
			}
			if (!s.empty()) {
				span[i] = i - s.top().first;
			} else {
				span[i] = i;
			}
			s.push(make_pair(i, price[i]));
		}
	}

	for (int i = 0; i < n; i++) {
		cout << span[i] << " ";
	} cout << endl;

}