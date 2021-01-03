#include<iostream>
using namespace std;

int main(){
	
	// Initialising later
	pair<int, int>p;
	p.first = 1;
	p.second = 2;
	
	cout<<p.first<<" "<<p.second<<endl;
	
	// Initialising on the go
	pair<int, int>p2(p);
	cout<<p2.first<<" "<<p2.second<<endl;
	
	pair<int, string>p3 = make_pair(3,"Audi");
	cout<<p3.first<<" "<<p3.second<<endl;
	
	// Array of pairs
	// Vector of pairs
	// Pair of Pairs
	
	pair<int, pair<string, int> >st;
	
	st.first = 1;
	st.second.first = "English";
	st.second.second = 50;
	
	cout<<st.second.second;
	
	
}

