// First and last occurence of key in an array

#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){
	
	int s=0, e=n-1, ans=-1,mid;
	
	while(s<=e){
		mid = (s+e)/2;
		cout<<"s="<<s<<" e="<<e<<" mid="<<mid<<endl;		
		if(arr[mid]==key){
			ans=mid;
			// shifting to left for first occurence
			e=mid-1; 
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
	
}

int lastOccurence(int arr[], int n, int key){
	
	int s=0, e=n-1, ans=-1,mid;
	
	while(s<=e){
		mid = (s+e)/2;
		cout<<"s="<<s<<" e="<<e<<" mid="<<mid<<endl;		
		if(arr[mid]==key){
			ans=mid;
			// shifting to right for last occurence
			s=mid+1; 
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
	
}

int main(){
	int arr[]={1,2,5,8,8,8,8,8,10,12,15,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=8;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int first = firstOccurence(arr, n, key);
	cout<<"First Occurence "<<first<<endl<<endl;
	
	int last = lastOccurence(arr, n, key);
	cout<<"Last Occurence "<<last<<endl; 
	
}

