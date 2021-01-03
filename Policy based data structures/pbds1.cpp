#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main() {

	PBDS st;
	st.insert({1, 0});
	st.insert({3, 1});
	st.insert({44, 2});
	st.insert({44, 3});
	st.insert({10, 4});
	st.insert({15, 5});

	for (int i = 0; i < st.size(); i++) {
		cout << (*st.find_by_order(i)).first << " ";
	} cout << endl;

	// cout << st.order_of_key(10) << endl;
	// cout << st.order_of_key(5) << endl;

}
