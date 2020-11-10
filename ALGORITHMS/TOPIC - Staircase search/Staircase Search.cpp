#include<iostream>
#define ll long long
using namespace std;

int main(){
	int arr[][4]={
	{1,4,8,10},
	{2,5,9,15},
	{6,16,18,20},
	{11,17,19,23},
	};
	
	int key = 17;
	int n=4, m=4;
	int i=0, j=m-1;
	
	while(arr[i][j]!=key){
		if(arr[i][j]<key){// that means array value must increase, for that we have to go down
			i++;
		}
		if(arr[i][j]>key){
			j--;
		}
	}
	cout<<i<<" "<<j;
}

