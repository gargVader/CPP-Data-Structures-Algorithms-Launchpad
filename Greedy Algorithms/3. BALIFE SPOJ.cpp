#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 100005
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void solve(ll n) {

	ll arr[MAX];
	ll arr2[MAX];
	ll sum = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum == 0) {
		cout << "0" << endl;
		return;
	}
	if (sum % n) {
		cout << "-1" << endl;
		return;
	}

	// Prefix sum of arr
	for (ll i = 2; i <= n; i++) {
		arr[i] += arr[i - 1];
	}

	// Prefix sum of final arr
	ll temp = sum / n;

	for (ll i = 1; i <= n; i++) {
		arr2[i] = temp * i;
	}

	ll ans = INT_MIN;

	for (int i = 1; i <= n; i++) {
		ans = max(ans, abs(arr[i] - arr2[i]));
	}

	cout << ans << endl;





}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;

	while (n != -1) {

		solve(n);




		cin >> n;
	}
}
