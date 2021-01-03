#include<bits/stdc++.h>
using namespace std;

void filter(int n, string str){
	
	int j=0;
	while(n>0){
		int last_bit = n&1;
		if(last_bit){
			cout<<str[j];
		}
		j++;
		n=n>>1;
	}
	cout<<endl;
	
}

int main(){
	string str; cin>>str;
	
	int num = 1<<str.length();
	
	for(int i=0; i<num; i++){
		filter(i, str);
	}
//	filter(26, str);
}


