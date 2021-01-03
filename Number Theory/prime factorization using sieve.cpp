#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<math.h>
#include<vector>
#define ll long long
#define MAX 1000
using namespace std;

// Returns vector of all primes 1 to MAX
vector<int> primeSieve(int p[]) {

	p[2] = 1;

	// All odd numbers may be prime
	for (int i = 3; i < MAX; i += 2) {
		p[i] = 1;
	}

	vector<int> primes; primes.push_back(2);

	for (int i = 3; i < MAX; i += 2) {

		//if number is prime
		if (p[i]) {
			// mark all its multiples as not prime
			for (int j = i * i; j < MAX; j += i) {
				p[j] = 0;
			}
		}
	}

	for (int i = 3; i < MAX; i += 2) {
		if (p[i]) {
			primes.push_back(i);
		}
	}

	return primes;
}

vector<int> factorization(int n, vector<int> primes) {
	vector<int> factors;

	int i = 0;
	while (primes[i]*primes[i] <= n) {
		if (n % primes[i] == 0) {
			factors.push_back(primes[i]);
			while (n % primes[i] == 0) {
				n = n / primes[i];
			}
		}
		i++;
	}

	if (n != 1) {
		factors.push_back(n);
	}

	return factors;
}

int main() {
	int p[MAX] = {0};
	int q; cout << "Enter number of queries: "; cin >> q;
	vector<int> primes = primeSieve(p);

	while (q--) {

		int n; cout << "Enter number: "; cin >> n;

		vector<int> factors = factorization(n, primes);

		for (int i = 0; i < factors.size(); i++) {
			cout << factors[i] << " ";
		} cout << endl;


	}


}


