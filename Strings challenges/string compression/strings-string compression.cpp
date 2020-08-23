// strings-string compression

#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int n=s.length();
	
	int i=0, j=0;
	int count=0;
	
	while(i!=n){
		if(s[i]==s[j]){
			count++;
			j++;
		}
		else{
			if(count==1){
				cout<<s[i];
			}
			else{
				cout<<s[i]<<count;
			}
			i=j;
			count=0;
		}
	}
	
}

