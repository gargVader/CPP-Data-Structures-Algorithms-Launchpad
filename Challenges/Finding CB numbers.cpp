#include<iostream>
#include<algorithm>
using namespace std;
//Check for CB number
bool check(long long b) {
	if (d == 0 || d == 1)
		return false;
	else {
		for (i = 0; i < 10; ++i) {
			if (d == s[i])
				return true;
			else if (d % s[i] == 0)
				return false;
		}
	}
	return true;
}

bool isvisited(int *v, int i, int j) {
	for (; i <= j; i++)
		if (v[i] == 1)
			//Already visited
			return true;
	//If all goes well, then not visited, we can count for this CB number
	return false;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count = 0;
	//Array to keep track of visisted indeces
	int v[n] = {0};
	//Outter loop for size of the subaaray/substring
	for (int i = 0; i < n; i++)
		//To create subarrays
		for (int j = 0; j < n - i; j++)
		{
			long long num = 0;
			//Start from j
			int temp = j;
			//Go upto j+i
			while (temp <= j + i)
			{
				num = num * 10 + (s[temp] - '0');
				temp++;
			}
			//If a CB number
			if (check(num) == 1)
			{
				//Now, check if indexes are not already used is any other CB number detected before.
				if (!isvisited(v, j, j + i)) {
					//If you want to see the CB numbers detected, uncomment the following statement
					// cout<<num<<endl;
					count++;
					//Mark the detected indexes as visited
					for (int k = j; k <= j + i; k++)
						v[k] = 1;
				}
			}

		}
	cout << count;
	return 0;
}