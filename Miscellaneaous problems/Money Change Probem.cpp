#include<iostream>
#include<climits>
#include<algorithm>
#define MAX 100000 //maximum money to be exchanged
using namespace std;

int minChange(int m, int arr[]){
//	cout<<m<<endl;
	if(m<0){
		return 0;
	}
	
	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(coins)/sizeof(coins[0]);

	// Lookup
	if(arr[m]!=-1){
		return arr[m];
	}
	else{
		int ans=0;
		
		for(int i=0; i<n; i++){
			if(m-coins[i]>=0){
			ans=min(ans, minChange(m-coins[i], arr))+1;
			}
		}
		arr[m]=ans;
		return arr[m];
	}
		

	
}

int main(){
	// Indian Money Change Problem
	int money; cin>>money;
	
	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(coins)/sizeof(coins[0]);
	
	int arr[MAX];
	std::fill_n(arr, MAX, -1);
	
	for(int i=0; i<n; i++){
		arr[coins[i]]=1;
	}
	
	int ans = minChange(money, arr);
	cout<<ans;
}

