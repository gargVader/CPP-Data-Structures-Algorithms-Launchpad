#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char ch[100];
	cin>>ch;
	int n=strlen(ch);
	int i;
	for(i=0; i<n-1; i++){
		cout<<ch[i];
		cout<<ch[i+1]-ch[i];
	}
	cout<<ch[i];
}
