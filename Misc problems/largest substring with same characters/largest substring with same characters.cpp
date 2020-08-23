// Largest substring with same Characters

#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int i=0, j=0, n=s.length(), count=0, max=0;
	char max_c;
	
	while(i<n){
		if(s[i]==s[j]){
			count++;
			if(max<count){
				max=count;
				max_c=s[i];
			}
			j++;
		}
		else{
			i=j;
			count=0;
		}
	}
	
	cout<<max_c<<" "<<max;
	
	
}

