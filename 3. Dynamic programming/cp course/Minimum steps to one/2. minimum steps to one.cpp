// Minimum steps to one
// n ==> 1 by using the following methods:
// n=> n/3 iff n%3==0
// n=> n/2 iff n%2==0
// n=> n-1

#include<iostream>
#include<algorithm>
#define MAX 200
using namespace std;

int minStepsToOne(int n, int a[]){
//	int a[MAX]; This is wrong as new array is being defined at each fucntion call. So no efficiency is achieved. Only recursion is occuring
	for (int i = 0; i < MAX ; i++){ 
        a[i] = -1; 
    }
	
	//Base case
	a[1] = 0;
	
	if(a[n]==-1){
		if(n%3==0 and n%2==0){
			int temp = min(minStepsToOne(n/3,a), minStepsToOne(n/2,a));	
			a[n] = min(temp,minStepsToOne(n-1,a)) + 1;
		}
		if(n%3==0 and n%2!=0){
			a[n] = min(minStepsToOne(n/3,a), minStepsToOne(n-1,a)) + 1;
		}
		if(n%3!=0 and n%2==0){
			a[n] = min(minStepsToOne(n/2,a), minStepsToOne(n-1,a)) + 1;
		}
		if(n%3!=0 and n%2!=0){
			a[n] = minStepsToOne(n-1,a) + 1;
		}	
	}
	
	return a[n];
}

int BottomUp(int n){
	int a[MAX];
	
	//Base case
	a[1] = 0;
	
	for(int i=2; i<=n; i++){
		if(i%3==0 and i%2==0){
			int temp = min(BottomUp(i/3), BottomUp(i/2));	
			a[i] = min(temp,BottomUp(i-1)) + 1;
		}
		if(i%3==0 and i%2!=0){
			a[i] = min(BottomUp(i/3), BottomUp(i-1)) + 1;
		}
		if(i%3!=0 and i%2==0){
			a[i] = min(BottomUp(i/2), BottomUp(i-1)) + 1;
		}
		if(i%3!=0 and i%2!=0){
			a[i] = BottomUp(i-1) + 1;
		} 
	}
	
	return a[n];
	
}

int main(){
	int a[MAX];
	int n;
	cout<<"Enter number: ";
	cin>>n;
	
	int ans = minStepsToOne(n, a);
	cout<<"Top Down Approach: "<<ans<<endl;
	
	ans = BottomUp(n);
	cout<<"Bottom Up Approach: "<<ans;
	
}

