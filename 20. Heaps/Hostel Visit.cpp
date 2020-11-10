#include <iostream>
#include<queue>
#include<math.h>
using namespace std;

int main() {

	// Max Heap
	priority_queue<int> pq;

	int q, k; cin >> q >> k;

	while (q--) {
		int t; cin >> t;

		if (t == 2) {
			cout << pq.top() << endl;
		} else {
			int x, y; cin >> x >> y;
			int num = (x * x + y * y);

			if (pq.size() < k) {
				pq.push(num);
				continue;
			} else if (num < pq.top()) {
				pq.pop();
				pq.push(num);
			}

		}

	}

}
