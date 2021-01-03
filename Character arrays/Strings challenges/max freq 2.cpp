// max frequency 2

#include<iostream>
#include<string>
using namespace std;

int main(){
	int freq[256]={0};
	string s;
	cin>>s;
	
	for(int i=0; s[i]!='\0'; i++){
		freq[s[i]]++;
	}
	
	char x=0; int max = freq[0];
	for(int i=1; i<256; i++){
		if(max<freq[i]){
			max = freq[i];
			x=i;
		}
	}
	
	cout<<x;
	
}

