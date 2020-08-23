// max subarray sum
// Optimize using cumulative freq
#include<climits>
#include<iostream>
#define ll long long
using namespace std;

int main(){
	int n=9;
	int arr[1000]={0};
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int max = INT_MIN, left, right;
	
//	for(int i=0; i<n; i++){
//		int cum[1000]={0};
//		cum[0] = arr[i];
//		for(int j=1; j<n-i; j++){
//			cum[j] = cum[j-1]+arr[i+j];
//			cout<<cum[j]<<" ";
//			if(cum[j]>max){
//				max = cum[j];
//			}
//		}
//		cout<<endl;
//	}

	for(int i=0; i<n; i++){
		int csum[1000]={0};
		csum[i] = arr[i];
		for(int j=i+1; j<n; j++){
			csum[j] = csum[j-1]+arr[j];
			if(csum[j]>max){
				max = csum[j];
				left=i;
				right=j;
			}
		}
	}
	
	cout<<max<<endl;
	for(int i=left; i<=right; i++){
		cout<<arr[i]<<" ";
	}
}

