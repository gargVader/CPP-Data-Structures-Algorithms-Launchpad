// bubble sort
// Edit: Modified to pass fucntion as a fucntion parameter
#include<stdio.h>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

// Bubble Sort
void bubblesort(int arr[], int n, bool (*cmp)(int, int)) {
	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (cmp(arr[i + 1], arr[i])) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

int main() {

	int n; cin >> n;

	int arr[n];

	// Create a reverse sorted array
	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}

	// Bubble Sort
	time_t start = clock();
	bubblesort(arr, n, compare);
	time_t end = clock();
	cout << "Bubble Sort: " << end - start << endl;

	// Create a reverse sorted array
	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}

	//inbuilt sort function
	start = clock();
	sort(arr, arr + n);
	end = clock();
	cout << "In built sort/Merge Sort: " << end - start << endl;


}

