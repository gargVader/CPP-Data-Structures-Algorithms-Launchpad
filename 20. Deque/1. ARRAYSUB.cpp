#include <iostream>
#include <deque>
using namespace std;

int main() {

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int k; cin >> k;
	deque<int> q(k);

	for (int i = 0; i < k; i++) {
		while (!q.empty() && a[i] > a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << a[q.front()] << " ";

	for (int i = k; i < n; i++) {
		while (!q.empty() && a[i] > a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
		while (!q.empty() && q.front() <= i - k) {
			q.pop_front();
		}

		cout << a[q.front()] << " ";
	} cout << endl;



}
