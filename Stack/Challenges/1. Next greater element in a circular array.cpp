#include <iostream>
#include <vector>
#include<stack>
using namespace std;


/*
// Editorial:

vector<int> nextGreaterElementsOptimised(vector<int> &nums)
{
	int n = nums.size();
	vector<int> res(n);

	stack<int> s;

	for (int i = 2 * n - 1; i >= 0; i--)
	{

		while (!s.empty() && nums[s.top()] <= nums[i % n])
		{
			s.pop();
		}

		res[i % n] = (s.empty() ? -1 : nums[s.top()]);
		s.push(i % n);
	}

	return res;
}

*/

vector<int> nextGreaterElementsOptimised(vector<int> v) {
	int n = v.size();
	vector<int> res(n);

	stack<int> s;
	s.push(0);

	for (int i = 1; i < 2 * n; i++) {

		while (!s.empty() && v[s.top()] < v[i % n]) {
			int ind = s.top();
			res[ind] = v[i % n];
			//cout << ind << " " << v[i % n] << endl;
			s.pop();
		}

		if (s.empty()) {
			res[i % n] = -1;
		}

		// if (!s.empty() && s.top() == i % n) {
		// 	//cout << s.top() << endl;
		// 	res[s.top()] = -1;
		// 	break;
		// }

		s.push(i % n);

	}
	return res;
}

vector<int> nextGreaterElements(vector<int> v) {

	int n = v.size();
	vector<int> res(n);

	for (int i = 0; i < n; i++) {

		bool f = 0;
		for (int j = i + 1; j < i + n; j++) {
			if (v[i] < v[j % n]) {
				res[i] = v[j % n];
				f = 1;
				break;
			}
		}
		if (f == 0) {
			res[i] = -1;
		}

	}

	return res;
}

int main() {
	int n; cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> res = nextGreaterElementsOptimised(v);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	} cout << endl;
}