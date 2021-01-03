// Search in a row and col wise sorted matrix

#include<iostream>
using namespace std;

int main(){
	int arr[][4]={
		{10,20,30,40},
		{15,25,35,45},
		{27,29,37,48}
	};
	int row=3, col=4;
	int key=29;
	int i=0, j=col-1;
	
	int flag=0;
	while(i<=row-1 && col>=0){
		
		if(arr[i][j]==key){
			flag=1;
			break;
		}
		if(arr[i][j]>key){
			j--;
		}
		if(arr[i][j]<key){
			i++;
		}	
	}
	
	if(flag==1){
		cout<<"Found at "<<i<<","<<j;
	}
	else{
		cout<<"-1";
	}
	
	
}

