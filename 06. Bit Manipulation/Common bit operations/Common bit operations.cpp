//Common bit operations
#include<bits/stdc++.h>
using namespace std;

//Gets last bit
bool isOdd(int n){
	return n&1; 
}

// Gets ith bit from right
int getBit(int n, int i){
	return n&(1<<i);
}

// Set ith bit from right to 1
void setBit(int &n, int i){
	n = n|(1<<i);
}

// Set ith bit from right to 0
void clearBit(int &n, int i){
	n = n&(~(1<<i));
}

// Update ith bit to v
void updateBit(int &n, int i, int v){
	// first clear ith bit
	n=n&(~(1<<i));
	// then set ith bit to v
	n = n|(v<<i);
}

// Clears last i bits
void clearLastIBits(int &n, int i){
	
//	int mask=0;
//	// set last i digits to 1
//	for(int j=0; j<i; j++){
//		mask = mask|(1<<j);
//	}
//	// reverse mask
//	mask = ~mask;
//	n = n&mask;

	int mask=-1; // 11111111111....111111
	mask =mask<<i;
	n=n&mask;
}

void clearRangeIToJ(int &n, int i, int j){

// Method:1
//	int mask = -1;
//	mask = mask<<j;
//	mask = ~mask;
//	mask = mask<<i;
//	mask = ~mask;
//	
//	n = n&mask;	

// Method: 2
//	int a = -1; a=a<<j;
//	int b = -1; b=b<<i; b=~b;
//	int mask = a|b; 
//	n = n&mask;

// Method:3
//	int a = -1; a=a<<(j+1);
//	int b = (1<<i) - 1; 
//	int mask = a|b; 
//	n = n&mask;
}


int main(){
	int n=31;
	clearRangeIToJ(n, 1, 3);
	cout<<n<<endl;
}


