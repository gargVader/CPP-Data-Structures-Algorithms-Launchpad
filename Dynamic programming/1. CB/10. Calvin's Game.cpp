#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} cout << endl;
}

signed main() {

	int n, k;
	cin >> n >> k;
	k--;
	int a[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int dpb[n + 1], dpf[n + 1];
	memset(dpf, 0, sizeof(dpf));
	memset(dpb, 0, sizeof(dpb));

	// dpf
	// points gained for going k to i
	for (int i = k + 1; i < n; i++) {
		// I want to reach i
		int op1 = INT_MIN, op2 = INT_MIN;

		op1 = dpf[i - 1] + a[i];
		if (i >= 2) op2 = dpf[i - 2] + a[i];
		dpf[i] = max(op1, op2);
	}

	// dpb
	// points gained for going i to 0
	for (int i = 1; i < n; i++) {
		int op1 = INT_MIN, op2 = INT_MIN;
		op1 = dpb[i - 1] + a[i - 1];
		if (i >= 2) op2 = dpb[i - 2] + a[i - 2];

		dpb[i] = max(op1, op2);
	}
	dpb[0] = a[0];

	// dpb[0] = a[0];

	// print(dpf, n);
	// print(dpb, n);


	int mx = INT_MIN;

	for (int i = k + 1; i < n; i++) {
		mx = max(mx, dpb[i] + dpf[i]);
	}

	mx = max(mx, dpf[k] + dpb[k]);

	// for (int i = 0; i < n; i++) {
	// 	mx = max(mx, dpb[i] + dpf[i]);
	// }


	if (k == 0) {
		cout << max(mx, 0LL) << endl;
	} else {
		cout << mx << endl;
	}
}