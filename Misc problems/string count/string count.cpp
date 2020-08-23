#include<iostream>
#define ll long long
using namespace std;

int main(){
	
	int digit=0, alphabet=0, other=0, space=0;
	
	char c;
	
	
	do{
		c = cin.get();
		if(c>='0' && c<='9') digit++;
		else if((c>='a' && c<='z') || (c>='A' && c<='Z')) alphabet++;
		else if(c==' ' or c=='\n' or c=='\t') space++;
		else other++;
	}while(c!='$');
	
	cout<<"digit="<<digit<<endl;
	cout<<"space="<<space<<endl;
	cout<<"alphabet="<<alphabet<<endl;
	cout<<"other="<<other<<endl;
	
	
}

