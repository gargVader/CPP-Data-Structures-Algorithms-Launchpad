#include<stdio.h>

int main(){
	int n, arr[100000], num, flag=0, ans;
	scanf("%d", &n); // number of elements
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &num);
	
	for(int i=0; i<n; i++){
		if(arr[i]==num){
			flag = 1;
			ans = i;
			break;
		}
	}
	
	if(flag==0)
		printf("-1");
	else
		printf("%d", ans);
}

