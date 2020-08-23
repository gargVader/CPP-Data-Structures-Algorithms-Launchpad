// sub-arrays 2 using pigeon hole concept

#include<stdio.h>
#include<stdlib.h>
#define ll long
ll a[100005];

int main(){
	int t; scanf("%d", &t); // Number of test cases
	
		
	for(int i=0; i<t; i++){
		ll pre[100005]={0};
		int n; scanf("%d", &n); // size of array
		
		pre[0] = 1;
		int sum=0;
		
		for(int j=0; j<n; j++){ // taking array input
			scanf("%d", &a[j]);
			sum += a[j];
			sum %= n;
			sum = (sum + n)%n;
			pre[sum]++;
		}
		
		ll ans = 0;
		
		for(int j=0; j<n; j++){
				ll m= pre[j];
				ans += m*(m- 1)/2;
			
		}
		
		printf("%lld\n", ans);
	
	}
}

