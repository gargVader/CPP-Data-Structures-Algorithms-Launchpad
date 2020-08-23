// Fast Exponentiation O(Logn)

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastExp(ll b, ll n) {

	ll p = b, ans = 1;
	while (n > 0) {

		if (n & 1) {
			ans *= p;
		}

		p *= p;
		n = n >> 1;
	}

	return ans;

}

int main() {
	int a, b;
	cin >> a >> b;

	cout << fastExp(a, b);
}


/*
base^index

Regular Exponentiation:
Multiply base to 1, index times. O(index)

Binary Exponentiation:
index can be  expressed as the sum of powers of 2.

7^14

16	8	4	2	1
0	1	1	1	0

We will multiply only 7^8, 7^4, 7^2 to our ans. We will keep a variable p, which will square itself upon each iteration.
This will go on till n>0

*/


// Number of bits in a number: logn + 1

