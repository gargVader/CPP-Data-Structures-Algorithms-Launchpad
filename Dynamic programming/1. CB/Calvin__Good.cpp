#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define ff first
#define ss second
#define vi vector<ll>
#define INF 0x3f3f3f3f3f
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)


const int mod = 1e9 + 7;

int main() {
	fast;

	//input
	ll n, k; cin >> n >> k;
	vi A(n + 5); int dpforward[n + 5]; int dpbackward[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	//basecase
	dpforward[k] = 0;
	dpforward[k - 1] = 0;
	dpbackward[1] = A[1];
	dpbackward[2] = A[1] + A[2];
	//recursion
	for (int j = k + 1; j <= n; j++) {
		dpforward[j] = max(dpforward[j - 2], dpforward[j - 1]) + A[j];
	}
	for (int j = 3; j <= n; j++) {

		dpbackward[j] = A[j] + max(dpbackward[j - 2], dpbackward[j - 1]);

	}
	//output
	ll ans = dpbackward[k] + dpforward[k] - A[k];
	for (int j = k; j <= n; j++) {
		mmax(ans, dpforward[j] + dpbackward[j] - A[j]);
	}

	cout << ans << endl;




}