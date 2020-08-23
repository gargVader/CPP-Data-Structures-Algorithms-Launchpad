// since the array is sorted and rotated, we have two sets of sorted array: Sorted array 1, Sorted array 2

#include<stdio.h>

int find(int a[], int n, int key){
	int s=0, e=n-1;
	
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>a[s]){ // => a[mid] is in sorted_array1

			if(key>=a[s] and key<=a[mid]){
				/// search between s and mid-1
				e=mid-1;
			}
			else{
				// search between mid+1 and e 
				s=mid+1;
			}
		}
	//	else{...} could have also been used instead of this ->	
		else if(a[mid]<a[e]){ // => a[mid] is in sorted_array2
			
			if(key>=a[mid] and key<=a[e]){
				// search between mid+1 and e
				s=mid+1;
			}
			else{
				// search between s and mid-1
				e=mid-1;
			}
		}
	}
	return -1;
}


int main(){
	int n, a[100000], key;
	scanf("%d", &n); // number of elements
	
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	scanf("%d", &key);
	
	int ans = find(a, n, key);
	printf("%d", ans);
	
}

