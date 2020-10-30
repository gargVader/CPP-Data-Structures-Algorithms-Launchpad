#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int *sum=new int[n];
    sum[0]=arr[1];
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+arr[i];
    int unfair=0;
    for(int i=1;i<k;i++)
        unfair+=(i*arr[i])-sum[i-1];

    int target=unfair;
    int start=0;
    int end=k-1;
    start++;
    end++;
    while(end<n)
    {
    		target=target+(end-start)*arr[end] -2*sum[end-1]-(end-start)*arr[start-1];
        unfair=min(unfair,target);
        start++;
        end++;
    }
 cout<< unfair;
}
