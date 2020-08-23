// max frequency

#include<iostream>
#include<string>
using namespace std;

int main(){
	int freq[26]={0};
	string s;
	cin>>s;
	
	int n = s.length();
	
	for(int i=0; s[i]!='\0'; i++){
		freq[s[i]-97]++;
	}
	
	char x=0; int max = freq[0];
	for(int i=1; i<26; i++){
		if(max<freq[i]){
			max = freq[i];
			x=i;
		}
	}
	
	x+=97;
	
	cout<<x;
	
}

