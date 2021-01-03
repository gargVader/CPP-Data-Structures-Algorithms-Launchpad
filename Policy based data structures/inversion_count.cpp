#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main() {

	int a[] = {1, 5, 2, 3, 6, 4, 10};
	int n = sizeof(a) / sizeof(a[0]);

	PBDS st;

	int count = 0;

	for (int i = 0; i < n; i++) {
		// Find the count of number is pbds that are greater than a[i]
		int lessThan = st.order_of_key(a[i]);
		count += st.size() - lessThan;

		// Insert a[i]
		st.insert(a[i]);
	}

	cout << count << endl;

}
