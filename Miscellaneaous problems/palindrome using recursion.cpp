// check if palindrome using recursion

#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

bool isPalindrome(string arr, int s, int e){
	// Base case
	if(s>=e){ // this means that the control has managed to reach the middle of the 
//	array without being stopped by if(arr[s]!=arr[e]){return false;} which unlike the 
//	else step returns a definite value. (else step doesnot return definite value but makes a 
//	recursive call to the function)
		return true;
	}
	
	// recursion
	if(arr[s]!=arr[e]){
		return false;
	}
	else{
		return isPalindrome(arr, ++s, --e);
	}
	
}

int main(){
	string arr; cin>>arr;
//	getline(cin, arr);
	
	int n = arr.length();
	cout<<n<<endl;
	
	if(isPalindrome(arr, 0, n-1)){
		cout<<"Yes palindrome";
	}
	else{
		cout<<"Not palindrome";
	}
}

