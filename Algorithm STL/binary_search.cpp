// algorithm STL
// binary_search(), lower_bound(), upper_bound()

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[] = {15, 25, 26, 27, 33, 48, 50, 50, 50, 52, 54, 58, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 50;

	// Search in a sorted array

	// binary_search(s,e,key): return true if key present, false otherwise
	bool isPresent = binary_search(arr, arr + n, key);
	if (isPresent) {
		cout << "present" << endl;
	}
	else {
		cout << "absent" << endl;
	}

	// Get index of the element
	// lower_bound(s,e,key): returns address of element greater than or equal to key

	// returns address of first occurence of key.
	// If element is absent, returns address of the next higher number
	auto it = lower_bound(arr, arr + n, key);
	cout << "Lower bound: " << *it;
	int index = it - arr; cout << " at index->" << index << endl;

	// upper_bound(s,e,key): returns address of element strictly greater than key
	//returns address of the next higher number from the first occurence of key
	// If element is absent, returns address of the next higher number

	it = upper_bound(arr, arr + n, key);
	cout << "Upper bound: " << *it;
	index = it - arr; cout << " at index->" << index << endl;

	// Frequency = up - lb
	auto ub = upper_bound(arr, arr + n, key);
	auto lb = lower_bound(arr, arr + n, key);

	cout << "Frequency of key is " << ub - lb;

}

