#include<iostream>
#include <stack>
using namespace std;

void largestAreaUnderHistogram(int height[], int n) {

	stack<int> s;
	int ans = 0;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {

		if (s.empty()) {
			s.push(i);
			continue;
		}

		if (height[i] > height[s.top()]) {
			s.push(i);
		} else {
			// I have encountered a height that is less than my last height

			while (!s.empty() && height[i] < height[s.top()]) {
				int toBeRemoved = s.top();
				s.pop();
				int area;
				if (s.empty()) {
					area = height[toBeRemoved] * i;
				} else {
					area = height[toBeRemoved] * (i - s.top() - 1);
				}
				cout << toBeRemoved << " " << area << endl;
				if (area > ans) {
					ans = area;
					l = (!s.empty()) ? s.top() : 0;
					r = i;
				}
				ans = max(ans, area);

			}
			s.push(i);
		}
	}

	cout << "largest area = " << ans << " between bars " << l << " and " << r << endl;
}

int main() {
	int height[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(height) / sizeof(height[0]);
	largestAreaUnderHistogram(height, n);

}